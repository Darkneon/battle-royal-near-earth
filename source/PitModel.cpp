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

	geoHelper.drawCube(0,0,0,1,.2,1);
		glPushMatrix();
			glTranslatef(0,.2,0);
			geoHelper.drawCube(0,0,0,.2,.8,1);
			glTranslatef(0,-.2,0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(.8,.2,0);
			geoHelper.drawCube(0,0,0,.2,.8,1);
			glTranslatef(0,-.2,0);
		glPopMatrix();
	glPopMatrix();
}

void PitModel::drawPitOut()
{
	//Pit Outside
	glPushMatrix();
		geoHelper.drawCube(0,0,0,1,.2,1);
		glPushMatrix();
			glTranslatef(0,.2,0);
			geoHelper.drawCube(0,0,0,.2,.8,1);
			glTranslatef(0,-.2,0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(.8,.2,0);
			geoHelper.drawCube(0,0,0,.2,.8,1);
			glTranslatef(0,-.2,0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(.2,.2,0);
			geoHelper.drawCube(0,0,0,.6,.8,.2);
			glTranslatef(-.2,-.2,0);
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