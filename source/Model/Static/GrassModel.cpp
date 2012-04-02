/* 
 * File:   GrassModel.cpp
 * Author: robert
 * 
 * Created on January 26, 2012, 1:35 PM
 */

#include "GrassModel.h"
#include "TeamNumberModel.h"
#include "Material/OrganicMaterial.h"

bool GrassModel::teamNumber = false;

GrassModel::GrassModel() {
    material = (Material*)(new OrganicMaterial());
    build();
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
	if(teamNumber){
		teamNumberRender();
	}
	glColor3f(0.8f, 0.8f, 0.8f);
	TextureManager::getInstance()->enableTexture();

	glCallList(1);
	glDisable(GL_TEXTURE_2D);
}

void GrassModel::teamNumberRender() {	
    TextureManager::getInstance()->enableTexture();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("team.bmp"));

    glColor3f(1.0f, 1.0f, 1.0f);
    
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
