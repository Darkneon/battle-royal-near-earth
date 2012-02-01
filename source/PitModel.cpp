/* 
 * File:   PitModel.cpp
 * Author: Jeffrey
 * 
 * Created on January 26, 2012, 8:59 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "PitModel.h"

PitModel::PitModel() 
{
	this->isEndingPit = true;
}

PitModel::PitModel(bool isEndingPit) 
{
	this->isEndingPit = isEndingPit;
}

void PitModel::switchPitType()
{
	isEndingPit = !isEndingPit;
}

void PitModel::drawPitIn()
{
	//Pit Outside
	glPushMatrix();

	GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 1.0f, 0.2f, 1.0f);
		glPushMatrix();
			glTranslatef(0.0f, 0.2f, 0.0f);
			GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.2f, 0.8f, 1.0f);
			glTranslatef(0.0f, -0.2f, 0.0f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.8f, 0.2f, 0.0f);
			GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.2f, 0.8f, 1.0f);
			glTranslatef(0.0f, -0.2f, 0.0f);
		glPopMatrix();
	glPopMatrix();
}

void PitModel::drawPitOut()
{
	//Pit Outside
	glPushMatrix();
		GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 1.0f, 0.2f, 1.0f);
		glPushMatrix();
			glTranslatef(0.0f, 0.2f, 0.0f);
			GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.2f, 0.8f, 1.0f);
			glTranslatef(0.0f, -0.2f, 0.0f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.8f, 0.2f, 0.0f);
			GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.2f, 0.8f, 1.0f);
			glTranslatef(0.0f, -0.2f, 0.0f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.2f, 0.2f, 0.0f);
			GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.6f, 0.8f, 0.2f);
			glTranslatef(-0.2f, -0.2f, 0.0f);
		glPopMatrix();
	glPopMatrix();
}

void PitModel::render() 
{
	glPushMatrix();
		glTranslatef(-0.5f, -0.5f, -0.5f);
		if (isEndingPit)
			drawPitOut();
		else	
			drawPitIn();
	glPopMatrix();
}