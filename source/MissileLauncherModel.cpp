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
	//height approx. .3
}

void MissileLauncherModel::render() {
	glTranslatef(.5f,0.175f,.5f);//by jeff
	glScalef(.27f,.27f,.27f);//by jeff
    glPushMatrix();
		glRotatef(-90, 0.0f, 1.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 4.0f, 0.0f);
			glScalef(1.1f, 0.9f, 0.8f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.5f, 0.0f, 0.5f);
			glPushMatrix();
				glTranslatef(-1.3f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.5f, 0.0f, 0.5f);
				glTranslatef(1.6f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}