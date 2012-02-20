/* 
 * File:   HalfHollowBlockModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 6:47 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "HalfHollowBlockModel.h"

HalfHollowBlockModel::HalfHollowBlockModel() 
{
}

void HalfHollowBlockModel::render() {
	glPushMatrix();
		glScalef(1.0f, 0.5f, 1.0f);
		HollowBlockModel::render();
	glPopMatrix();
}

