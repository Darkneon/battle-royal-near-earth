#include "HumanPlayer.h"
#include "Player/PlayerModel.h"


HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane){
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_FOLLOW] = new FollowCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    
    currentCamera = CAMERA_COMMANDER;
	ufo = new PlayerUFO(spawnPtX,spawnPtZ+5.0f);
	aRobotIsSelected = false;
	robotUfoLock = false;
}

HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane, GLfloat spawnX, GLfloat spawnZ)
					: Player(spawnX,spawnZ){
    
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FOLLOW] = new FollowCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);

    currentCamera = CAMERA_COMMANDER;
	ufo = new PlayerUFO(spawnPtX,spawnPtZ+5.0f);
	aRobotIsSelected = false;
	robotUfoLock = false;
}

HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane, GLfloat spawnX, GLfloat spawnZ, bool hasUFO)
					: Player(spawnX,spawnZ){
    
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FOLLOW] = new FollowCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);

    currentCamera = CAMERA_COMMANDER;
	if(hasUFO){
		ufo = new PlayerUFO(spawnPtX,spawnPtZ+5.0f);
	}
	else{
		ufo = NULL;
	}
	aRobotIsSelected = false;
	robotUfoLock = false;
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
		ufo->draw();
	}

	//keep drawing until all the children are done
    for(int j = 0; j < (int)robots.size(); j++){
		robots.at(j)->draw();
	}
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
	if(!robotUfoLock && ufo->ufoCollisionTest(ufoPos.x,ufoPos.y-0.05f,ufoPos.z) > 0){
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
		changeCamera(CAMERA_COMMANDER);
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
