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

BaseModel::BaseModel(){}

void BaseModel::render() 
{
	glPushMatrix();
	drawBase(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

//Uses the previous methods to draw a base
void BaseModel::drawBase(GLfloat xPos, GLfloat yPos, GLfloat zPos) 
{
	glTranslatef(0.0f,0.0f,0.3f);
    glScalef(0.012f, 0.015f, 0.012f); //scale enlarged x3 by Jeff
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
}