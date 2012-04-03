#ifndef ROBOT_CAMERA_H
#define ROBOT_CAMERA_H

#include "Camera.h"
#include "Robot.h"

class Robot;

class RobotCamera : public Camera
{
public:
	RobotCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane);

	void view();
	
	//Orientation Related
	void moveCameraForwards(bool negateTheValue); //camera pitch
	void modifyYaw(bool negateTheValue, int x, int y); //camera yaw
	void moveCameraStrafe(bool negateTheValue); //spins robot
	void resetCameraAngle();
	
	//Light-Related
	void toggleLight();

	void updateFog();

	//Robot-Related - Must attach a robot to a robot camera
	Robot* robot;
	void attachToRobot(Robot* r);
	virtual bool getHasRobot() {return hasRobot;}

	//Synchronizes RobotCamera with Camera
	void synchEyePosition();
	void synchLookAtPosition();
	void update();

	//not used
	void zoom(bool zoomIn) { return; }
	void resetZoom() { return; }

private:
	bool hasRobot;
	GLfloat lookAt[3]; //look-at coordinates

};

#endif