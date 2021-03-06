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
    TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("team.bmp"));

   // glColor3f(1.0f, 1.0f, 1.0f);
    
    GLfloat distance = -1.0f / 5.0f;
    glPushMatrix();
        glTranslatef(0.25f, 0.01f, -0.25f);
		glScalef(0.5, 1, 0.5);
        glBegin(GL_TRIANGLES);
			glNormal3f(0.0f,1.0f,0.0);
            //bottom
			glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, 0, 0);
			
			glTexCoord2f(1.0f, 0.0f);
            glVertex3f(1, 0, 0);

			glTexCoord2f(1.0f, -distance);
            glVertex3f(1, 0, distance);

			glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, 0, 0);

			glTexCoord2f(1.0f, -distance);
            glVertex3f(1, 0, distance);

			glTexCoord2f(0.0f, -distance);
            glVertex3f(0, 0, distance);

            // mid bottom
			glTexCoord2f(0.0f, -distance);
            glVertex3f(0, 0, distance);

			glTexCoord2f(0.25f, -distance);
            glVertex3f(0.25f, 0, distance);

			glTexCoord2f(0.25f, -distance * 2);
            glVertex3f(0.25f, 0, distance * 2);

			glTexCoord2f(0.0f, -distance);
            glVertex3f(0, 0, distance);

			glTexCoord2f(0.25f, -distance * 2);
            glVertex3f(0.25f, 0, distance * 2);

			glTexCoord2f(0.0f, -distance*2);
            glVertex3f(0, 0, distance * 2);

            // mid
			glTexCoord2f(0.0f, -distance * 2);
            glVertex3f(0, 0, distance * 2);

			glTexCoord2f(1.0f, -distance * 2);
            glVertex3f(1, 0, distance * 2);

			glTexCoord2f(1.0f, -distance * 3);
            glVertex3f(1, 0, distance * 3);

			glTexCoord2f(0.0f, -distance * 2);
            glVertex3f(0, 0, distance * 2);

			glTexCoord2f(1.0f, -distance * 3);
            glVertex3f(1, 0, distance * 3);

			glTexCoord2f(0.0f, -distance * 3);
            glVertex3f(0, 0, distance * 3);

            // mid top
			glTexCoord2f(0.75f, -distance * 3);
            glVertex3f(0.75f, 0, distance * 3);

			glTexCoord2f(1.0f, -distance * 3);
            glVertex3f(1, 0, distance * 3);

			glTexCoord2f(1.0f, -distance * 4);
            glVertex3f(1, 0, distance * 4);

			glTexCoord2f(0.75f, -distance * 3);
            glVertex3f(0.75f, 0, distance * 3);

			glTexCoord2f(1.0f, -distance * 4);
            glVertex3f(1, 0, distance * 4);

			glTexCoord2f(0.75f, -distance * 4);
            glVertex3f(0.75, 0, distance * 4);

            //top 
			glTexCoord2f(0.0f, -distance * 4);
            glVertex3f(0, 0, distance * 4);

			glTexCoord2f(1.0f, -distance * 4);
            glVertex3f(1, 0, distance * 4);

			glTexCoord2f(1.0f, -distance * 5);
            glVertex3f(1, 0, distance * 5);

			glTexCoord2f(0.0f, -distance * 4);
            glVertex3f(0, 0, distance * 4);

			glTexCoord2f(1.0f, -distance * 5);
            glVertex3f(1, 0, distance * 5);

			glTexCoord2f(0.0f, -distance * 5);
            glVertex3f(0, 0, distance * 5);
        glEnd();
    glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}
