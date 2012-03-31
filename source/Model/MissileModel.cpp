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
#include "MissileModel.h"
#include "Material/MetalMaterial.h"

MissileModel::MissileModel() {    
    material = (Material*)(new MetalMaterial());
	smokeX = smokeY = smokeZ = 0.0f;

	time_t lastUpdate = time(NULL);
	time_t currentTime = time(NULL);
}    

void MissileModel::render() 
{
	glDisable(GL_LIGHTING);
	
	GLUquadricObj *quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);

	glPushMatrix();
		glPushMatrix();
			//glScalef(1.5f, 1.0f, 1.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			gluSphere(quadric, 2, 8, 8);
		glPopMatrix();

		glPushMatrix();
			//glTranslatef(1.0f, 0.0f, 1.0f);
			glColor3f(.7f,.7f,.7f);
			TextureManager::getInstance()->enableTexture();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("missile.bmp"));
			gluCylinder(quadric, 2, 2, 10, 8, 8);
			

			glTranslatef(0.0f, 0.0f, 10.0f);
			glColor3f(1.0f,.0f,0.0f);
			gluCylinder(quadric, 2, 3, 3, 8, 8);
		glPopMatrix();


		//smoke effect trial lol

		//glEnable(GL_ALPHA16);
		//glDisable(GL_DEPTH_TEST);

		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smoke.bmp"));
			glTranslatef(0.0f, 0.0f, 13.0f);
			for (int i = 1; i < 4; i++)
			{
				
				glPushMatrix();
					glColor4f(0.7f, 0.7f, 0.7f, 0.3f);
					
					currentTime = time(NULL);

					
					lastUpdate = time(NULL);

					smokeX = 0.0f;//sin((GLfloat)i * rand()) + sin((GLfloat)i * rand());
					smokeY = sin((GLfloat)i * rand()) + cos((GLfloat)i * rand());
					smokeZ++;//sin((GLfloat)i * rand()) + cos((GLfloat)i * rand()) * 0.00001f;

					if (smokeZ == 10.0f)
						smokeZ = 0.0f;


					glTranslatef(smokeX, smokeY, smokeZ);

					//glScalef(2.0f, 2.0f, 2.0f);
					//gluDisk(quadratic, 0.0f, 1.0f, 8, 8);
					gluSphere(quadric, 1.0f, 8, 8);
					/*
					glBegin(GL_TRIANGLES);
					//std::cout << sin(rand() * 10.0f)* 2.0f << endl;

						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(0.0f, 0.0f, 0.0f);

						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(0.0f, 0.0f, 1.0f);

						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(0.0f, 1.0f, 0.0f);

						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(0.0f, 0.0f, 1.0f);

						glTexCoord2f(1.0f, 1.0f);
						glVertex3f(0.0f, 1.0f, 1.0f);

						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(0.0f, 1.0f, 0.0f);
					glEnd();
					*/
				glPopMatrix();
			}
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);


	glPopMatrix();
	gluDeleteQuadric(quadric);
	
	glDisable(GL_TEXTURE_2D);
	//glDisable(GL_ALPHA);
}