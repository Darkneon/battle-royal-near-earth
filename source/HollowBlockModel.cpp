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
	glTranslatef(.5,.5,.5);
	glPushMatrix();
		GeoHelper::drawCube(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.25f);
		GeoHelper::drawCube(-0.5f, -0.5f, -0.25f, -0.25f, 0.5f, 0.25f);
		GeoHelper::drawCube(-0.5f, -0.5f, 0.25f, 0.5f, 0.5f, 0.5f);
		GeoHelper::drawCube(0.25f, -0.5f, -0.25f, 0.5f, 0.5f, 0.5f);
	glPopMatrix();
}