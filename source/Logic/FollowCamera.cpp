/* 
 * File:   FollowCamera.cpp
 * Author: robert
 * 
 * Created on March 26, 2012, 6:35 PM
 */

#include "FollowCamera.h"

FollowCamera::FollowCamera(GLint viewWidth, GLint viewHeight, GLdouble viewNearPlane, GLdouble viewFarPlane) {
    Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	
	//camera rotation
	yaw = 0.0f;
	pitch = 0.0f;
	roll = 0.0f;

	//camera location
	locX = 25.0f;
	locY = 3.0f;
	locZ = 25.0f;

    lookAt[0] = 0.0f;
    lookAt[1] = 0.0f;
    lookAt[2] = 0.0f;

        
	fovy = DEFAULT_FOVY;

	up[0] = 0.0f;
	up[1] = 1.0f;
    up[2] = 0.0f;
    
    distance = 8.0f;
}

FollowCamera::~FollowCamera() {
}

void FollowCamera::view() {
	gluLookAt(locX, locY, locZ, direction[0], direction[1], direction[2], up[0], up[1], up[2]);
}

