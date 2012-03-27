/* 
 * File:   ElectronicsModel.cpp
 * Author: Jeffrey
 * 
 * Created on January 27, 2012, 1:23 AM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "ElectronicsModel.h"
#include "Material/MetalMaterial.h"

ElectronicsModel::ElectronicsModel() {    
    material = (Material*)(new MetalMaterial());
	teamNumber = new TeamNumberModel();
	build();
}

void ElectronicsModel::build()
{
	glNewList(7, GL_COMPILE);
		glPushMatrix();
			glTranslatef(.5f, 0, 0.5f);
			glRotatef(-90.0f,0.0f,1.0f,0.0f);
			glScalef(.4f,.4f,.4f);	
			//Rotation for full object
			glRotatef(-90, 1, 0, 0);	

			glPushMatrix();
				GLUquadricObj *quadratic = gluNewQuadric();
				//Base
				glColor3f(.2f,.2f,.2f);
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("concrete_bare.bmp"));
				gluQuadricTexture(quadratic,true);
				gluCylinder(quadratic, .5, .5, .1, 8, 3);

				// Bottom of Base
				glColor3f(.2f,.2f,.2f);
				glTranslatef(0.0f,0.0f,0.0f);
				gluDisk(quadratic, 0, .5, 8, 5);
		
				// Top of Base with Team Number
				glColor3f(.2f,.2f,.2f);
				glTranslatef(0.0f,0.0f,.1f);
				gluDisk(quadratic, 0, .5, 8, 5);
				glPushMatrix();
					glColor3f(1.0f,1.0f,1.0f);
					glScalef(0.4f,0.4f,0.4f);
					glTranslatef(-0.5f,-1.3f,0.0f);
					glRotatef(90,1.0f,0.0f,0.0f);
					teamNumber->render();
				glPopMatrix();
			glPopMatrix();

			TextureManager::getInstance()->enableTexture();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("concrete_bare.bmp"));
			glPushMatrix();
				//Neck
				glColor3f(.4f,.4f,.4f);
				gluCylinder(quadratic, .2, .2, .475, 8, 4);
			glPopMatrix();
		
			glPushMatrix();
				//Sphere: rotate sphere upward
				glRotatef(-20,1.0f,0.0f,0.0f);

				//Translate clipped sphere to top of neck
				glTranslatef(0.0f,-.5f,.8f);
			
				glPushMatrix();
					//set up clip plane & draw sphere
					GLdouble coordinate[4] = {0,1,0,.15};
					glClipPlane(GL_CLIP_PLANE0, coordinate);
					glEnable(GL_CLIP_PLANE0);
						//outer sphere
						glColor3f(.5,.5,.5);
						glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metal4.bmp"));
						gluQuadricTexture(quadratic,true);
						glPushMatrix();
							glRotatef(180,1.0f,0.0f,0.0f);
							gluSphere(quadratic, .6, 10,10);
						glPopMatrix();
						//inner sphere
						gluQuadricOrientation(quadratic, GLU_INSIDE);
						glColor3f(.55f, .55f, .55f);
						glPushMatrix();
							glRotatef(180,1.0f,0.0f,0.0f);
							gluSphere(quadratic, .5, 10, 10);
						glPopMatrix();
						gluQuadricOrientation(quadratic, GLU_OUTSIDE);
					glDisable(GL_CLIP_PLANE0);
					glPushMatrix();
						glTranslatef(0.0f, -.15f, 0.0f);
						glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
						glColor3f(.4f, .4f, .4f);
						gluDisk(quadratic, .465, .59, 20, 5);
					glPopMatrix();

					//draw antenna
					glPushMatrix();
						glTranslatef(0.0f, 0.55f, 0.0f);
						glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
						glColor3f(.8f, .8f, .8f);
						gluCylinder(quadratic, .05, .0, .9, 8, 4);
						glPushMatrix();
							//Tip of antenna
							glTranslatef(0.0f, 0.0f, 0.925f);
							gluSphere(quadratic, .1, 3, 3);
						glPopMatrix();
					glPopMatrix();

				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		gluDeleteQuadric(quadratic);
	glEndList();
}

void ElectronicsModel::render()
{
    TextureManager::getInstance()->enableTexture();
	glCallList(7);
    glDisable(GL_TEXTURE_2D);
}