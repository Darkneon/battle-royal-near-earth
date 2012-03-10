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
#include "Static/TeamNumberModel.h"
#include "Material/MetalMaterial.h"

NuclearModel::NuclearModel() { 
    material = (Material*)(new MetalMaterial());
}

void NuclearModel::render() 
{
    
	GLUquadricObj *quadratic = gluNewQuadric();
	GLuint temp = TextureManager::getInstance()->getTextures("nuclearTexture64.bmp");
	glBindTexture(GL_TEXTURE_2D, temp);
	gluQuadricTexture(quadratic,true);
    glPushMatrix();
		glTranslatef(0.5f,0.0f,0.5f);
		glScalef(0.5f, 0.7f, 0.5f);
        glRotatef(-90, 1,0,0);
		glColor3f(0.4f,0.4f,0.4f);
		gluCylinder(quadratic, .45, .45, .5, 8, 5);

		// Bottom
		glColor3f(0.6f,0.6f,0.6f);
		gluDisk(quadratic, 0, .45, 8, 5);
		
		// Top
		glTranslatef(0,0,.5);
		gluDisk(quadratic, 0, .45, 8, 5);

		//Team #
			glPushMatrix();
				glColor3f(1.0f,0.0f,0.0f);
				glTranslatef(0.0f,0.0f,0.01f);
				glScalef(0.25f, 0.25f, 0.25f);
				glBegin(GL_LINES);
					glLineWidth(1.0f);
					glVertex3f(-0.25f, -0.25f, 0.0f);
					glVertex3f(0.25f, -0.25f, 0.0f);

					glVertex3f(-0.25f, -0.25f, 0.0f);
					glVertex3f(-0.25f, 0.0f, 0.0f);

					glVertex3f(0.25f, 0.0f, 0.0f);
					glVertex3f(-0.25f, 0.0f, 0.0f);

					glVertex3f(0.25f, 0.0f, 0.0f);
					glVertex3f(0.25f, 0.25f, 0.0f);

					glVertex3f(-0.25f, 0.25f, 0.0f);
					glVertex3f(0.25f, 0.25f, 0.0f);
				glEnd();
			glPopMatrix();
    glPopMatrix();
	glTranslatef(0, 0.355f, 0);
    

	gluDeleteQuadric(quadratic);
}