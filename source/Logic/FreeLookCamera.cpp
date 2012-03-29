//Jonathan's class

#include "FreeLookCamera.h"


FreeLookCamera::FreeLookCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	
	//camera rotation
	yaw = 0.0f;
	pitch = 0.0f;
	roll = 0.0f;

	//camera location
	locX = 25.0f;
	locY = 10.0f;
	locZ = 25.0f;

	fovy = DEFAULT_FOVY;

	mouseSensitivity = DEFAULT_MOUSE_SENSITIVITY;
	movementSensitivity = DEFAULT_MOVEMENT_SENSITIVITY;

	for (int i = 0; i < 3; i++)
		directionVector[i] = 0.0;

	upVector[0] = 0.0f;
	upVector[1] = 1.0f;
	upVector[2] = 0.0f;
}

void FreeLookCamera::view()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewWidth / viewHeight, viewNearPlane, viewFarPlane);

	gluLookAt(locX, locY, locZ,
		locX + directionVector[0], locY + directionVector[1], locZ + directionVector[2],  
		upVector[0], upVector[1], upVector[2]);
}

void FreeLookCamera::moveCameraForwards(bool negateTheValue)
{
	GLfloat multiplier = 1.0f;

	if (negateTheValue)
		multiplier *= -1.0f;

	locX += (GLfloat)directionVector[0] * multiplier * movementSensitivity;
	locY += (GLfloat)directionVector[1] * multiplier * movementSensitivity;
	locZ += (GLfloat)directionVector[2] * multiplier * movementSensitivity;
}

void FreeLookCamera::moveCameraStrafe(bool negateTheValue)
{
	GLfloat multiplier = 1.0;

	if (negateTheValue)
		multiplier *= -1.0;

	locX -= (GLfloat)directionVector[2] * multiplier * movementSensitivity;
	locZ += (GLfloat)directionVector[0] * multiplier * movementSensitivity;
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

		directionVector[0] = cos(yaw);
		directionVector[1] = -sin(pitch);
		directionVector[2] = sin(yaw);
	}
}

void FreeLookCamera::incrementRoll(bool negateTheValue)
{
	if (negateTheValue)
		roll -= 0.4f;
	else
		roll += 0.4f;


	//http://www.gamedev.net/topic/546975-calculating-the-up-vector/
	upVector[0] = cos(yaw) * sin(pitch) * sin(roll) - sin(yaw) * cos(roll);
	upVector[1] = sin(yaw) * sin(pitch) * sin(roll) + cos(yaw) * cos(roll);
	upVector[2] = /*cos(pitch) */ sin(roll);
}

void FreeLookCamera::resetPitchAndRoll()
{
	pitch = 0.0f;
	roll = 0.0f;

	directionVector[0] = cos(yaw);
	directionVector[1] = pitch;
	directionVector[2] = sin(yaw);

	upVector[0] = 0.0f;
	upVector[1] = 1.0f;
	upVector[2] = 0.0f;

	
}