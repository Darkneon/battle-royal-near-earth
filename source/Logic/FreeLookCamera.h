//Jonathan's class

#ifndef FREELOOK_CAMERA_H
#define FREELOOK_CAMERA_H

#include "Camera.h"
static const GLfloat MAX_PITCH = GL_PI / 2;
static const GLfloat MIN_PITCH = -MAX_PITCH;
static const GLfloat DEFAULT_MOUSE_SENSITIVITY = 0.0025f;
static const GLfloat DEFAULT_MOVEMENT_SENSITIVITY = 0.35f;

class FreeLookCamera : public Camera
{
public:
	FreeLookCamera(GLint viewWidth, GLint viewHeight, GLdouble viewNearPlane, GLdouble viewFarPlane);

	void view();
	//Movement related methods
	void moveCameraForwards(bool negateTheValue);
	void moveCameraStrafe(bool negateTheValue);
	void modifyYaw(bool negateTheValue, int x, int y);
	void zoom(bool zoomIn){ return; }
	void resetZoom(){ return; }
	void toggleLight() { return; }

	//specific to freelook (roll rotation)
	void incrementRoll(bool negateTheValue);
	void resetPitchAndRoll();

private:
	GLfloat mouseSensitivity;
	GLfloat movementSensitivity;
	GLdouble directionVector[3];
	GLdouble upVector[3];
};

#endif