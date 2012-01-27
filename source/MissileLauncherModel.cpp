/* 
 * File:   MissileLauncherModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:30 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "MissileLauncherModel.h"

MissileLauncherModel::MissileLauncherModel() {
}

void MissileLauncherModel::render() {
    glPushMatrix();
		glRotatef(-90, 0.0f, 1.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 4.0f, 0.0f);
			glScalef(1.1f, 0.9f, 0.8f);
			geoHelper.drawRectangle();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.5f, 0.0f, 0.5f);
			glPushMatrix();
				glTranslatef(-1.3f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				geoHelper.drawCylinder(360);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.5f, 0.0f, 0.5f);
				glTranslatef(1.6f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				geoHelper.drawCylinder(360);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}