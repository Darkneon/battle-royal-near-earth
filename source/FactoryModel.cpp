/* 
 * File:   FactoryModel.cpp
 * Author: Addisson
 * 
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "FactoryModel.h"


FactoryModel::FactoryModel(void)
{}

/*
FactoryModel::~FactoryModel(void)
{}
*/
void FactoryModel::render() 
{
    glPushMatrix();
        drawFactory(0.0f, 0.0f, 0.0f);
    glPopMatrix();
}

//Uses the previous methods to draw a base
void FactoryModel::drawFactory(GLfloat xPos, GLfloat yPos, GLfloat zPos) 
{
	glScalef(0.0192f, 0.024f, 0.0192f);
	//First step
    GeoHelper::drawGarage(xPos, yPos, zPos);
    GeoHelper::drawGarage(xPos+50.0f, yPos, zPos);
    GeoHelper::drawGarage(xPos+100.0f, yPos, zPos);
    //Second step
    GeoHelper::drawMidBuildingFront(xPos, yPos, zPos+50);
    GeoHelper::drawMidBuildingFront(xPos+100, yPos, zPos+50);
}