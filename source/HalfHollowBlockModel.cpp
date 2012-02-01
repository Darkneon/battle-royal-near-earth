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

HalfHollowBlockModel::HalfHollowBlockModel() {
}

void HalfHollowBlockModel::render() {
	glTranslatef(.5,.25,.5);
	glPushMatrix();
		geoHelper.drawCube(-0.5f, -0.25f, -0.5f, 0.5f, 0.25f, -0.25f);
		geoHelper.drawCube(-0.5f, -0.25f, -0.25f, -0.25f, 0.25f, 0.25f);
		geoHelper.drawCube(-0.5f, -0.25f, 0.25f, 0.5f, 0.25f, 0.5f);
		geoHelper.drawCube(0.25f, -0.25f, -0.25f, 0.5f, 0.25f, 0.5f);
	glPopMatrix();
}

