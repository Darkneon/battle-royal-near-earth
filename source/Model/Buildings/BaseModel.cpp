/* 
 * File:   BaseModel.cpp
 * Author: Addisson
 * 
 * Created on January 31, 2012, 11:29 AM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>

#include "Model.h"
#include "BaseModel.h"
#include "Material/MetalMaterial.h"


BaseModel::BaseModel()
{
   teamNumber = new TeamNumberModel();
   material = (Material*)(new MetalMaterial());
   //flag = new FlagModel();
   
   //box->resize(5.0f,1.25f,4.0f);
}

void BaseModel::render() 
{
     //Draw number -- Addison
    glPushMatrix();
        //Draw Base
		glTranslatef(0.0f,0.0f,0.05f);
        drawBase(0.0f, 0.0f, 0.0f);
        glPushMatrix();
			glTranslatef(2.0f, 1.23f, 2.2f);
			teamNumber->render();
		glPopMatrix();
        glPopMatrix();
	glPushMatrix();
		renderGrass();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
        //Draw the flag
       /* glPushMatrix();
                glTranslatef(0.5, 3.0, 1.75);
                flag->render();
        glPopMatrix();
        */
  
}

//Uses the previous methods to draw a base
void BaseModel::drawBase(GLfloat xPos, GLfloat yPos, GLfloat zPos) 
{
    glPushMatrix();
    glTranslatef(0.025f,0.0f,0.475f);
    glScalef(0.012f * 1.65f, 0.015f * 1.65f, 0.012f * 1.65f); //scale enlarged x3 by Jeff
    //Start Drawing the buildings
    //First step
    GeoHelper::drawGarage(xPos+0.0f, yPos+0.0f, zPos+0.0f);
    GeoHelper::drawGarage(xPos+0.0f, yPos+0.0f, zPos+50.0f);
    //Second step
    GeoHelper::drawGarage(xPos+50.0f, yPos+0.0f, zPos-25.0f);
    GeoHelper::drawMidBuilding(xPos+50.0f, yPos+0.0f, zPos+25.0f);
    GeoHelper::drawMidBuilding(xPos+50.0f, yPos+0.0f, zPos+75.0f);
    GeoHelper::drawMidBuildingFront(xPos+50.0f, yPos+0.0f, zPos+125.0f);
    //Third step
    GeoHelper::drawGarage(xPos+100.0f, yPos+0.0f, zPos+0.0f);
    GeoHelper::drawGarage(xPos+100.0f, yPos+0.0f, zPos+50.0f);
    GeoHelper::drawMidBuildingFront(xPos+100.0f, yPos+0.0f, zPos+100.0f);
    //Forth step
    GeoHelper::drawGarage(xPos+150.0f, yPos+0.0f, zPos-25.0f);
    GeoHelper::drawMidBuilding(xPos+150.0f, yPos+0.0f, zPos+25.0f);
    GeoHelper::drawMidBuilding(xPos+150.0f, yPos+0.0f, zPos+75.0f);
    GeoHelper::drawMidBuildingFront(xPos+150.0f, yPos+0.0f, zPos+125.0f);
    //Fifth step
    GeoHelper::drawGarage(xPos+200.0f, yPos+0.0f, zPos+0.0f);
    GeoHelper::drawGarage(xPos+200.0f, yPos+0.0f, zPos+50.0f);
    glPopMatrix();
    //draw flag
    

}


void BaseModel::renderGrass() {

	glTranslatef(0,0,1);

	glColor3f(0.8f, 0.8f, 0.8f);
	TextureManager::getInstance()->enableTexture();
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
	glDisable(GL_TEXTURE_2D);
}