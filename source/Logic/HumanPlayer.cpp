#include "HumanPlayer.h"
#include "Player/PlayerModel.h"


HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane){
    PlayerModel *pm = new PlayerModel;
    model = (Model*)pm;
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    /*availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);*/
	currentCamera = CAMERA_COMMANDER;
	ufoXPos = spawnPtX;
	ufoZPos = spawnPtZ+5.0f;
}

HumanPlayer::HumanPlayer(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane, GLfloat spawnX, GLfloat spawnZ)
					: Player(spawnX,spawnZ){
    PlayerModel *pm = new PlayerModel;
    model = (Model*)pm;
	availableCams[CAMERA_COMMANDER] = new CommanderCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_FREELOOK] = new FreeLookCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_CIRCULAR] = new CirclingCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	availableCams[CAMERA_ROBOT] = new RobotCamera(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    /*availableCams[CAMERA_LIGHT1] = new LightCamera(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT2] = new LightCamera(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT3] = new LightCamera(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    availableCams[CAMERA_LIGHT4] = new LightCamera(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f ,viewWidth, viewHeight, viewNearPlane, viewFarPlane);*/
	currentCamera = CAMERA_COMMANDER;
	ufoXPos = spawnPtX;
	ufoZPos = spawnPtZ+5.0f;
}

HumanPlayer::~HumanPlayer() {    
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

void HumanPlayer::draw() {
	glPushMatrix();
		glTranslatef(ufoXPos,0.0f,ufoZPos);
		model->draw();
	glPopMatrix();
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
