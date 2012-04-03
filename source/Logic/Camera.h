#ifndef CAMERA_H
#define CAMERA_H

#define GL_PI 3.14159f // PI
#define RadiansToDegrees 180.0f/GL_PI
#define DegreesToRadians GL_PI/180.0f

#define CAMERA_COMMANDER 0
#define CAMERA_FREELOOK  1
#define CAMERA_CIRCULAR	 2
#define CAMERA_ROBOT 3
#define CAMERA_LIGHT1 4
#define CAMERA_LIGHT2 5
#define CAMERA_LIGHT3 6
#define CAMERA_LIGHT4 7
#define CAMERA_FOLLOW 8

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "math.h"
#include "AntTweakHelper.h"

//static const GLfloat BIRD_SIGHT_RADIUS = 45.0f;

static const GLfloat DEFAULT_FOVY = 60.0f;

class Camera
{
public:
  friend class AntTweakHelper;

	Camera(){}
	virtual ~Camera(){}
	virtual void view() = 0;

	//Abstract methods
	virtual void moveCameraForwards(bool negateTheValue) = 0; //negate to move backwards
	virtual void moveCameraStrafe(bool negateTheValue) = 0; //negate to strafe left
	virtual void modifyYaw(bool negateTheValue, int x, int y) = 0; //negate to go counter-clockwise
	virtual void zoom(bool zoomIn) = 0;
	virtual void resetZoom() = 0;
	virtual void toggleLight() = 0;

	void toggleDifferentView();
	virtual void resetCameraAngle(); //reset the camera angle to 0
	
protected:
	//perspective variables
	GLint viewWidth, viewHeight;
	GLdouble viewNearPlane, viewFarPlane;
	int centerX, centerY;

	int viewStates;

	GLfloat fovy; //Zooming variable
	GLfloat locX, locY, locZ; //camera location
	GLdouble yaw, pitch, roll; //camera rotation
	
	bool isLightOn;

	void initialize(GLint viewWidth, GLint viewHeight, GLdouble viewNearPlane, GLdouble viewFarPlane);
};

#endif
