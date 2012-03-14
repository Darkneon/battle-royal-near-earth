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
	TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("ink.bmp"));
	glPushMatrix();
		glTranslatef(.5,.5,.5);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		GeoHelper::drawCube(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.25f);
		GeoHelper::drawCube(-0.5f, -0.5f, -0.25f, -0.25f, 0.5f, 0.25f);
		GeoHelper::drawCube(-0.5f, -0.5f, 0.25f, 0.5f, 0.5f, 0.5f);
		GeoHelper::drawCube(0.25f, -0.5f, -0.25f, 0.5f, 0.5f, 0.25f);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}