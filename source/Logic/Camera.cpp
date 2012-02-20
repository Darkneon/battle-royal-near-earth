#include "Camera.h"

void Camera::initialize(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	wireframeView = false;
	
	//initialzing the perspective 
	this->viewWidth = viewWidth;
	this->viewHeight = viewHeight;
	this->viewNearPlane = viewNearPlane;
	this->viewFarPlane = viewFarPlane;

	centerX = (int)viewWidth / 2;
	centerY = (int)viewHeight / 2;
}

void Camera::toggleWireframeView()
{
	wireframeView = !wireframeView;

	if (wireframeView)
	{
		glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_BACK, GL_LINE);
		glPolygonMode(GL_FRONT, GL_LINE);
	}
	else
	{
		glEnable(GL_DEPTH_TEST);
		glPolygonMode(GL_BACK, GL_FILL);
		glPolygonMode(GL_FRONT, GL_FILL);
	}
}

void Camera::resetCameraAngle()
{
	yaw = 0;
}

