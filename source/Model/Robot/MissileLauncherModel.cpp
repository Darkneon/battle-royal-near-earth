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
#include "NuclearModel.h"
#include "Material/MetalMaterial.h"

MissileLauncherModel::MissileLauncherModel() {
    //teamNumber = new TeamNumberModel();
    teamNumber = new TeamNumberModel();
    material = (Material*)(new MetalMaterial());
}

void MissileLauncherModel::render() {
	 //Draw number -- Addison
	 glPushMatrix();
			 glTranslatef(0.2f, 0.3f, 0.6f);
			 glScalef(0.5f, 0.5f, 0.5f);
			 teamNumber->render();
	 glPopMatrix();
     GLUquadricObj *quadratic = gluNewQuadric();
	 glEnable(GL_TEXTURE_2D);

    glPushMatrix();
        glTranslatef(0.5f,0.175f,0.5f);//by jeff
        glScalef(.27f,.27f,.27f);//by jeff
		glRotatef(-90, 0.0f, 1.0f, 0.0f);

		//chasis
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smooth_metal.bmp"));
		glPushMatrix();
			glColor3f(0.7f, 0.7f, 0.7f);
			glScalef(1.1f, 0.9f, 0.8f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("warning.bmp")); //for missile tubes
		glPushMatrix();
			glColor3f(0.7f, 0.7f, 0.7f);
			glPushMatrix();
				glTranslatef(-1.2f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				//glScalef(0.3f, 1.7f, 0.3f);
				gluQuadricTexture(quadratic,true);
				gluCylinder(quadratic, 0.25, 0.25, 1.5, 10, 10);

				//GeoHelper::drawCylinder(360);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.5f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
    glTranslatef(0, 0.3f, 0);
	gluDeleteQuadric(quadratic);
}