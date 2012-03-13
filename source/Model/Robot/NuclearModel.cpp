/* 
 * File:   NuclearModel.cpp
 * Author: Jeffrey
 * 
 * Created on January 27, 2012, 1:24 AM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/NuclearModel.h"
#include "Robot/PhaserModel.h"
#include "Material/MetalMaterial.h"

NuclearModel::NuclearModel() { 
	teamNumber = new TeamNumberModel();
    material = (Material*)(new MetalMaterial());
}

void NuclearModel::render() 
{
    TextureManager::getInstance()->enableTexture();
	GLUquadricObj *quadratic = gluNewQuadric();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metalWarning.bmp"));
	gluQuadricTexture(quadratic,true);
	
	glPushMatrix();
		glTranslatef(0.5f,0.0f,0.5f);
		glScalef(0.5f, 0.7f, 0.5f);
        glRotatef(-90, 1,0,0);
		glColor3f(0.4f,0.4f,0.4f);
		gluCylinder(quadratic, .45, .45, .5, 8, 5);

		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metalRadiation.bmp"));
		gluQuadricTexture(quadratic,true);
		// Bottom
		glColor3f(0.6f,0.6f,0.6f);
		gluDisk(quadratic, 0, .45, 8, 5);
		
		// Top with Team Number
		glTranslatef(0,0,.5);
		gluDisk(quadratic, 0, .45, 8, 5);
		glPushMatrix();
			glColor3f(0.0f,0.0f,0.0f);
			glScalef(0.2f,0.2f,0.2f);
			glTranslatef(-0.5f,-0.5f,0.0f);
			glRotatef(90,1.0f,0.0f,0.0f);
			teamNumber->render();
		glPopMatrix();

    glPopMatrix();
	glTranslatef(0, 0.355f, 0);
    

	gluDeleteQuadric(quadratic);
    glDisable(GL_TEXTURE_2D);

}