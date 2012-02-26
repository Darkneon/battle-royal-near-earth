#include "Player.h"
#include "Player/PlayerModel.h"


Player::Player(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane) {
    PlayerModel *pm = new PlayerModel;
    model = (Model*)pm;
	//r = new Robot;
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
        availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
        availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
        availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
        availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	currentCamera = CAMERA_COMMANDER;
}

Player::~Player() {    
	if (model != NULL) {
		delete model;
		model = NULL;
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

void Player::draw() {
    model->draw();
}

void Player::changeCamera(int CAMERA)
{
	if(CAMERA == CAMERA_ROBOT){
		if(!((RobotCamera*)availableCams[CAMERA_ROBOT])->getHasRobot()){
			return;
		}
	}
	currentCamera = CAMERA;
}


void Player::view()
{
	availableCams[currentCamera]->view();
}

Camera* Player::getCurrentCamera()
{
	return availableCams[currentCamera];
}

int Player::getCurrentCameraType()
{
	return currentCamera;
}

void Player::selectRobot(Robot* robo){
	((RobotCamera*)availableCams[CAMERA_ROBOT])->attachToRobot(robo);
}