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

#include "Robot/CannonModel.h"
#include "Robot/NuclearModel.h"
#include "Material/MetalMaterial.h"

CannonModel::CannonModel() {    
	teamNumber = new TeamNumberModel();
    material = (Material*)(new MetalMaterial());
}    

void CannonModel::render() 
{
	TextureManager::getInstance()->enableTexture();

	glPushMatrix();
		glTranslatef(-0.1f, 0.0f, 0.0f);
		glPushMatrix();
			glTranslatef(0.5f, 0.1f, 0.5f);
			glScalef(0.3f, 0.4f, 0.3f);
			glColor3f(0.7f, 0.7f, 0.7f);

			//chassis
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smooth_metal.bmp"));
			GeoHelper::drawTrapezoidalPrism();
			
			GLUquadricObj *quadratic = gluNewQuadric();

			//skull logo
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("skull.bmp"));
			glPushMatrix();
				glTranslatef(0.5f, 0.2f, 1.01f);
				GLfloat* normal = new GLfloat[3];

				glScalef(0.5f, 0.6f, 0.5f);
				glBegin(GL_TRIANGLES);
					GeoHelper::findNormal3f(-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, normal);
					glNormal3fv(normal);

					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5f, -0.5f, 0.0f);

					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(0.5f, -0.5f, 0.0f);

					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5f, 0.5f, 0.0f);
					
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(0.5f, -0.5f, 0.0f);

					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(0.5f, 0.5f, 0.0f);

					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5f, 0.5f, 0.0f);
				glEnd();
				
				delete [] normal;

			glPopMatrix();
			
			//cannons
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("titanium.bmp"));
			
			gluQuadricTexture(quadratic,true);

			glPushMatrix();
				glTranslatef(-0.2f, 0.35f, 0.0f);
				glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

				glPushMatrix();
					glTranslatef(0.5f, 0.0f, 0.0f);
					drawBarrel(quadratic);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(-0.5f, 0.0f, 0.0f);
					drawBarrel(quadratic);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //render team number
			glTranslatef(0.89f, 0.0f, 0.75f);
			glScalef(0.5f, 0.5f, 0.5f);
			glRotatef(90, 0.0f,1.0f, 0.0f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			teamNumber->render();
		glPopMatrix();
    glPopMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);

	gluDeleteQuadric(quadratic);
	glDisable(GL_TEXTURE_2D);
}

void CannonModel::drawBarrel(GLUquadricObj* quadratic)
{
	gluCylinder(quadratic, 0.125, 0.125, 1.5, 10, 10);
	glTranslatef(0.0f, 0.0f, 1.5f);
	gluCylinder(quadratic, 0.125, 0.18, 0.1, 10, 10);
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadratic, 0.18, 0.18, 0.1, 10, 10);
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluDisk(quadratic, 0.0, 0.18, 10, 10);
}