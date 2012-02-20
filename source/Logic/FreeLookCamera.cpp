//Jonathan's class

#include "FreeLookCamera.h"


FreeLookCamera::FreeLookCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	
	//camera rotation
	yaw = 0.0f;
	pitch = 0.0f;

	//camera location
	locX = 25.0f;
	locY = 10.0f;
	locZ = 25.0f;

	fovy = DEFAULT_FOVY;

	mouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;
	movementSensitivity = DEFAULT_MOVEMENT_SENSITIVITY;

	for (int i = 0; i < 3; i++)
		rotationVector[i] = 0.0f;
}

void FreeLookCamera::view()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewWidth / viewHeight, viewNearPlane, viewFarPlane);

	gluLookAt(locX, locY, locZ,
		locX + rotationVector[0], locY - rotationVector[1], locZ + rotationVector[2],  
		0.0f, 1.0f, 0.0f);
}

void FreeLookCamera::moveCameraForwards(bool negateTheValue)
{
	GLfloat multiplier = 1.0f;

	if (negateTheValue)
		multiplier *= -1.0f;

	locX += rotationVector[0] * multiplier * movementSensitivity;
	locY -= rotationVector[1] * multiplier * movementSensitivity;
	locZ += rotationVector[2] * multiplier * movementSensitivity;
	
	
}

void FreeLookCamera::moveCameraStrafe(bool negateTheValue)
{
	GLfloat multiplier = 1.0f;

	if (negateTheValue)
		multiplier *= -1.0f;

	locX -= rotationVector[2] * multiplier * movementSensitivity;
	locZ += rotationVector[0] * multiplier * movementSensitivity;
	
	glutPostRedisplay();
}

void FreeLookCamera::modifyYaw(bool negateTheValue, int x, int y)
{
	int diffX, diffY;

	diffX = x - centerX;
	diffY = y - centerY;

	if (diffX != 0 || diffY != 0)
	{
		glutWarpPointer(centerX, centerY);

		yaw += diffX * mouseSensitivity;
		pitch += diffY * mouseSensitivity;

		if (pitch > MAX_PITCH)
			pitch = MAX_PITCH;
		else if (pitch < MIN_PITCH)
			pitch = MIN_PITCH;

		rotationVector[0] = sin(yaw * DegreesToRadians) * RadiansToDegrees;
		rotationVector[1] = pitch;//sin(pitch * DegreesToRadians) * RadiansToDegrees;
		rotationVector[2] = -cos(yaw * DegreesToRadians) * RadiansToDegrees;
	}
}