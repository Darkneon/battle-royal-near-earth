/* 
 * File:   GrassModel.cpp
 * Author: robert
 * 
 * Created on January 26, 2012, 1:35 PM
 */

#include "GrassModel.h"
#include "TeamNumberModel.h"
#include "Material/OrganicMaterial.h"

GrassModel::GrassModel() {
    TeamNumberModel* child = new TeamNumberModel();
    setNextChild( (Model*)child );
    
    material = (Material*)(new OrganicMaterial());
}

void GrassModel::render() {
    glTranslatef(0,0,1);
	
	glColor3f(0.8f, 0.8f, 0.8f);
	glEnable(GL_TEXTURE_2D);
    glPushMatrix();		
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("rusty_floor.bmp"));
        glBegin(GL_TRIANGLES);
			glNormal3f(0.0f,1.0f,0.0f);

			glTexCoord2f (0.0f, 0.0f);            
			glVertex3f(0 ,0 ,0);

			glTexCoord2f (1.0, 0.0);
            glVertex3f(1, 0 ,0);

			glTexCoord2f (1.0, 1.0);
            glVertex3f(1, 0, -1);

			glTexCoord2f (0.0, 0.0);
            glVertex3f(0 ,0 ,0);

			glTexCoord2f (1.0, 1.0);
            glVertex3f(1, 0, -1);

			glTexCoord2f (0.0, 1.0);
            glVertex3f(0, 0, -1);
        glEnd();
    glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

