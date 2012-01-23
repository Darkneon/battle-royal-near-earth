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
        glTranslatef(4, 0, 0);
        drawPeak();
        
        glTranslatef(1, 0, 0.5);
        glScalef(1, 1.5, 1);
        drawPeak();
        
        glTranslatef(1, 0, -0.5f);
        glScalef(1, 2.5, 1);
        drawPeak();
        
        glTranslatef(-1, 0, -0.5f);
        glScalef(1, 0.5, 1);
        drawPeak();
        
        glTranslatef(0, 0, 1);
        glScalef(1, 0.75f, 1.25f);
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