#include "PlayerInput.h"

PlayerInput::PlayerInput(HumanPlayer* player, bool *keyStates, bool *funcKeyStates)
{
	this->player = player;
	this->keyStates = keyStates;
	this->funcKeyStates = funcKeyStates;
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
    /*    else if (keyStates[49]) //1
	{
		//player->changeCamera(CAMERA_LIGHT1);
               // glutPostRedisplay();
		player->moveUFOX(true);

	}
        else if (keyStates[50]) //2
	{
		//player->changeCamera(CAMERA_LIGHT2);
                //glutPostRedisplay();
		player->moveUFOZ(false);
	}*/
     /*   else if (keyStates[51]) //3
	{
		player->changeCamera(CAMERA_LIGHT3);
                glutPostRedisplay();
	}
        else if (keyStates[52]) //4
	{
		player->changeCamera(CAMERA_LIGHT4);
                glutPostRedisplay();
	}*/

	if (keyStates[108]) //l
	{
		player->getCurrentCamera()->toggleLight();
	}
	if (keyStates[111]) //o
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
		player->moveUFOX(true);
	}
	else if(keyStates[97]){ //a
		player->moveUFOX(false);
	}

	if (keyStates[115]) //s
	{
		player->moveUFOZ(true);
	}
	else if(keyStates[119]){//w
		player->moveUFOZ(false);
	}

	if (keyStates['i'])
	{
		
	}

}

void PlayerInput::functionKeyOperations(int keyModifier)
{

	if (funcKeyStates[GLUT_KEY_F4])
	{
		player->changeCamera(CAMERA_CIRCULAR);
	}
	else if (funcKeyStates[GLUT_KEY_F2])
	{
		player->changeCamera(CAMERA_FREELOOK);
	}
	else if (funcKeyStates[GLUT_KEY_F3])
	{
		player->changeCamera(CAMERA_COMMANDER);	
	}
	else if (funcKeyStates[GLUT_KEY_F5])
	{
		player->changeCamera(CAMERA_ROBOT);	
	}
	else if (funcKeyStates[GLUT_KEY_F7])
	{
		player->changeCamera(CAMERA_FOLLOW);	
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
		player->getCurrentCamera()->modifyYaw(false, x, y);

}
