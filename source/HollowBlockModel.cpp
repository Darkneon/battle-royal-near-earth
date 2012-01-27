/* 
 * File:   HollowBlockModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 6:39 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "HollowBlockModel.h"

HollowBlockModel::HollowBlockModel() {
}

void HollowBlockModel::render() {
	glPushMatrix();
		geoHelper.drawCube(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.25f);
		geoHelper.drawCube(-0.5f, -0.5f, -0.25f, -0.25f, 0.5f, 0.25f);
		geoHelper.drawCube(-0.5f, -0.5f, 0.25f, 0.5f, 0.5f, 0.5f);
		geoHelper.drawCube(0.25f, -0.5f, -0.25f, 0.5f, 0.5f, 0.5f);
	glPopMatrix();
}