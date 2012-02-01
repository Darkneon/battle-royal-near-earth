/* 
 * File:   PlainBlockModel.cpp
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

#include "PlainBlockModel.h"

PlainBlockModel::PlainBlockModel() {
}

void PlainBlockModel::render() {
	glPushMatrix();
		GeoHelper::drawCube(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f);
	glPopMatrix();
}