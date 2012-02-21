/*
//Jonathan's class

#ifndef CIRCLING_CAMERA_H
#define CIRCLING_CAMERA_H

#include "Camera.h"

static const GLfloat DEFAULT_RADIUS = 25.0f;
static const GLfloat DEFAULT_HEIGHT =  10.0f;

class CirclingCamera : public Camera
{
public:
	CirclingCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane);

	//interface methods
	void view();
	void moveCameraForwards(bool negateTheValue);
	void moveCameraStrafe(bool negateTheValue);
	void modifyYaw(bool negateTheValue, int x, int y);
	void zoom(bool zoomIn) { return; }
	void resetZoom() { return; }

private:
	GLfloat currentRadius; //radius from lookat point
	GLfloat currentHeight;
	void calculate45DegreesForLocY(); //45 degrees for cams (useful for more than one class)
};

#endif*/