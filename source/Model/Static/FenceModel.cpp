/* 
 * File:   FenceModel.cpp
 * Author: robert
 * 
 * Created on January 21, 2012, 9:45 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "FenceModel.h"
#include "Helper/GeoHelper.h"
#include "Material/MetalMaterial.h"
#include "Material/RockMaterial.h"

FenceModel::FenceModel() {
    material = (Material*)(new RockMaterial());
}

void FenceModel::render() {
    TextureManager::getInstance()->enableTexture();
    
	glScalef(.5,.5,.5);
    glTranslatef(4,2,0);
	glPushMatrix();
        glColor3f(1, 1, 1);
        glScalef(2, 2, 2);
        glTranslatef(-2, -1, 0);
        drawBottom();
        
        glTranslatef(0.1f, 0, 0.1f);
        glScalef(0.8f, 0.8f, 0.8f);
        drawSection();
        
        glTranslatef(0.25f, 0.8f, 0.25f);
        glScalef(0.5f, 1.2f, 0.5f);
        drawSection();
        
        glTranslatef(0.4f, 1.0f, 0.4f);
        glScalef(0.2f, 1.2f, 0.2f);
        drawSection();        
    glPopMatrix();  
    
    glDisable(GL_TEXTURE_2D);
}

void FenceModel::drawBottom() {
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("fence.bmp"));

	GLfloat* normal = new GLfloat[3];

    glBegin(GL_TRIANGLES);
        GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, normal);
		glNormal3fv(normal); 
         
        glTexCoord2f(0.0f, 0.4f);    
        glVertex3f(0.0f, 0.0f ,0.0f);        
        
        glTexCoord2f(0.0f, 1.0f);    
        glVertex3f(0.0f, 0.0f ,1.0f);
        
        glTexCoord2f(1.0f, 0.4f);
        glVertex3f(1.0f, 0.0f ,0.0f);
    
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f ,1.0f);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 0.0f ,1.0f);
        
        glTexCoord2f(1.0f, 0.4f);
        glVertex3f(1.0f, 0.0f ,0.0f);        
    glEnd();
    
	delete [] normal;
}

void FenceModel::drawSection() {
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("fence.bmp"));
    
	GLfloat* normal = new GLfloat[3];
    glBegin(GL_TRIANGLES);    
    
        //bottom
		GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, normal);
		glNormal3fv(normal); 
        
        glTexCoord2f(0.0f, 0.0f);    
        glVertex3f(0, 0 ,0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 0 ,1);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,0);
            
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 0 ,1);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 0 ,1);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,0);        
        
        //top
		GeoHelper::findNormal3f(0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, normal);
		glNormal3fv(normal); 
        
        glTexCoord2f(0.0f, 0.35f);    
        glVertex3f(0, 1 ,0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,1);
        
        glTexCoord2f(1.0f, 0.35f);
        glVertex3f(1, 1 ,0);

        glTexCoord2f(0.0f, 1.0f);        
        glVertex3f(0, 1 ,1);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 1 ,1);
        
        glTexCoord2f(1.0f, 0.35f);
        glVertex3f(1, 1 ,0); 

        //side 1        
		GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, normal);
		glNormal3fv(normal); 
        
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0, 0 ,0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0, 0 ,1);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0, 0 ,1);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0, 1 ,1);   
        
        //side 2
		GeoHelper::findNormal3f(1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, normal);
		glNormal3fv(normal); 
        
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1, 0 ,0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(1, 1 ,0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,1);
                    
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,1);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(1, 1 ,0);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 1 ,1);        
            
        //front
		GeoHelper::findNormal3f(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, normal);
		glNormal3fv(normal); 

        
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0, 0 ,1);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,1);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,1);
    
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,1);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,1);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 1 ,1);    

        //back
        //ToDo
//        glNormal3fv( GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f) );
        glNormal3f(0.0f, 0.0f, 1.0f);
        
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0, 0 ,0);     
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,0);
    
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1, 0 ,0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0, 1 ,0);     

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1, 1 ,0);          
    glEnd();    

	delete [] normal;
}


