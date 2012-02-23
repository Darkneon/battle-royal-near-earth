#include "CommanderCamera.h"

CommanderCamera::CommanderCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	//camera rotation
	yaw = 0.0f;
	pitch = 0.0f;

	//camera location
	currentRadius = DEFAULT_RADIUS;
	locX = 25.0f;
	locY = 0.0f;
	locZ = 25.0f + currentRadius;

	heightDenom = DEFAULT_HEIGHT_DENOM;
	fovy = DEFAULT_FOVY;
	calculate45DegreesForLocY();
}

void CommanderCamera::view()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewWidth / viewHeight, viewNearPlane, viewFarPlane);

	gluLookAt(locX + currentRadius * sin(yaw * 1.0f / 8), locY, locZ - currentRadius + currentRadius * cos(yaw * 1.0f / 8),
		locX, 0, locZ - currentRadius, 0, 1, 0);
}


void CommanderCamera::moveCameraForwards(bool negateTheValue)
{
	GLfloat moveVector[] = {sin(yaw * 1.0f / 8), cos(yaw * 1.0f / 8)};

	if (negateTheValue)
	{
		moveVector[0] *= -1.0f;
		moveVector[1] *= -1.0f;
	}

	locX -= moveVector[0];
	locZ -= moveVector[1];
}

void CommanderCamera::moveCameraStrafe(bool negateTheValue)
{
	GLfloat moveVector[] = {sin(yaw / 8.0f), cos(yaw / 8.0f)};

	if (negateTheValue)
	{
		moveVector[0] *= -1.0f;
		moveVector[1] *= -1.0f;
	}

	locX += moveVector[1];
	locZ -= moveVector[0];
}

void CommanderCamera::zoom(bool zoomIn)
{
	if (fovy > 10 && fovy < DEFAULT_FOVY + 1.0f)
	{
		if (zoomIn)
		{
			fovy--;
			heightDenom += 0.25f;
		}
		else
		{
			fovy++;
			heightDenom -= 0.25f;
		}

		locY = currentRadius * tan(GL_PI / heightDenom);
	}
}

void CommanderCamera::resetZoom()
{
	fovy = DEFAULT_FOVY;
	calculate45DegreesForLocY();
	heightDenom = DEFAULT_HEIGHT_DENOM;
}

void CommanderCamera::calculate45DegreesForLocY()
{
	locY = currentRadius * tan(GL_PI / 4);
}

void CommanderCamera::modifyYaw(bool negateTheValue, int x, int y)
{
	if (!negateTheValue)
		yaw++;
	else
		yaw--;
}