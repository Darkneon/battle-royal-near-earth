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
   teamNumber2 = new TeamNumberModel();
   material = (Material*)(new MetalMaterial());
}

void BaseModel::render() 
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("camo.bmp"));
     //Draw number -- Addison
    glPushMatrix();
        //Draw Base
        drawBase(0.0f, 0.0f, 0.0f);
        drawBase(-300.0f, 0.0f, 0.0f);
        glTranslatef(1.75f, 1.15f, 2.2f);
        teamNumber->render();
        glTranslatef(-7.2f, 0, 0.0f);
        teamNumber2->render();
    glPopMatrix();
	glEnable(GL_TEXTURE_2D);
  
  
}

//Uses the previous methods to draw a base
void BaseModel::drawBase(GLfloat xPos, GLfloat yPos, GLfloat zPos) 
{
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.3f);
    glScalef(0.012f * 1.5f, 0.015f * 1.5f, 0.012f * 1.5f); //scale enlarged x3 by Jeff
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
}