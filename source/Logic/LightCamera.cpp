/* 
 * File:   LightCamera.cpp
 * Author: Addison
 * 
 * Created on February 20, 2012, 7:41 PM
 */

#include "LightCamera.h"

LightCamera::LightCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat lookX, GLfloat lookY, GLfloat lookZ, GLint viewWidth, GLint viewHeight, GLdouble viewNearPlane, GLdouble viewFarPlane) 
{
    Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
    fovy = DEFAULT_FOVY;
    offset = 0.9f;
    this->posX = posX;
    this->posY = posY*offset;
    this->posZ = posZ;
    this->lookX = lookX;
    this->lookY = lookY;
    this->lookZ = lookZ;
}

void LightCamera::view()
{
        gluLookAt(posX, posY, posZ, posX+lookX, posY+lookY, posZ+lookZ,  0, 1, 0);

}
