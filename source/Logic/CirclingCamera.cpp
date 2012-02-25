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
	isLightOn = false;
}

void CirclingCamera::view()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewWidth / viewHeight, viewNearPlane, viewFarPlane);

	GLfloat lookAtX = CENTER_OF_MAP + currentRadius * sin(yaw * 0.0625);
	GLfloat lookAtZ = CENTER_OF_MAP + currentRadius * cos(yaw * 0.0625);

	GLfloat fromX = (currentRadius * sin(yaw * 0.0625)) + lookAtX;
	GLfloat fromZ = (currentRadius * cos(yaw * 0.0625)) + lookAtZ;

	gluLookAt(fromX, locY, fromZ,
		lookAtX, 0.0, lookAtZ, 0.0, 1.0, 0.0);

	if (isLightOn)
	{
		GLfloat light6_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };
		GLfloat light6_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
		GLfloat light6_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat light6_position[] = { fromX, locY, fromZ, 1.0f };
		GLfloat light6_direction[] = { -sin(yaw  * 0.0625), -1.0f, -cos(yaw * 0.0625) };
		
		glLightfv(GL_LIGHT6, GL_AMBIENT, light6_ambient);
		glLightfv(GL_LIGHT6, GL_DIFFUSE, light6_diffuse);
		glLightfv(GL_LIGHT6, GL_SPECULAR, light6_specular);
		glLightfv(GL_LIGHT6, GL_POSITION, light6_position);
		glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, light6_direction);
		glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 5.0f);
        glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 10.0f); 
		
		glEnable(GL_LIGHT6);
	}
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

void CirclingCamera::toggleLight()
{
	isLightOn = !isLightOn;

	if (!isLightOn)
		glDisable(GL_LIGHT6);
}