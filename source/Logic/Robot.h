//ROBERT'S CLASS


#ifndef ROBOT_H
#define ROBOT_H
#define GL_PI 3.14159f //PI
#define RadiansToDegrees 180.0f/GL_PI
#define DegreesToRadians GL_PI/180.0f

#include "Model.h"
#include "Static/TeamNumberModel.h"
#include "RobotCamera.h"

static const GLfloat ELECTRONICS_HEIGHT = 0.63f;
static const GLfloat NUCLEAR_HEIGHT = 0.355f;
static const GLfloat PHASER_HEIGHT = 0.9f;
static const GLfloat CANNON_HEIGHT = 0.4f;
static const GLfloat BIPOD_HEIGHT = 1.0f;
static const GLfloat MISSILE_LAUNCHER_HEIGHT = 0.3f;
static const GLfloat ANTIGRAV_HEIGHT = 0.7f;
static const GLfloat TRACKS_HEIGHT = 0.42f;
static const GLfloat light8_ambient[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
static const GLfloat light8_diffuse[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
static const GLfloat light8_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
class RobotCamera;

class Robot {
public:
	Robot();
	~Robot();
	void draw();

	//Used for component toggling
	void cycleIndex();
	void turnSelectedOn();

	//interface robot transformations
	void translate(GLfloat x, GLfloat z);
	void translateTo(GLfloat x, GLfloat z);
	void spin(GLfloat degrees);
	void incrementSpinDegrees(bool pos);

	//Coordinate accessors
	GLfloat getEyeX();
	GLfloat getEyeY();
	GLfloat getEyeZ();
	GLfloat* getLookAt();
	GLfloat* getLightLookAt();
	GLfloat calculateHeight(int index); //because height varies depending on components

	//Camera attachment and synchronization
	void attachToCamera(RobotCamera* rc);
	void notifyCamera();

	//orientation related
	void incrementPitchAngle(bool pos);
	void incrementYawAngle(bool pos);
	void resetOrientation();	

	//light related
	static bool isARobotLightOn;
	void toggleLight();
	void refreshLight();

private:
	//-----------------------PRIVATE ATTRIBUTES---------------------------
	//models
	Model* model;
    Model* nuclearM;
    Model* electronicsM;
    Model* phaserM;
    Model* cannonM;
    Model* missileM;
    Model* bipodM;
    Model* tracksM;
    Model* antiGravM;
	Model* headlight;
	TeamNumberModel teamNumberModel;

	//Camera
	RobotCamera* roboCam;
    
	//State Variables: coordinates and orientation
	GLfloat xPos;
	GLfloat zPos;
	GLfloat lookAtX;
	GLfloat lookAtY;
	GLfloat lookAtZ;
	GLfloat spinDegrees;
	GLfloat pitchAngle;
	GLfloat yawAngle;
	
	//Lighting
	bool isMyLightOn;

	//Used for component toggling
	bool isPartOn[8];
	int selectedIndex;
	void refreshRobot(); //refreshes model to contain correct robot components
	void clearChildren(); //initialization for refreshRobot()
	void turnIndexOn(int index); //helper function for toggling components (updates isPartOn[])

public:


};

#endif