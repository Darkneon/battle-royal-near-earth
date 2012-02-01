/* 
 * File:   PhaserModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 2:55 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "PhaserModel.h"

PhaserModel::PhaserModel() {
}

void PhaserModel::render() {
	glTranslatef(.7,0,.5);//by jeff
	glScalef(.5,.5,.5);
    glPushMatrix();
		glTranslatef(-0.9f, 0.9f, 0.5f);

		//back panel
		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glTranslatef(1.0f, 0.0f, 0.0f);
			glScalef(1.2f, 1.0f, 1.2f);
			GeoHelper::drawCylinder(180);
		glPopMatrix();

		//cannon barrel
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glTranslatef(-0.1f, 0.0f, -0.6f);
			glScalef(0.5f, 1.1f, 0.4f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		//cannon base
		glPushMatrix();
			glColor3f(0,1,0);
			glTranslatef(1.1f, -1.1f, -0.125f);
			glScalef(0.9f, 0.5f, 0.9f);
			GeoHelper::drawCylinder(360);
		glPopMatrix();
	glPopMatrix();
}