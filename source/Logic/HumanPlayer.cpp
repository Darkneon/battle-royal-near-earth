#include "HumanPlayer.h"
#include "Player/PlayerModel.h"
#define GL_TEXTURE_CUBE_MAP 0x8513

HumanPlayer::HumanPlayer(GLfloat centerOfMapX, GLfloat CenterOfMapZ, GLfloat spawnX, GLfloat spawnZ, bool hasUFO, GLfloat rows, GLfloat columns)
					: Player(spawnX,spawnZ){
    
	availableCams[CAMERA_COMMANDER] = new CommanderCamera();
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera();
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(centerOfMapX, CenterOfMapZ);
	availableCams[CAMERA_ROBOT] = new RobotCamera();
        availableCams[CAMERA_LIGHT1] = new LightCamera(1.0f, 6.0f, 1.0f, 2.5f, -2.5f, 2.5f);
        availableCams[CAMERA_LIGHT2] = new LightCamera(columns-1, 6.0f, 1.0f, -2.5f, -2.5f, 2.5f);
        availableCams[CAMERA_LIGHT3] = new LightCamera(columns-1, 6.0f, rows-1, -2.5f, -2.5f, -2.5f);
        availableCams[CAMERA_LIGHT4] = new LightCamera(1.0f, 6.0f, rows-1, 2.5f, -2.5f, -2.5f);
	availableCams[CAMERA_FOLLOW] = new FollowCamera();
        currentCamera = CAMERA_FOLLOW;
	if(hasUFO){
		//ufo = new PlayerUFO(spawnPtX,spawnPtZ+5.0f);
		ufo = new PlayerUFO(spawnPtX,spawnPtZ);
	}
	else{
		ufo = NULL;
	}
	aRobotIsSelected = false;
	robotUfoLock = false;
	currentComponent = 0;
    
    hasEnvMap = false;
}

HumanPlayer::~HumanPlayer() {    
	if (ufo != NULL) {
		delete ufo;
		ufo = NULL;
	}

	for (int i = 0; i < 2; i++)
	{
		if (availableCams[i] != NULL)
		{
			delete availableCams[i];
			availableCams[i] = NULL;
		}
	}
}

void HumanPlayer::render(){
	if(ufo != NULL){
        if (hasEnvMap) {
			GLfloat mv[16], invMV[16];
            glEnable(GL_TEXTURE_CUBE_MAP);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_GEN_R);

			glGetFloatv(GL_MODELVIEW_MATRIX, mv);
			invMV[0]  = mv[0]; invMV[1]  = mv[4]; invMV[2]  = mv[8];  invMV[3]  = 0;
            invMV[4]  = mv[1]; invMV[5]  = mv[5]; invMV[6]  = mv[9];  invMV[7]  = 0;
            invMV[8]  = mv[2]; invMV[9]  = mv[6]; invMV[10] = mv[10]; invMV[11] = 0;
            invMV[12] = 0;    invMV[13] = 0;     invMV[14] = 0;      invMV[15] = 1;

			glMatrixMode(GL_TEXTURE);
			glPushMatrix();
			glLoadMatrixf(invMV);
            glMatrixMode(GL_MODELVIEW);
        }
        
		ufo->draw();
	
        if (hasEnvMap) {
            glDisable(GL_TEXTURE_CUBE_MAP);
            glDisable(GL_TEXTURE_GEN_S);
            glDisable(GL_TEXTURE_GEN_T);
            glDisable(GL_TEXTURE_GEN_R);
            glMatrixMode(GL_MODELVIEW);
			glPopMatrix();
        }
    }

        //robots.at(0)->applyShadow(rows, columns);
	//keep drawing until all the children are done
	glPushMatrix();
	for(int j = 0; j < (int)robots.size(); j++){
		robots.at(j)->draw();
                robots.at(j)->applyShadow(rows, columns);
	}
	//glMatrixMode(GL_TEXTURE);
	glPopMatrix();
}

