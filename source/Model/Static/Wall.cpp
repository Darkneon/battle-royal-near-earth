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
#include "../Material/OrganicMaterial.h"

Wall::Wall() {
	
	material = (Material*)(new OrganicMaterial());
}

void Wall::render() {
	TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("vines.bmp"));
	glPushMatrix();
		GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 1.0f, 6.0f, 1.0f);
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
}