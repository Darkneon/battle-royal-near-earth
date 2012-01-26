/* 
 * File:   TeamNumberModel.cpp
 * Author: robert
 * 
 * Created on January 26, 2012, 1:13 PM
 */

#include "TeamNumberModel.h"


TeamNumberModel::TeamNumberModel() {
}

void TeamNumberModel::render() {
    glColor3f(0, 0.5f, 0);
    
    GLfloat distance = -1.0 / 5.0;
    glPushMatrix();
        glTranslatef(0, 0.01f, 0);
        glBegin(GL_TRIANGLES);
            //bottom
            glVertex3f(0, 0, 0);
            glVertex3f(1, 0, 0);
            glVertex3f(1, 0, distance);

            glVertex3f(0, 0, 0);
            glVertex3f(1, 0, distance);
            glVertex3f(0, 0, distance);

            // mid bottom
            glVertex3f(0, 0, distance);
            glVertex3f(0.25f, 0, distance);
            glVertex3f(0.25f, 0, distance * 2);

            glVertex3f(0, 0, distance);
            glVertex3f(0.25f, 0, distance * 2);
            glVertex3f(0, 0, distance * 2);

            // mid
            glVertex3f(0, 0, distance * 2);
            glVertex3f(1, 0, distance * 2);
            glVertex3f(1, 0, distance * 3);

            glVertex3f(0, 0, distance * 2);
            glVertex3f(1, 0, distance * 3);
            glVertex3f(0, 0, distance * 3);

            // mid top
            glVertex3f(0.75f, 0, distance * 3);
            glVertex3f(1, 0, distance * 3);
            glVertex3f(1, 0, distance * 4);

            glVertex3f(0.75f, 0, distance * 3);
            glVertex3f(1, 0, distance * 4);
            glVertex3f(0.75, 0, distance * 4);

            //top 
            glVertex3f(0, 0, distance * 4);
            glVertex3f(1, 0, distance * 4);
            glVertex3f(1, 0, distance * 5);

            glVertex3f(0, 0, distance * 4);
            glVertex3f(1, 0, distance * 5);
            glVertex3f(0, 0, distance * 5);
        glEnd();
    glPopMatrix();
}
