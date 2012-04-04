#include "PlayerInput.h"
#include "SoundHelper.h"


PlayerInput::PlayerInput(HumanPlayer* player, bool *keyStates, bool *funcKeyStates)
{
	this->player = player;
	this->keyStates = keyStates;
	this->funcKeyStates = funcKeyStates;
	lr = NULL;
}

void PlayerInput::keyOperations(int keyModifier)
{	
	if (keyStates[45]) //-
	{
		player->getCurrentCamera()->zoom(false);
	}
	else if (keyStates[61]) //=
	{
		player->getCurrentCamera()->zoom(true);
	}
	else if (keyStates[48]) //0
	{
		player->getCurrentCamera()->resetZoom();
	}
	else if (keyStates[32]){ //space
		player->levitateUFO();
	}
        else if (keyStates[49]) //1
	{
		player->changeCamera(CAMERA_LIGHT1);               

	}
        else if (keyStates[50]) //2
	{
		player->changeCamera(CAMERA_LIGHT2);
	}
        else if (keyStates[51]) //3
	{
		player->changeCamera(CAMERA_LIGHT3);
	}
        else if (keyStates[52]) //4
	{
		player->changeCamera(CAMERA_LIGHT4);
	}

	if (keyStates[108]) //l
	{
		player->getCurrentCamera()->toggleLight();
	}
	if (keyStates[116]) //t
	{
		TextureManager::getInstance()->toggleTextures();
		BoundingBox::showBoxes = !BoundingBox::showBoxes;
	}

	if (keyStates[91]) // [
	{
		if (player->getCurrentCameraType() == CAMERA_FREELOOK)
			((FreeLookCamera*)player->getCurrentCamera())->incrementRoll(false);
	}
	else if (keyStates[93]) // ]
	{
		if (player->getCurrentCameraType() == CAMERA_FREELOOK)
			((FreeLookCamera*)player->getCurrentCamera())->incrementRoll(true);
	}
	else if (keyStates[47]) // '/'
	{
		if (player->getCurrentCameraType() == CAMERA_FREELOOK)
			((FreeLookCamera*)player->getCurrentCamera())->resetPitchAndRoll();
	}
	
	if (keyStates[100]) //d
	{
		if (player->getCurrentCameraType() == CAMERA_ROBOT)
		{
			//assume a robot is there for now
			player->robotStrafe(true,0);
		}
		else
			player->moveUFOX(true);
	}
	else if(keyStates[97])//a
	{ 
		if (player->getCurrentCameraType() == CAMERA_ROBOT)
		{
			//assume a robot is there for now
			player->robotStrafe(false,0);
		}
		else
			player->moveUFOX(false);
	}

	if (keyStates[115]) //s
	{
		if (player->getCurrentCameraType() == CAMERA_ROBOT)
		{
			//assume a robot is there for now
			player->robotForward(false,0);
		}
		else
			player->moveUFOZ(true);
	}
	else if(keyStates[119]){//w

		if (player->getCurrentCameraType() == CAMERA_ROBOT)
		{
			//assume a robot is there for now
			player->robotForward(true,0);
		}
		else
			player->moveUFOZ(false);
	}
	else if (keyStates[114]) //r
	{
		player->ufoSetDestination(0);
	}
	else if (keyStates[102]) //f
	{
		player->lockRobotAndUfo();
	}
	else if (keyStates[105]) //i
	{
		player->cycleThroughComponents(0);
	}
	else if (keyStates[117]) //u
	{
		player->toggleComponentOn(0);
	}
	else if (keyStates[106]) //j
	{
		player->toggleComponentOff(0);
	}
}

void PlayerInput::functionKeyOperations(int keyModifier)
{
	if (funcKeyStates[GLUT_KEY_F2])
	{
		player->changeCamera(CAMERA_FREELOOK);
	}
	else if (funcKeyStates[GLUT_KEY_F3])
	{
		player->changeCamera(CAMERA_COMMANDER);	
	}
	else if (funcKeyStates[GLUT_KEY_F4])
	{
		player->changeCamera(CAMERA_CIRCULAR);
	}
	else if (funcKeyStates[GLUT_KEY_F5])
	{
		player->changeCamera(CAMERA_FOLLOW);
		player->robots.at(0)->isRobotBeingControlled = false;
	}
	else if (funcKeyStates[GLUT_KEY_F10])
	{
		if(lr != NULL){
			lr->toggleTeamNumber();
		}
	}

	if (funcKeyStates[GLUT_KEY_LEFT])
	{
		player->getCurrentCamera()->moveCameraStrafe(true);
	}
	else if (funcKeyStates[GLUT_KEY_RIGHT])
	{
		player->getCurrentCamera()->moveCameraStrafe(false);
	}

	if (funcKeyStates[GLUT_KEY_UP])
	{
		player->getCurrentCamera()->moveCameraForwards(false);
	}
	else if (funcKeyStates[GLUT_KEY_DOWN])
	{
		player->getCurrentCamera()->moveCameraForwards(true);
	}

	if (funcKeyStates[GLUT_KEY_PAGE_UP])
	{
		player->getCurrentCamera()->modifyYaw(true, 0, 0); 
	}
	else if (funcKeyStates[GLUT_KEY_PAGE_DOWN])
	{
		player->getCurrentCamera()->modifyYaw(false, 0, 0);
		
	}
	else if (funcKeyStates[GLUT_KEY_END])
	{
		player->getCurrentCamera()->resetCameraAngle();
	}
}

void PlayerInput::mousePassiveOperations(int x, int y)
{
	if (player->getCurrentCameraType() == CAMERA_FREELOOK)
	{
		player->getCurrentCamera()->modifyYaw(false, x, y);
	}

	if (player->getCurrentCameraType() == CAMERA_ROBOT)
		player->robots.at(0)->incrementSpinDegrees(x, y);

}

void PlayerInput::mouseButtons(int button, int state)
{
	//0 is left button, 2 is right button, 1 is middle mouse
	//0 is pressed, 1 is released for STATES
	if (button == 0 && state == 0) {
		if (player->robots.at(0)->isAlive)
		{
			player->robots.at(0)->shootBullet();
			SoundHelper::getInstance()->play("shoot.wav", 1, false);
		}
		else
			player->respawn();
    }
}

void PlayerInput::attachLevelRenderer(LevelRenderer* lr){
	this->lr = lr;
}