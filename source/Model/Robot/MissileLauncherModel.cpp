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
	 TextureManager::getInstance()->enableTexture();

    glPushMatrix();
        glTranslatef(0.5f, 0.175f, 0.5f); //by jeff
        glScalef(0.27f, 0.27f, 0.27f); //by jeff
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		//glColor3f(0.7f, 0.7f, 0.7f);

		//Chasis
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smooth_metal.bmp"));
		glPushMatrix();
			glScalef(1.1f, 0.9f, 0.8f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		//Missile tubes
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
	glTranslatef(0.0f, 0.3f, 0.0f);
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadratic);
}

void MissileLauncherModel::drawMissileLauncher(GLUquadricObj* quadratic)
{
	
	gluQuadricTexture(quadratic,true);

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tubes.bmp")); 
	gluCylinder(quadratic, 0.25, 0.25, 2.5, 8, 8);

	//some cubes
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("warning.bmp")); 
	GeoHelper::drawCube(-0.26f, -0.26f, -0.26f, 0.26f, 0.26f, 0.26f);

	//more cubes
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 1.0f);
		GeoHelper::drawCube(-0.26f, -0.26f, -0.26f, 0.26f, 0.26f, 0.7f);
	glPopMatrix();

	//Front
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 2.5f);
		GeoHelper::drawCube(-0.26f, -0.26f, -0.26f, 0.26f, 0.26f, 0.26f);
		GLfloat* normal = new GLfloat[3];
		
		glTranslatef(0.0f, 0.0f, 0.27f);

		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("missile_face.bmp")); 
		glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(-0.26f,  -0.26f, 0.0f, 0.26f,  -0.26f, 0.0f, -0.26f,  0.26f, 0.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.26f,  -0.26f, 0.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.26f,  -0.26f, 0.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.26f,  0.26f, 0.0f);

		GeoHelper::findNormal3f(0.26f, -0.26f, 0.0f, 0.26f, 0.26f, 0.0f, -0.26f,  0.26f, 0.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.26f, -0.26f, 0.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.26f, 0.26f, 0.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.26f,  0.26f, 0.0f);

		glEnd();

		delete [] normal;
	glPopMatrix();
}