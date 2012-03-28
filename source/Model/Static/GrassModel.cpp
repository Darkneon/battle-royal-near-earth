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
    build(3.0);
}

void GrassModel::build()
{
	glNewList(1, GL_COMPILE);
	
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("rusty_floor.bmp"));
	glPushMatrix();		
		
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
	glEndList();
}

//Will split the grass models into x by x cubes in order to improve sharpness of lighting, added by Addison
void GrassModel::build(GLfloat x)
{
        GLfloat split = 1/x;
	glNewList(1, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("rusty_floor.bmp"));	
        for (GLfloat i = 0.0f; i < 1; i+=split)
        {
            for (GLfloat j = 0.0f; j < 1; j+=split)
            {
               glPushMatrix();
               glTranslatef(j, 0.0f, i);
               glBegin(GL_TRIANGLES);
			glNormal3f(0.0f,1,0.0f);
                        
			glTexCoord2f (0.0f, 0.0f);            
			glVertex3f(0.0f ,0.0f ,0.0f);

			glTexCoord2f (1.0, 0.0);
                        glVertex3f(split, 0.0f ,0.0f);
            
			glTexCoord2f (1.0, 1.0);
                        glVertex3f(split, 0.0f, -split);

			glTexCoord2f (0.0, 0.0);
                        glVertex3f(0.0f ,0.0f ,0.0f);

			glTexCoord2f (1.0, 1.0);
                        glVertex3f(split, 0.0f, -split);

			glTexCoord2f (0.0, 1.0);
                        glVertex3f(0.0f, 0.0f, -split);
                glEnd();  
                glPopMatrix();
            }
        }
        glEndList();
}

void GrassModel::render() {
    glTranslatef(0,0,1);
	glColor3f(0.8f, 0.8f, 0.8f);
	TextureManager::getInstance()->enableTexture();

	glCallList(1);
	glDisable(GL_TEXTURE_2D);
}

