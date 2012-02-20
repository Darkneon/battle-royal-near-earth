/* 
 * File:   MountainModel.cpp
 * Author: robert
 * 
 * Created on January 21, 2012, 10:32 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "MountainModel.h"

MountainModel::MountainModel() {
}

void MountainModel::render() {
    
	glPushMatrix();
        glColor3f(1,1,1);
		
		//leftmost
        drawPeak();
        
		//right
		glColor3f(.8f,.8f,.8f);
        glTranslatef(1.0f, 0.0f, 0.0f);
        glScalef(1.0f, 1.5f, 1.0f);
        drawPeak();
        
		//middle
		glColor3f(.6f,.6f,.6f);
        glTranslatef(-.5f, 0.0f, 0.0f);
        glScalef(1.0f, 2.5f, 1.0f);
        drawPeak();
        
    glPopMatrix();
}

void MountainModel::drawPeak() {
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0.5f, 1, 0.5f);
        
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
        glVertex3f(0.5f, 1, 0.5f);
        
        glVertex3f(1, 0, 1);
        glVertex3f(0, 0, 1);
        glVertex3f(0.5f, 1, 0.5f);
        
        glVertex3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0.5f, 1, 0.5f);        
    glEnd();
    
}