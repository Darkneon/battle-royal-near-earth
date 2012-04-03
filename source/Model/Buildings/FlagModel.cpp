/* 
 * File:   FlagModel.cpp
 * Author: Addison
 * 
 * Created on April 2, 2012, 3:04 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "FlagModel.h"

FlagModel::FlagModel(GLfloat r, GLfloat g, GLfloat b) {
    red = r;
    green = g;
    blue = b;
    y = 0.0f;
    inc = true;
}

FlagModel::FlagModel() {
    red = 1.0f;
    green = 0.0f;
    blue = 0.0f;
    y = 0.0f;
    inc = true;
}

void FlagModel::render()
{
    GLUquadricObj *quadratic = gluNewQuadric();
    //Draw the flag pole
    if (y < 1 && inc)
        y+=0.1f;
    else if (y>=1)
        inc = false;
    if (y>0 && !inc)
        y-=0.1f;
    else if (y<=0)
        inc = true;
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        gluCylinder(quadratic, .05, 0.05, 2, 6, 1);
    glPopMatrix();
    
    //Draw the flag 
    glPushMatrix();
        glColor3f(red, green, blue);
        glDisable(GL_CULL_FACE);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -1.0, 0.0f);
        glVertex3f(1.0f, -y, 0.0f);
        glEnd();
        glEnable(GL_CULL_FACE);
    glPopMatrix();
    //glutTimerFunc(001, render(), 1);
}

