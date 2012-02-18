#ifndef CAMERA_H
#define CAMERA_H

#define GL_PI 3.14159f // PI
#define RadiansToDegrees 180.0f/GL_PI
#define DegreesToRadians GL_PI/180.0f

#define CAMERA_COMMANDER 0
#define CAMERA_FREELOOK  1

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "math.h"

//static const GLfloat BIRD_SIGHT_RADIUS = 45.0f;

static const GLfloat DEFAULT_FOVY = 60.0f;

class Camera
{
public:
	Camera(){}
	virtual ~Camera(){}
	virtual void view() = 0;

	//Abstract methods
	virtual void moveCameraForwards(bool negateTheValue) = 0; //negate to move backwards
	virtual void moveCameraStrafe(bool negateTheValue) = 0; //negate to strafe left
	virtual void modifyYaw(bool negateTheValue, int x, int y) = 0; //negate to go counter-clockwise
	virtual void zoom(bool zoomIn) = 0;
	virtual void resetZoom() = 0;

	void toggleWireframeView();
	void resetCameraAngle(); //reset the camera angle to 0
	
	
protected:
	//perspective variables
	GLint viewWidth, viewHeight;
	GLfloat viewNearPlane, viewFarPlane;
	int centerX, centerY;

	bool wireframeView;

	GLfloat fovy; //Zooming variable
	GLfloat locX, locY, locZ; //camera location
	GLfloat yaw, pitch, roll; //camera rotation
	
	void initialize(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane);
};

#endif