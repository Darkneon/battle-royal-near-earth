/* 
 * File:   MountainModel.cpp
 * Author: robert
 * 
 * Created on January 21, 2012, 10:32 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "MountainModel.h"

MountainModel::MountainModel() {
}

void MountainModel::render() {
	TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("snow.bmp"));

	glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);		
		//leftmost
        GeoHelper::drawPeak();
        
		//right
		glColor3f(0.8f, 0.8f, 0.8f);
        glTranslatef(1.0f, 0.0f, 0.0f);
        glScalef(1.0f, 1.5f, 1.0f);
        GeoHelper::drawPeak();
        
		//middle
		glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(-.5f, 0.0f, 0.0f);
        glScalef(1.0f, 2.5f, 1.0f);
        GeoHelper::drawPeak();
        
    glPopMatrix();

	//glDisable(GL_TEXTURE_2D);
}