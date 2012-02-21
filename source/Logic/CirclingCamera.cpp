#include "CirclingCamera.h"

CirclingCamera::CirclingCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	//camera rotation
	yaw = 0.0f;

	//camera location
	currentRadius = DEFAULT_CIRCLING_RADIUS;
	locX = 25.0f;
	locZ = 25.0f + currentRadius;

	fovy = DEFAULT_FOVY;
	calculate45DegreesForLocY();
}

void CirclingCamera::view()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewWidth / viewHeight, viewNearPlane, viewFarPlane);

	GLfloat lookAtX = CENTER_OF_MAP + currentRadius * sin(yaw * 0.0625);
	GLfloat lookAtZ = CENTER_OF_MAP + currentRadius * cos(yaw * 0.0625);

	gluLookAt((currentRadius * sin(yaw * 0.0625)) + lookAtX, locY, (currentRadius * cos(yaw * 0.0625)) + lookAtZ,
		lookAtX, 0, lookAtZ, 0, 1, 0);
}

void CirclingCamera::moveCameraStrafe(bool negateTheValue)
{
	if (negateTheValue)
		yaw--;
	else
		yaw++;
}

void CirclingCamera::calculate45DegreesForLocY()
{
	locY = currentRadius * tan(GL_PI / 4);
}