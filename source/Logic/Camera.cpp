#include "Camera.h"

Camera::Camera()
{
	viewStates = 0;
	
	centerX = (int)glutGet(GLUT_WINDOW_WIDTH) / 2;
	centerY = (int)glutGet(GLUT_WINDOW_HEIGHT) / 2;
}

void Camera::toggleDifferentView()
{
	++viewStates;

	//normal settings
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_FRONT, GL_FILL);

	if(viewStates==1){ //wireFrame
		glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_BACK, GL_LINE);
		glPolygonMode(GL_FRONT, GL_LINE);
	}

	else if(viewStates==2){ //smoothShading
		glShadeModel(GL_SMOOTH);
	}

	else{//back to normal
		viewStates=0;
	}
}

void Camera::resetCameraAngle()
{
	yaw = 0;
}