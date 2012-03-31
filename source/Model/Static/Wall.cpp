/* 
 * File:   Wall.h
 * Author: Jonathan
 *
 * Created on March 31, 2012, 7:39 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Wall.h"

Wall::Wall() {
}

void Wall::render() {
	TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("brick.bmp"));
	glPushMatrix();
	//GeoHelper::drawCube();
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
}