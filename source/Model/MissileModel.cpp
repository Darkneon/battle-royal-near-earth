/* 
 * File:   MissileModel.cpp
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
#include "MissileModel.h"
#include "Material/MetalMaterial.h"

MissileModel::MissileModel() {    
    material = (Material*)(new MetalMaterial());
	smokeX = smokeY = smokeZ = 0.0f;
}    

void MissileModel::render() 
{	
	GLUquadricObj *quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);
	glPushMatrix();

	glScalef(0.02f,0.02f,0.015f);
	glTranslatef(0.0f,0.0f,-5.0f);
		glPushMatrix();	
			glPushMatrix();
				//glScalef(1.5f, 1.0f, 1.0f);
				glColor3f(1.0f, 0.0f, 0.0f);
				gluSphere(quadric, 2, 8, 8);
			glPopMatrix();

			glPushMatrix();
				//glTranslatef(1.0f, 0.0f, 1.0f);
				glPushMatrix();
					glRotatef(180.0f,1.0f,0.0f,0.0f);
					gluDisk(quadric,0,2,5,5);
				glPopMatrix();
				glColor3f(.7f,.7f,.7f);
				TextureManager::getInstance()->enableTexture();
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("missile.bmp"));
				gluCylinder(quadric, 2, 2, 10, 8, 8);

				glTranslatef(0.0f, 0.0f, 10.0f);
				glColor3f(1.0f,.0f,0.0f);
				gluCylinder(quadric, 2, 3, 3, 8, 8);
			glPopMatrix();


			//smoke effect
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smoke.bmp"));
				glTranslatef(0.0f, 0.0f, 13.0f);
				for (int i = 1; i < 8; i++)
				{
				
					glPushMatrix();
						glColor4f(0.7f, 0.7f, 0.7f, 0.3f);
						glTranslatef(0.0f, 0.0f, (GLfloat)i * 0.5f);

						smokeX = cos((GLfloat)i * rand()) + sin((GLfloat)i * rand());
						smokeY = sin((GLfloat)i * rand()) + cos((GLfloat)i * rand());
						smokeZ++;

						if (smokeZ == 10.0f)
							smokeZ = 0.0f;

						glTranslatef(smokeX, smokeY, smokeZ);
						gluSphere(quadric, 1.0f, 5, 5);
					
					glPopMatrix();
				}
			glPopMatrix();

		glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);
}