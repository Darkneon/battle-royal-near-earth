/* 
 * File:   PlayerModel.cpp
 * Author: robert
 * 
 * Created on January 19, 2012, 3:47 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "PlayerModel.h"
#include "AntennaModel.h"
#include <cstdlib>

PlayerModel::PlayerModel() {
    AntennaModel *child = new AntennaModel;
    setNextChild( (Model*)child );
}

void PlayerModel::render() {
    glEnable(GL_TEXTURE_2D);	
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("gold.bmp"));
	
    glPushMatrix();
        glScalef(0.3f,0.3f,0.3f);
        glColor3f(1, 1, 0);

        renderPlane();

        glPushMatrix();
            glTranslatef(0, 1.0f, 0);
            renderPlane();
        glPopMatrix();

        //front
        renderOneSide();

        //right side
        glPushMatrix();
            glTranslatef(3.0f, 0.0f, 0.0f);
            glRotated(-90.0f, 0, 1.0f, 0);
            renderOneSide();
        glPopMatrix();

        //back
        glPushMatrix();
            glTranslatef(3.0f, 0.0f, 3.0f);
            glRotated(180.0f, 0, 1.0f, 0);
            renderOneSide();
        glPopMatrix();

        //left side
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 3.0f);
            glRotated(90.0f, 0, 1.0f, 0);
            renderOneSide();
        glPopMatrix();
    glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);
}
void PlayerModel::renderOneSide() {
	GLfloat* normal = new GLfloat[3];

    glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, normal);
		glNormal3fv(normal); 

        //front left square
		glTexCoord2f(0.0f, 0.0f);    
        glVertex3f(0, 0, 0);		

		glTexCoord2f(0.0f, 1.0f);    
        glVertex3f(0, 1, 0);
      
		glTexCoord2f(1.0f, 1.0f);    
        glVertex3f(1, 0, 0);   

		glTexCoord2f(1.0f, 1.0f);    
        glVertex3f(1, 0, 0);

		glTexCoord2f(0.0f, 1.0f);    
        glVertex3f(0, 1, 0);

		glTexCoord2f(1.0f, 0.0f);            
		glVertex3f(1, 1, 0);   
         

		GeoHelper::findNormal3f(1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, normal);
		glNormal3fv(normal); 

        //front left inner 
		glTexCoord2f(0.0f, 0.0f);    
		glVertex3f(1, 0, 0);  
		
		glTexCoord2f(1.0f, 0.0f); 
        glVertex3f(1, 1, 0);      
		
		glTexCoord2f(0.0f, 1.0f);    
        glVertex3f(1, 0, 0.5f);
   		
		glTexCoord2f(0.0f, 1.0f);  
        glVertex3f(1, 0, 0.5f);  
		
		glTexCoord2f(1.0f, 0.0f);  
        glVertex3f(1, 1, 0);
				
		glTexCoord2f(1.0f, 1.0f);    
        glVertex3f(1, 1, 0.5f); 
        
        //front inner
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(1, 0, 0.5f);
        
        glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(1, 1, 0.5f);
        
        glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(2, 0, 0.5f);
        
        glTexCoord2f(1.0f, 1.0f); 
        glVertex3f(2, 0, 0.5f);
        
        glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(1, 1, 0.5f);
        
        glTexCoord2f(1.0f, 0.0f);         
        glVertex3f(2, 1, 0.5f);
        
        //front right inner
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(2, 0, 0.5f);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(2, 1, 0.5f);
        
        glTexCoord2f(0.0f, 1.0f);        
        glVertex3f(2, 0, 0);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(2, 0, 0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(2, 1, 0.5f);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(2, 1, 0);
 
        //front right square
        glTexCoord2f(0.0f, 0.0f);    
        glVertex3f(2, 0, 0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(2, 1, 0);
        
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(3, 0, 0);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(3, 0 ,0);
        
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(2, 1, 0);
        
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(3, 1, 0);
 
    glEnd();

	delete [] normal;
}

void PlayerModel::renderPlane() {
	GLfloat* normal = new GLfloat[3];
	
	glBegin(GL_TRIANGLES);
		//corner 1
		GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, normal);
		glNormal3fv(normal); 

		glTexCoord2f(0.0f, 0.0f);    
		glVertex3f(0, 0, 0);
		
		glTexCoord2f(0.0f, 1.0f);     
		glVertex3f(0, 0, 1);
		
		glTexCoord2f(1.0f, 1.0f);     
		glVertex3f(1, 0, 1);		                    

		glTexCoord2f(0.0f, 0.0f);     
		glVertex3f(0, 0, 0);

		glTexCoord2f(1.0f, 1.0f);     
		glVertex3f(1, 0, 1);

		glTexCoord2f(1.0f, 0.0f);     
		glVertex3f(1, 0, 0);
				
		//corner 2			
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2, 0, 0);		

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(2, 0, 1);
		
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(3, 0, 1);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2, 0, 0);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(3, 0, 1);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(3, 0, 0);

		//corner 3
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2, 0, 2);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(2, 0, 3);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(3, 0, 3);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2, 0, 2);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(3, 0, 3);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(3, 0, 2);

		//corner 4
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0, 0, 2);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0, 0, 3);		

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1, 0, 3);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0, 0, 2);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1, 0, 3);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1, 0, 2);

		//middle
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f, 0, 1);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.5f, 0, 2);		
		
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2.5f, 0, 2);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.5f, 0, 1);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2.5f, 0, 2);		

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.5f, 0, 1);

		//space between squares
		//space 1
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1, 0, 0.5f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1, 0, 1);	

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2, 0, 1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1, 0, 0.5f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2, 0, 1);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2, 0, 0.5f);		

		//space2
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1, 0, 2);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1, 0, 2.5f);		

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2, 0, 2.5f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1, 0, 2);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2, 0, 2.5f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2, 0, 2.0f);	
	glEnd();

	delete[] normal;
}