void HumanPlayer::controlRobotAt(int index)
{
	selectRobotView(robots.at(0));
	changeCamera(CAMERA_ROBOT);

	selectRobot(index);
	aRobotIsSelected = true;
	robots.at(0)->isRobotBeingControlled = true;
}

void HumanPlayer::changeCamera(int CAMERA)
{
	if(CAMERA == CAMERA_ROBOT){
		if(!((RobotCamera*)availableCams[CAMERA_ROBOT])->getHasRobot()){
			return;
		}
	}
	currentCamera = CAMERA;
}

void HumanPlayer::view()
{
	availableCams[currentCamera]->view();
    
    if (currentCamera == CAMERA_FOLLOW) {
        ((FollowCamera *)availableCams[currentCamera])->setLookAt(ufo->pos[0], ufo->pos[1], ufo->pos[2]);
    }
}

Camera* HumanPlayer::getCurrentCamera()
{
	return availableCams[currentCamera];
}

int HumanPlayer::getCurrentCameraType()
{
	return currentCamera;
}

void HumanPlayer::selectRobotView(Robot* robo){
	((RobotCamera*)availableCams[CAMERA_ROBOT])->attachToRobot(robo);
}

void HumanPlayer::levitateUFO(){
	if(!robotUfoLock){
		ufo->incrementHeight(true);
	}
}

void HumanPlayer::moveUFOX(bool direction){
	if(!robotUfoLock){
		ufo->incrementXPos(direction);
	}
}

void HumanPlayer::moveUFOZ(bool direction){
	if(!robotUfoLock){
		ufo->incrementZPos(direction);
	}
}
void HumanPlayer::setUFOPosition(GLfloat setX, GLfloat setY, GLfloat setZ){
	ufo->setPosition(setX,setY,setZ);
}
void HumanPlayer::setUFOPosition(V3 v){
	ufo->setPosition(v.x,v.y,v.z);
}

void HumanPlayer::lockRobotAndUfo(){
	V3 ufoPos = ufo->getPosition();
	if(!robotUfoLock && ufo->ufoCollisionTest(ufoPos.x,ufoPos.y-0.1f,ufoPos.z) > 0){
		controlRobotAt(0);
		//searched for robot being collided with and finds index in vector
		for(int i = 0; i < (int)robots.size(); i++){
			if(robots.at(i)->getRobotId() == ufo->ufoCollisionTest(ufoPos.x,ufoPos.y-0.05f,ufoPos.z)){
				//input vector index to control that robot
				controlRobotAt(i);
			}
		}
		robotUfoLock = true;
	}
	else{
		changeCamera(CAMERA_FOLLOW);
		robots.at(0)->isRobotBeingControlled = false;
		robotUfoLock = false;
	}
}

void HumanPlayer::robotStrafe(bool negate, int vectorIndex){
	robots.at(vectorIndex)->moveStrafe(negate);
	if(robotUfoLock){
		V3 positionUFO = robots.at(vectorIndex)->getUFOLockPosition();
		setUFOPosition(positionUFO);
	}
}

void HumanPlayer::robotForward(bool negate, int vectorIndex){
	robots.at(vectorIndex)->moveForward(negate);
	if(robotUfoLock){
		V3 positionUFO = robots.at(vectorIndex)->getUFOLockPosition();
		setUFOPosition(positionUFO);
	}
}

void HumanPlayer::ufoSetDestination(int vectorIndex){
	if(vectorIndex < (int)robots.size()){
		V3 ufoPosition = ufo->getPosition();
		robots.at(vectorIndex)->setDestination(ufoPosition.x,ufoPosition.z);
	}
}

void HumanPlayer::cycleThroughComponents(int vectorIndex){
	robots.at(vectorIndex)->cycleIndex();
}

void HumanPlayer::toggleComponentOn(int vectorIndex){
	robots.at(vectorIndex)->turnSelectedOn();
}

void HumanPlayer::toggleComponentOff(int vectorIndex){
	robots.at(vectorIndex)->turnSelectedOff();
}
