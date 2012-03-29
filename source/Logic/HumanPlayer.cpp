#include "HumanPlayer.h"
#include "Player/PlayerModel.h"


HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane){
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    /*availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);*/
    availableCams[CAMERA_FOLLOW] = new FollowCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    
    currentCamera = CAMERA_COMMANDER;
	ufo = new PlayerUFO(spawnPtX,spawnPtZ+5.0f);
	aRobotIsSelected = false;
}

HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane, GLfloat spawnX, GLfloat spawnZ)
					: Player(spawnX,spawnZ){
    
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    /*availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);*/
	availableCams[CAMERA_FOLLOW] = new FollowCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);

    currentCamera = CAMERA_COMMANDER;
	ufo = new PlayerUFO(spawnPtX,spawnPtZ+5.0f);
	aRobotIsSelected = false;
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
	ufo->draw();

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
	ufo->incrementHeight(true);
}

void HumanPlayer::moveUFOX(bool direction){
	ufo->incrementXPos(direction);
}

void HumanPlayer::moveUFOZ(bool direction){
	ufo->incrementZPos(direction);
}