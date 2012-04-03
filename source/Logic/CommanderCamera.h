//Jonathan's class

#ifndef COMMANDER_CAMERA_H
#define COMMANDER_CAMERA_H

#include "Camera.h"

static const GLfloat DEFAULT_RADIUS = 10.0f;
static const GLfloat DEFAULT_HEIGHT_DENOM =  4.0f;

class CommanderCamera : public Camera
{
public:
	CommanderCamera();

	//interface methods
	void view();
	void moveCameraForwards(bool negateTheValue);
	void moveCameraStrafe(bool negateTheValue);
	void modifyYaw(bool negateTheValue, int x, int y);
	void zoom(bool zoomIn);
	void resetZoom();
	void toggleLight() { return; }
        void updateFog();

private:
	GLfloat currentRadius; //radius from lookat point
	GLfloat heightDenom; //used for zoom effect
	void calculate45DegreesForLocY(); //45 degrees for cams (useful for more than one class)
};

#endif