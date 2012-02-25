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
	glScalef(.5,.5,.5);
    glTranslatef(4,2,0);
	glPushMatrix();
        glColor3f(1, 0, 0);
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
}

void FenceModel::drawBottom() {
    glBegin(GL_TRIANGLES);
        
        glNormal3fv( GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f) );  
        
        glVertex3f(0.0f, 0.0f ,0.0f);        
        glVertex3f(0.0f, 0.0f ,1.0f);
        glVertex3f(1.0f, 0.0f ,0.0f);
    
        glVertex3f(0.0f, 0.0f ,1.0f);
        glVertex3f(1.0f, 0.0f ,1.0f);
        glVertex3f(1.0f, 0.0f ,0.0f);        
    glEnd();
}

void FenceModel::drawSection() {
    glBegin(GL_TRIANGLES);    
        //bottom
        glNormal3fv( GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f) );
            
        glVertex3f(0, 0 ,0);
        glVertex3f(0, 0 ,1);
        glVertex3f(1, 0 ,0);
            
        glVertex3f(0, 0 ,1);
        glVertex3f(1, 0 ,1);
        glVertex3f(1, 0 ,0);        
        
        //top
        glNormal3fv( GeoHelper::findNormal3f(0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f) );
        
        glVertex3f(0, 1 ,0);
        glVertex3f(0, 1 ,1);
        glVertex3f(1, 1 ,0);
       
        glVertex3f(0, 1 ,1);
        glVertex3f(1, 1 ,1);
        glVertex3f(1, 1 ,0); 
        
        //side 1        
        glNormal3fv( GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f) );
        
        glVertex3f(0, 0 ,0);
        glVertex3f(0, 0 ,1);
        glVertex3f(0, 1 ,0);
        
    
        glVertex3f(0, 1 ,0);
        glVertex3f(0, 0 ,1);
        glVertex3f(0, 1 ,1);   
        
        //side 2
        glNormal3fv( GeoHelper::findNormal3f(1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f) );
        
        glVertex3f(1, 0 ,0);
        glVertex3f(1, 1 ,0);
        glVertex3f(1, 0 ,1);
                    
        glVertex3f(1, 0 ,1);
        glVertex3f(1, 1 ,0);
        glVertex3f(1, 1 ,1);        
            
        //front
        glNormal3fv( GeoHelper::findNormal3f(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f) );
        
        glVertex3f(0, 0 ,1);
        glVertex3f(1, 0 ,1);
        glVertex3f(0, 1 ,1);
    
        glVertex3f(0, 1 ,1);
        glVertex3f(1, 0 ,1);
        glVertex3f(1, 1 ,1);    

        //back
        //ToDo
//        glNormal3fv( GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f) );
        glNormal3f(0.0f, 0.0f, 1.0f);
        
        glVertex3f(0, 0 ,0);        
        glVertex3f(0, 1 ,0);
        glVertex3f(1, 0 ,0);
    
        glVertex3f(1, 0 ,0);
        glVertex3f(0, 1 ,0);     
        glVertex3f(1, 1 ,0);          
    glEnd();    
}


