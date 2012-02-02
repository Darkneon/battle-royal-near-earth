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
#include "TeamNumberModel.h"

ElectronicsModel::ElectronicsModel() {
	TeamNumberModel* child = new TeamNumberModel();
    setNextChild( (Model*)child );
}

void ElectronicsModel::render() {
   
	glPushMatrix();
        glTranslatef(0.35f,0.8f,-0.3f);
        glScalef(.6,.6,.6);
		//Rotation for full object
		glRotatef(-90, 1, 0, 0);	

		glPushMatrix();
			GLUquadricObj *quadratic = gluNewQuadric();
			//Base
			glColor3f(.2,.2,.2);
			gluCylinder(quadratic, .8, .8, .1, 8, 3);

			// Bottom of Base
			glColor3f(.2,.2,.2);
			glTranslatef(0,0,0);
			gluDisk(quadratic, 0, .8, 8, 5);
		
			// Top of Base
			glColor3f(.2,.2,.2);
			glTranslatef(0,0,.1);
			gluDisk(quadratic, 0, .8, 8, 5);
		glPopMatrix();
		glTranslatef(0,.1,.1);
		
		glPushMatrix();
			//Neck
			glColor3f(.7,.7,.7);
			gluCylinder(quadratic, .2, .2, .4, 8, 4);
		
			// Top of Base
			glColor3f(.7,.7,.7);
			glTranslatef(0,0,.4);
			gluDisk(quadratic, 0, .2, 8, 4);
		glPopMatrix();
		
		glPushMatrix();
			//Sphere: rotate sphere upward
			glRotatef(-20,1,0,0);

			//Translate clipped sphere to top of neck
			glTranslatef(0,-.5,.8);
			
			glPushMatrix();
				//set up clip plane & draw sphere
				GLdouble coordinate[4] = {0,1,0,.15};
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					//outer sphere
					glColor3f(.5,.5,.5);
					gluSphere(quadratic, .6, 10,10);
					
					//inner sphere
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					glColor3f(.55,.55,.55);
					gluSphere(quadratic,.5, 10, 10);
					gluQuadricOrientation(quadratic, GLU_OUTSIDE);
				glDisable(GL_CLIP_PLANE0);
				glPushMatrix();
					glTranslatef(0,-.15,0);
					glRotatef(90, 1, 0, 0);
					glColor3f(.4,.4,.4);
					gluDisk(quadratic,.465, .59, 20, 5);
				glPopMatrix();

				//draw antenna
				glPushMatrix();
					glTranslatef(0,0.55,0);
					glRotatef(90,1,0,0);
					glColor3f(.8,.8,.8);
					gluCylinder(quadratic, .05, 0, .9, 8, 4);
					glPushMatrix();
						//Tip of antenna
						glTranslatef(0,0,0.925);
						gluSphere(quadratic, .1, 3, 3);
					glPopMatrix();
				glPopMatrix();

			glPopMatrix();
		glPopMatrix();

    glPopMatrix();

	gluDeleteQuadric(quadratic);
}