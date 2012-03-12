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
        glTranslatef(0.5f, 0.175f, 0.5f);//by jeff
        glScalef(0.27f, 0.27f, 0.27f);//by jeff
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		glColor3f(0.7f, 0.7f, 0.7f);

		//Chasis
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smooth_metal.bmp"));
		glPushMatrix();
			glScalef(1.1f, 0.9f, 0.8f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		//Missile tubes
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("warning.bmp")); 
		glPushMatrix();
			glTranslatef(0.0f, -0.25f, -1.25f);
			glPushMatrix();
				glTranslatef(-1.3f, 0.0f, 0.0f);
				drawMissileLauncher(quadratic);
			glPopMatrix();

			
			glPushMatrix();
				glTranslatef(1.3f, 0.0f, 0.0f);
				drawMissileLauncher(quadratic);
			glPopMatrix();

		glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadratic);
}

void MissileLauncherModel::drawMissileLauncher(GLUquadricObj* quadratic)
{
	gluQuadricTexture(quadratic,true);
	gluCylinder(quadratic, 0.25, 0.25, 2.5, 10, 10);

	//disk 1
	glPushMatrix();
		glRotatef(180, 0.0f, 1.0f, 0.0f);
		gluDisk(quadratic, 0.0, 0.25, 10, 10);
	glPopMatrix();

	//disk 2
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 2.5f);
		gluDisk(quadratic, 0.0, 0.25, 10, 10);
	glPopMatrix();
}