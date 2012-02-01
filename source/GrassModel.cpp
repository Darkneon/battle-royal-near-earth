/* 
 * File:   GrassModel.cpp
 * Author: robert
 * 
 * Created on January 26, 2012, 1:35 PM
 */

#include "GrassModel.h"
#include "TeamNumberModel.h"

GrassModel::GrassModel() {
    TeamNumberModel* child = new TeamNumberModel();
    setNextChild( (Model*)child );
}

void GrassModel::render() {
    glTranslatef(0,0,1);
	glColor3f(0, 1, 0);
    
    glPushMatrix();
        glBegin(GL_TRIANGLES);
            glVertex3f(0 ,0 ,0);
            glVertex3f(1, 0 ,0);
            glVertex3f(1, 0, -1);

            glVertex3f(0 ,0 ,0);
            glVertex3f(1, 0, -1);
            glVertex3f(0, 0, -1);
        glEnd();
    glPopMatrix();
}

