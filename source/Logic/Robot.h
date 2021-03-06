//ROBERT'S CLASS

#ifndef ROBOT_H
#define ROBOT_H

#define GL_PI 3.14159f //PI
#define RadiansToDegrees 180.0f/GL_PI
#define DegreesToRadians GL_PI/180.0f
static const float MAX_LIFE = 7.0f;

#include "Model.h"
#include "Static/TeamNumberModel.h"
#include "RobotCamera.h"
#include "../Model/Helper/BoundingBox.h"
#include "../Model/Helper/CollisionTester.h"
#include "../Logic/BulletManager.h"
#include <time.h>

static const GLfloat ELECTRONICS_HEIGHT = 0.59f;
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

//DIRECTIONAL CONSTANTS
static const GLfloat NORTH = 270.0f;
static const GLfloat EAST = 180.0f;
static const GLfloat SOUTH = 90.0f;
static const GLfloat WEST = 0.0f;

//MOUSE CONTROL CONSTANTS
static const GLfloat MOUSE_SENSITIVITY = 0.25f;

static const GLfloat ROBOT_STEP_SIZE = 0.2f;
static const GLfloat ROBOT_LOOK_SIZE = 2.0f;

class RobotCamera;

class Robot {
public:
	Robot();
	Robot(GLfloat x, GLfloat y);
	~Robot();

	static int robotIdCount;
	

	void draw();

	//Used for component toggling
	void cycleIndex();
	void turnSelectedOn();
        GLfloat calculateAlpha(GLfloat, GLfloat, GLfloat, GLfloat);
	void turnSelectedOff();

	//Robot Spinning
	void incrementSpinDegrees(bool pos, GLfloat speed = 1);
	void incrementSpinDegrees(int x, int y);

	//move commands
	void moveForward(bool pos);
	void moveStrafe(bool pos);
        void applyShadow(GLfloat, GLfloat);
        int returnClosestLight(GLfloat, GLfloat);
        void shadowMatrix(GLfloat, GLfloat, GLfloat, GLfloat);
	//Coordinate accessors
	GLfloat getEyeX();
	GLfloat getEyeY();
	GLfloat getEyeZ();
	GLfloat* getLookAt();
	GLfloat* getLightLookAt();
	GLfloat calculateHeight(int index); //because height varies depending on components
	GLfloat calculateHeight();
	V3 getUFOLockPosition();
	void setDestination(GLfloat x, GLfloat z);

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

	//For Robert
	GLfloat directionVector[3];
	void spinDirectionVector();

	//Used to know if a player is currently controlling this particular robot
	bool isRobotBeingControlled;

	//Bullet Related
	//damage Robot
	void shootBullet();

	void takeDamage(GLfloat damage);

	int getRobotId();

	//State Variables: coordinates and orientation
	//Position
	GLfloat xPos;
	GLfloat zPos;
	GLfloat height;


	//Life
	GLfloat robotLife;

	bool isAlive;
	bool computerControlled;

	BoundingBox* box;

	bool stop;
	GLfloat explosionSize;
private:
	//-----------------------PRIVATE ATTRIBUTES---------------------------
	int robotId;
	//Models
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
	Model* rubble;
	Model* flag;
	TeamNumberModel teamNumberModel;
        GLfloat groundplane[4];
        GLfloat shadowMat[16];
	//Camera
	RobotCamera* roboCam;
	
	//Collision Detection
	
	bool hasBox;
	CollisionTester* ct;
	BulletManager* bm;
    
	
	//Camera & Light
	GLfloat lookAtX;
	GLfloat lookAtY;
	GLfloat lookAtZ;
	//Orientation
	GLfloat spinDegrees; //0 -> west, 90 -> south
	GLfloat pitchAngle;
	GLfloat yawAngle;
	//Destination
	GLfloat xDestination;
	GLfloat zDestination;
	GLfloat spinDestination;
//	V3 bulletSpawnPhaser;
//	V3 bulletSpawn2;
	//Lighting
	bool isMyLightOn;
	//Used for component toggling
	bool isPartOn[8];
	int selectedIndex;

	//Robot explosion
	double currentTime;
	double lastExplosion;
	

	int aiShootCount;

	//-----------------------PRIVATE METHODS---------------------------
	
	//Used for component toggling
	//isPartOn[8] mutator/toggler
	void turnIndexOn(int index);
	//refreshes model to contain components that are "Turned On"
	void refreshRobot();
	//initialization for refreshRobot()
	void clearChildren(); 
	
	//Robot Spinning
	//calculates counterclockwise angle between current and destination degrees
	GLfloat calcDestinationAngle();
	//ensures degrees are under 360
	void normalizeSpinDegrees();
	void normalizeSpinDestination();
	//called by every render() -> increments/decrements degree until facing destination angle
	void timedSpin();
	
	//Robot Walking -> Helper Functions
	//called by every render() -> increments/decrements xPos until at xDestination
	bool timedXWalk();
	//called by every render() -> increments/decrements xPos until at xDestination
	bool timedZWalk();
	void incrementXPos(bool pos);
	void incrementZPos(bool pos);
	bool checkXPos(bool pos);
	void aiSetDestination();
	bool checkZPos(bool pos);

	//Destination-Related
	//Robots orients and moves X, then orients and moves Z
	void goToDestination();
	
	//spins robot EAST or WEST depending on destination... 
	//returns true if facing correct direction already
	bool checkXDestination();
	//spins robot NORTH or SOUTH depending on destination... 
	//returns true if facing correct direction already
	bool checkZDestination();

	//Collision Detection
	bool robotCollisionTest(GLfloat x, GLfloat y, GLfloat z);

	

};

#endif