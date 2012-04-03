/* 
 * File:   FollowCamera.h
 * Author: robert
 *
 * Created on March 26, 2012, 6:35 PM
 */

#ifndef FOLLOWCAMERA_H
#define	FOLLOWCAMERA_H
#include "Camera.h"

class FollowCamera : public Camera {
public:
    FollowCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane);
    virtual ~FollowCamera();
    
    void view();

	//Abstract methods
	void moveCameraForwards(bool negateTheValue) {}; //negate to move backwards
	void moveCameraStrafe(bool negateTheValue) {}; //negate to strafe left
	void modifyYaw(bool negateTheValue, int x, int y) {}; //negate to go counter-clockwise
	void zoom(bool zoomIn) {};
	void resetZoom() {};
	void toggleLight() {};
    
    void setLookAt(GLfloat x, GLfloat y, GLfloat z) {
        lookAt[0] = x;
        lookAt[1] = y;
        lookAt[2] = z;
        
        locX = x;
        locY = y + distance;
        locZ = z + distance;
        
        calculateDirection();
    }

    void calculateDirection() {
        direction[0] = lookAt[0];
        direction[1] = lookAt[1] - locY;
        direction[2] = lookAt[2] - locZ;
    }
    
private:
    GLfloat lookAt[3];
    GLfloat up[3];
    GLfloat direction[3];
    GLfloat distance;

};

#endif	/* FOLLOWCAMERA_H */

