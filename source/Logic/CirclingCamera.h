//Jonathan's class

#ifndef CIRCLING_CAMERA_H
#define CIRCLING_CAMERA_H

#include "Camera.h"

//static const GLfloat DEFAULT_CIRCLING_RADIUS = 20.0f;
//static const GLfloat CENTER_OF_MAP = 25.0f;

class CirclingCamera : public Camera
{
public:
	CirclingCamera(GLfloat centerOfMapX, GLfloat centerOfMapZ);

	//interface methods
	void view();
	void moveCameraForwards(bool negateTheValue) { return; }
	void moveCameraStrafe(bool negateTheValue);
	void modifyYaw(bool negateTheValue, int x, int y) { return; }
	void zoom(bool zoomIn) { return; }
	void resetZoom() { return; }
	void toggleLight();

	void changeAngleDMCam();

private:
	bool hasLight;
	GLfloat currentRadius; //radius from lookat point
	GLfloat centerOfTheMapX;
	GLfloat centerOfTheMapZ;
	void calculate45DegreesForLocY(); //45 degrees for cams (useful for more than one class)
};

#endif