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
}    

void MissileModel::render() 
{
	glDisable(GL_LIGHTING);
	
	GLUquadricObj *quadratic = gluNewQuadric();
	gluQuadricTexture(quadratic, true);

	glPushMatrix();
		glPushMatrix();
			//glScalef(1.5f, 1.0f, 1.0f);
			glColor3f(1.0f, 0.0f, 0.0f);
			gluSphere(quadratic, 2, 8, 8);
		glPopMatrix();

		glPushMatrix();
			//glTranslatef(1.0f, 0.0f, 1.0f);
			glColor3f(.7f,.7f,.7f);
			TextureManager::getInstance()->enableTexture();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("missile.bmp"));
			gluCylinder(quadratic, 2, 2, 10, 8, 8);


			glDisable(GL_TEXTURE_2D);

			glTranslatef(0.0f, 0.0f, 10.0f);
			glColor3f(1.0f,.0f,0.0f);
			gluCylinder(quadratic, 2, 3, 3, 8, 8);
		glPopMatrix();


		//smoke effect trial lol

		glDisable(GL_DEPTH_TEST);

		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smoke.bmp"));
			for (int i = 0; i < 2; i++)
			{
				glTranslatef(0.0f, 0.0f, 13.0f);
				glPushMatrix();
					glColor4f(0.7f, 0.7f, 0.7f, 1/(i + 1) * 10.0f);
					glTranslatef(0.0f, sin((GLfloat)i * rand()), (GLfloat)i * 0.025f);
					glBegin(GL_TRIANGLES);
					//std::cout << sin(rand() * 10.0f)* 2.0f << endl;

						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(0.0f, 0.0f, 0.0f);

						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(0.0f, 0.0f, 1.0f);

						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(0.0f, 1.0f, 0.0f);

						glVertex3f(0.0f, 0.0f, 1.0f);
						glVertex3f(0.0f, 1.0f, 1.0f);
						glVertex3f(0.0f, 1.0f, 0.0f);
					glEnd();
				glPopMatrix();
			}
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);


	glPopMatrix();
	gluDeleteQuadric(quadratic);
	

}