#include "Player.h"
#include "Player/PlayerModel.h"


Player::Player(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane) {
    PlayerModel *pm = new PlayerModel;
    model = (Model*)pm;

	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);

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