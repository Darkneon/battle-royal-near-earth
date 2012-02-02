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

#include "NuclearModel.h"
#include "PhaserModel.h"
#include "TeamNumberModel.h"

NuclearModel::NuclearModel() { 
}

void NuclearModel::render() 
{
    
	GLUquadricObj *quadratic = gluNewQuadric();
    glPushMatrix();
		glTranslatef(0.5f,0.0f,0.5f);
		glScalef(0.6f, 0.6f, 0.6f);
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
	
    

	gluDeleteQuadric(quadratic);
}