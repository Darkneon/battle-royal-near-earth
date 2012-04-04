/* 
 * File:   LightCamera.h
 * Author: Addison
 *
 * Created on February 20, 2012, 7:41 PM
 */

#ifndef LIGHTCAMERA_H
#define	LIGHTCAMERA_H
#include "Light/LightPost.h"
#include "Camera.h"


class LightCamera : public Camera
{
public:
	LightCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat lookX, GLfloat lookY, GLfloat lookZ);

	//interface methods
	void view();
	void moveCameraForwards(bool negateTheValue) {return;};
	void moveCameraStrafe(bool negateTheValue) {return;};
	void modifyYaw(bool negateTheValue, int x, int y) {return;};
	void zoom(bool zoomIn) {return;};
	void resetZoom() {return;};
        void toggleLight() {};
private:
	void calculate45DegreesForLocY(); //45 degrees for cams (useful for more than one class
        LightPost* light;
public:
        GLfloat posX; 
        GLfloat posY;
        GLfloat posZ;
        GLfloat lookX;
        GLfloat lookY;
        GLfloat lookZ;
        GLfloat offset;
};

#endif
