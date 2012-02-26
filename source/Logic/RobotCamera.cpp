#include "RobotCamera.h"


RobotCamera::RobotCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	hasRobot = false;
	//camera location

	locX = 0.0f;
	locY = 0.0f;
	locZ = 0.0f;
	lookAt[0] = 0.0f;
	lookAt[1] = 0.0f;
	lookAt[2] = 0.0f;
	fovy = DEFAULT_FOVY;
	robot = NULL;

}

void RobotCamera::view(){
	if(hasRobot){
		glMatrixMode(GL_PROJECTION); //why?
		glLoadIdentity();
		gluPerspective(fovy,viewWidth/viewHeight, viewNearPlane, viewFarPlane);
		gluLookAt(locX, locY, locZ,lookAt[0], lookAt[1], lookAt[2],0,1,0);
	}
}

//----------------------------------------------------------------
//							ORIENTATION
//----------------------------------------------------------------
void RobotCamera::moveCameraForwards(bool negateTheValue){
	if(robot != NULL){
			robot->incrementPitchAngle(!negateTheValue);
	}
}

void RobotCamera::modifyYaw(bool negateTheValue, int x, int y){
	if(robot != NULL){
			robot->incrementYawAngle(!negateTheValue);
	}
}

void RobotCamera::moveCameraStrafe(bool negateTheValue){
	if(robot != NULL){
			robot->incrementSpinDegrees(negateTheValue);
	}
}

void RobotCamera::resetCameraAngle(){
	if(robot != NULL){
		robot->resetOrientation();
	}
}

//----------------------------------------------------------------
//							LIGHTING
//----------------------------------------------------------------

void RobotCamera::toggleLight()
{
	robot->toggleLight();
}

//----------------------------------------------------------------
//			ROBOT ATTACHMENT AND SYNCHRONIZATION
//----------------------------------------------------------------
// FUTURE IDEAS: Eventually to to prepare for deleting robots (ie. detach)

void RobotCamera::attachToRobot(Robot* r){
	if(r != NULL){
		robot = r;
		hasRobot = true;
		robot->attachToCamera(this);
		synchEyePosition();
		synchLookAtPosition();
	}
}

void RobotCamera::synchEyePosition(){
	locX = robot->getEyeX();
	locY = robot->getEyeY();
	locZ = robot->getEyeZ();
}

void RobotCamera::synchLookAtPosition(){
	GLfloat* i = robot->getLookAt();
	lookAt[0] = i[0];
	lookAt[1] = i[1];
	lookAt[2] = i[2];
	delete [] i;
}

void RobotCamera::update(){
	synchEyePosition();
	synchLookAtPosition();
}

