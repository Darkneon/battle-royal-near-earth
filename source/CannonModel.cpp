/* 
 * File:   CannonModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 6:59 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "CannonModel.h"

CannonModel::CannonModel() {
}

void CannonModel::render() {
	glTranslatef(.5,.2,.5); //by Jeff
	glScalef(.4,.8,.4);//by Jeff
    glPushMatrix();
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			GeoHelper::drawTrapezoidalPrism();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glTranslatef(-0.9f, 0.35f, 0.5f);
			glRotatef(90, 0.0f, 0.0f, 1.0f);
			glScalef(0.1f, 0.6, 0.1f);
			GeoHelper::drawCylinder(360);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glTranslatef(-0.9f, 0.35f, -0.5f);
			glRotatef(90, 0.0f, 0.0f, 1.0f);
			glScalef(0.1f, 0.6, 0.1f);
			GeoHelper::drawCylinder(360);
		glPopMatrix();
	glPopMatrix();
}