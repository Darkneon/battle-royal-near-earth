#include "Camera.h"

void Camera::initialize(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	viewStates = 0;
	
	//initialzing the perspective 
	this->viewWidth = viewWidth;
	this->viewHeight = viewHeight;
	this->viewNearPlane = viewNearPlane;
	this->viewFarPlane = viewFarPlane;

	centerX = (int)viewWidth / 2;
	centerY = (int)viewHeight / 2;
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

