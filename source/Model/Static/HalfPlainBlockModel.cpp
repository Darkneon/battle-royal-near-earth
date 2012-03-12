/* 
 * File:   HalfPlainBlockModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:21 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "HalfPlainBlockModel.h"

HalfPlainBlockModel::HalfPlainBlockModel() {
}

void HalfPlainBlockModel::render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("ink.bmp"));
	glTranslatef(.5,.25,.5);
	glPushMatrix();
		GeoHelper::drawCube(-0.5f, -0.25, -0.5f, 0.5f, 0.25, 0.5f);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
}

