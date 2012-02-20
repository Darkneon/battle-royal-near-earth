#include "PlayerInput.h"

PlayerInput::PlayerInput(Player* player, bool *keyStates, bool *funcKeyStates)
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

	if (keyStates[27]) //ESC
		exit(0);
}

void PlayerInput::functionKeyOperations(int keyModifier)
{

	
	if (funcKeyStates[GLUT_KEY_F2])
	{
		player->changeCamera(CAMERA_FREELOOK);
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_F3])
	{
		player->changeCamera(CAMERA_COMMANDER);	
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



/* keep this for now ==========================================================================================
	if (keyStates[122]) //z
	{
		birdSightView = !birdSightView;
		mouseLook = false;
		
		GLfloat zeeDistanze = BIRD_SIGHT_RADIUS - DEFAULT_RADIUS;
		if (birdSightView)
		{
			currentRadius = BIRD_SIGHT_RADIUS;
			locZ += zeeDistanze;
		}
		else
		{
			currentRadius = DEFAULT_RADIUS;
			locZ -= zeeDistanze;
		}
		
		calculate45DegreesForLocY();
	}*/