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

#include "Static/PitModel.h"

PitModel::PitModel() 
{
	this->pitType = 0;
}

PitModel::PitModel(bool isEndingPit) 
{
	this->pitType = 0;
}

void PitModel::switchPitType()
{
	pitType += 1;
	if(pitType == 3){
		pitType = 0;
	}
}

void PitModel::drawPitIn()
{
	//Pit Inside
	glPushMatrix();
		GLfloat black[3] = {0.0f, 0.0f, 0.0f}; //How do I delete????
		GLfloat brown[3] = {0.7f, 0.3f, 0.0f};
		GLfloat dbrown[3] = {0.6f, 0.2f, 0.0f};
		//Base
		glPushMatrix();
			glScalef(1.0f, 0.2f, 1.0f);
			drawColoredCube(black, black, black, black, black, black);
		glPopMatrix();
		//Left Side
		glPushMatrix();
			glTranslatef(0.0f,0.2f,0.0f);
			glScalef(0.2f,0.8f,1.0f);
			drawColoredCube(brown, black, black, dbrown, black, black);
		glPopMatrix();
		//Right Side
		glPushMatrix();
			glTranslatef(0.8f,0.2f,0.0f);
			glScalef(0.2f,0.8f,1.0f);
			drawColoredCube(brown, black, dbrown, black, black, black);
		glPopMatrix();
	glPopMatrix();
}

void PitModel::drawPitTop()
{
	GLUquadricObj *quadratic = gluNewQuadric();
	GLfloat black[3] = {0.0f, 0.0f, 0.0f}; //How do I delete????
	GLfloat brown[3] = {0.7f, 0.3f, 0.0f};
	GLfloat dbrown[3] = {0.6f, 0.2f, 0.0f};

	glPushMatrix();
		//Base
		glPushMatrix();
			glScalef(1.0f, 0.2f, 1.0f);
			drawColoredCube(black, black, black, black, black, black);
		glPopMatrix();
		//Left Side
		glPushMatrix();
			glTranslatef(0.0f,0.2f,0.0f);
			glScalef(0.2f,0.8f,1.0f);
			drawColoredCube(brown, black, black, dbrown, black, black);
		glPopMatrix();
		//Right Side
		glPushMatrix();
			glTranslatef(0.8f,0.2f,0.0f);
			glScalef(0.2f,0.8f,1.0f);
			drawColoredCube(brown, black, dbrown, black, black, black);
		glPopMatrix();
		//Far Side
		glPushMatrix();
			glTranslatef(0.2f,0.2f,0.0f);
			glScalef(0.6f,0.8f,0.2f);
			drawColoredCube(brown, black, black, black, dbrown, black);
		glPopMatrix();

		//curved inside
		glPushMatrix();
			glTranslatef(0.5f,1.0f,0.5f);
			glPushMatrix();
				glRotatef(90.0f, 1.0f,0.0f,0.0f);
				GLdouble coordinate[4] = {0.0, -1.0, 0.0, 0.0};
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					glColor3fv(dbrown);
					gluCylinder(quadratic, .33, .33, 1.0, 6, 4);
					gluQuadricOrientation(quadratic, GLU_OUTSIDE);
				glDisable(GL_CLIP_PLANE0);
				glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.5f, 1.0f, 0.5f);
			glPushMatrix();
				glRotatef(90.0f,1.0f,0.0f,0.0f);
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					glColor3fv(brown);
					gluDisk(quadratic, 0.325, 0.5, 6, 3);
					gluQuadricOrientation(quadratic, GLU_OUTSIDE);
				glDisable(GL_CLIP_PLANE0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(quadratic);
}

void PitModel::drawPitBottom()
{
	GLUquadricObj *quadratic = gluNewQuadric();
	GLfloat black[3] = {0.0f, 0.0f, 0.0f}; //How do I delete????
	GLfloat brown[3] = {0.7f, 0.3f, 0.0f};
	GLfloat dbrown[3] = {0.6f, 0.2f, 0.0f};

	glPushMatrix();
		glTranslatef(1.0f,0.0f,1.0f);
		glRotatef(180,0,1,0);
		//Base
		glPushMatrix();
			glScalef(1.0f, 0.2f, 1.0f);
			drawColoredCube(black, black, black, black, black, black);
		glPopMatrix();
		//Left Side
		glPushMatrix();
			glTranslatef(0.0f,0.2f,0.0f);
			glScalef(0.2f,0.8f,1.0f);
			drawColoredCube(brown, black, black, dbrown, black, black);
		glPopMatrix();
		//Right Side
		glPushMatrix();
			glTranslatef(0.8f,0.2f,0.0f);
			glScalef(0.2f,0.8f,1.0f);
			drawColoredCube(brown, black, dbrown, black, black, black);
		glPopMatrix();
		//Far Side
		glPushMatrix();
			glTranslatef(0.2f,0.2f,0.0f);
			glScalef(0.6f,0.8f,0.2f);
			drawColoredCube(brown, black, black, black, dbrown, black);
		glPopMatrix();

		//curved inside
		glPushMatrix();
			glTranslatef(0.5f,1.0f,0.5f);
			glPushMatrix();
				glRotatef(90.0f, 1.0f,0.0f,0.0f);
				GLdouble coordinate[4] = {0.0, -1.0, 0.0, 0.0};
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					glColor3fv(dbrown);
					gluCylinder(quadratic, .33, .33, 1.0, 6, 4);
					gluQuadricOrientation(quadratic, GLU_OUTSIDE);
				glDisable(GL_CLIP_PLANE0);
				glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.5f, 1.0f, 0.5f);
			glPushMatrix();
				glRotatef(90.0f,1.0f,0.0f,0.0f);
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					glColor3fv(brown);
					gluDisk(quadratic, 0.325, 0.5, 6, 3);
					gluQuadricOrientation(quadratic, GLU_OUTSIDE);
				glDisable(GL_CLIP_PLANE0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(quadratic);
}

void PitModel::render() 
{
	glPushMatrix();
		glTranslatef(0.0f, -1.0f, 0.0f);
		if (pitType == 0)
			drawPitTop();
		else if (pitType == 1)	
			drawPitIn();
		else
			drawPitBottom();
	glPopMatrix();
}

void PitModel::drawSquare(){
	glPushMatrix();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(0.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);

			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,0.0f);
		glEnd();
	glPopMatrix();
}

void PitModel::drawColoredCube(GLfloat* tColor, GLfloat* bColor, GLfloat* lColor, GLfloat* rColor, GLfloat* nColor, GLfloat* fColor){
	glPushMatrix();
		//bottom
		glPushMatrix();
			glColor3fv(bColor);
			drawSquare();
		glPopMatrix();
		//top
		glPushMatrix();
			glColor3fv(tColor);
			glTranslatef(0.0f,1.0f,0.0f);
			drawSquare();
		glPopMatrix();
		//left
		glPushMatrix();
			glColor3fv(lColor);
			glRotatef(90.f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//right
		glPushMatrix();
			glColor3fv(rColor);
			glTranslatef(1.0f, 1.0f, 0.0f);
			glRotatef(-90.f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//near
		glPushMatrix();
			glColor3fv(nColor);
			glRotatef(-90.f, 1.0f,0.0f,0.0f);
			drawSquare();
		glPopMatrix();
		//far
		glPushMatrix();
			glColor3fv(nColor);
			glTranslatef(0.0f,1.0f,1.0f);
			glRotatef(90.f, 1.0f,0.0f,0.0f);
			drawSquare();
		glPopMatrix();
	glPopMatrix();
}