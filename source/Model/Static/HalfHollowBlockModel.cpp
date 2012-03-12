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
	TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("marble.bmp"));
	glPushMatrix();
		glTranslatef(.5,.25,.5);
		glScalef(1.0f, 0.5f, 1.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		GeoHelper::drawCube(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.25f);
		GeoHelper::drawCube(-0.5f, -0.5f, -0.25f, -0.25f, 0.5f, 0.25f);
		GeoHelper::drawCube(-0.5f, -0.5f, 0.25f, 0.5f, 0.5f, 0.5f);
		GeoHelper::drawCube(0.25f, -0.5f, -0.25f, 0.5f, 0.5f, 0.5f);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

