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
    /*    else if (keyStates[49]) //1
	{
		player->changeCamera(CAMERA_LIGHT1);
                glutPostRedisplay();
	}
        else if (keyStates[50]) //2
	{
		player->changeCamera(CAMERA_LIGHT2);
                glutPostRedisplay();
	}
        else if (keyStates[51]) //3
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
		glutPostRedisplay();
	}
	if (keyStates[111]) //o
	{
		TextureManager::getInstance()->toggleTextures();
		//glutPostRedisplay();
	}

	if (keyStates[91]) // [
	{
		if (player->getCurrentCameraType() == CAMERA_FREELOOK)
			((FreeLookCamera*)player->getCurrentCamera())->incrementRoll(false);
		glutPostRedisplay();
	}
	else if (keyStates[93]) // ]
	{
		if (player->getCurrentCameraType() == CAMERA_FREELOOK)
			((FreeLookCamera*)player->getCurrentCamera())->incrementRoll(true);
		glutPostRedisplay();
	}
	else if (keyStates[47]) // '/'
	{
		if (player->getCurrentCameraType() == CAMERA_FREELOOK)
			((FreeLookCamera*)player->getCurrentCamera())->resetPitchAndRoll();
		glutPostRedisplay();
	}

}

void PlayerInput::functionKeyOperations(int keyModifier)
{

	if (funcKeyStates[GLUT_KEY_F4])
	{
		player->changeCamera(CAMERA_CIRCULAR);
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_F2])
	{
		player->changeCamera(CAMERA_FREELOOK);
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_F3])
	{
		player->changeCamera(CAMERA_COMMANDER);	
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_F5])
	{
		player->changeCamera(CAMERA_ROBOT);	
		glutPostRedisplay();
	}

	if (funcKeyStates[GLUT_KEY_LEFT])
	{
		player->getCurrentCamera()->moveCameraStrafe(true);
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_RIGHT])
	{
		player->getCurrentCamera()->moveCameraStrafe(false);
		glutPostRedisplay();
	}

	if (funcKeyStates[GLUT_KEY_UP])
	{
		player->getCurrentCamera()->moveCameraForwards(false);
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_DOWN])
	{
		player->getCurrentCamera()->moveCameraForwards(true);
		glutPostRedisplay();
	}

	if (funcKeyStates[GLUT_KEY_PAGE_UP])
	{
		player->getCurrentCamera()->modifyYaw(true, 0, 0); 
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_PAGE_DOWN])
	{
		player->getCurrentCamera()->modifyYaw(false, 0, 0);
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_END])
	{
		player->getCurrentCamera()->resetCameraAngle();
		glutPostRedisplay();
	}
}

void PlayerInput::mousePassiveOperations(int x, int y)
{
	if (player->getCurrentCameraType() == CAMERA_FREELOOK)
		player->getCurrentCamera()->modifyYaw(false, x, y);

	glutPostRedisplay();
}
