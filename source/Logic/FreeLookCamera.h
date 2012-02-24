//Jonathan's class

#ifndef FREELOOK_CAMERA_H
#define FREELOOK_CAMERA_H

#include "Camera.h"

static const GLfloat MAX_PITCH = 180.0f;
static const GLfloat MIN_PITCH = -MAX_PITCH;
static const GLfloat DEFAULT_MOUSE_SENSITIVITY = 0.25f;
static const GLfloat DEFAULT_MOVEMENT_SENSITIVITY = 0.035f;

class FreeLookCamera : public Camera
{
public:
	FreeLookCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane);

	void view();
	//Movement related methods
	void moveCameraForwards(bool negateTheValue);
	void moveCameraStrafe(bool negateTheValue);
	void modifyYaw(bool negateTheValue, int x, int y);
	void zoom(bool zoomIn){ return; }
	void resetZoom(){ return; }
	void toggleLight() { return; }

	//specific to freelook (roll rotation)
	void roll(bool negateTheValue);

private:
	GLfloat mouseSensitivity;
	GLfloat movementSensitivity;
	GLfloat rotationVector[3];
	GLfloat upVector[3];
};

#endif