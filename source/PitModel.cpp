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
	glTranslatef(.5,-.5,.5);
	glPushMatrix();
	drawBase(0.0f, 0.0f, 0.0f, 1.0f, 0.2f, 1.0f);
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

void PitModel::drawPitTop()
{
	GLUquadricObj *quadratic = gluNewQuadric();
	//Pit Outside
	glTranslatef(.5,-.5,.5);
	glPushMatrix();
		drawBase(0.0f, 0.0f, 0.0f, 1.0f, 0.2f, 1.0f);
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
	
		//curved inside
		glPushMatrix();
			glTranslatef(0.5f,1.0f,0.5f);
			glPushMatrix();
				glRotatef(90.0f, 1.0f,0.0f,0.0f);
				GLdouble coordinate[4] = {0,-1,0,0};
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					gluCylinder(quadratic, .33f, .33f, 1.0f, 6.0f,4.0f);
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
					gluDisk(quadratic,0.325f,0.5f,6.0f,3.0f);
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
	//Pit Outside
	glTranslatef(1.5,-.5,1.5);
	glRotatef(180,0,1,0);
	glPushMatrix();
		drawBase(0.0f, 0.0f, 0.0f, 1.0f, 0.2f, 1.0f);
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
		//curved inside
		glPushMatrix();
			glTranslatef(0.5f,1.0f,0.5f);
			glPushMatrix();
				glRotatef(90.0f, 1.0f,0.0f,0.0f);
				GLdouble coordinate[4] = {0,-1,0,0};
				glClipPlane(GL_CLIP_PLANE0, coordinate);
				glEnable(GL_CLIP_PLANE0);
					gluQuadricOrientation(quadratic, GLU_INSIDE);
					gluCylinder(quadratic, .33f, .33f, 1.0f, 6.0f,4.0f);
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
					gluDisk(quadratic,0.325f,0.5f,6.0f,3.0f);
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
		glTranslatef(-0.5f, -0.5f, -0.5f);
		if (pitType == 0)
			drawPitTop();
		else if (pitType == 1)	
			drawPitIn();
		else
			drawPitBottom();
	glPopMatrix();
}

void PitModel::drawBase(GLfloat xOrigin,GLfloat yOrigin, GLfloat zOrigin, GLfloat xExtend, GLfloat yExtend, GLfloat zExtend)
{
   // glPushMatrix();
    glBegin(GL_TRIANGLES);
        //                  X     Y     Z
        // Square 1 -- ALONG THE X AXIS
        glColor3f(0.0f, 1.0f, 1.0f);
                //Lower Triangle
                glColor3f(0.8f, 1.0f, 1.0f); // LIGHT BLUE
                glNormal3f(0.0, 0.0, -1.0);
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
        // Square 2 -- ALONG THE Z AXIS
               // glColor3f(0.0f, 1.0f, 1.0f); // DARKER BLUE
                glNormal3f(-1.0, 0.0, 0.0);
                 //Lower Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xOrigin, yOrigin, zExtend);
                glVertex3f(xOrigin, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xOrigin, yExtend, zExtend);
        // Square 3 -- ALONG THE X AXIS, extended off Z
               // glColor3f(1.0f, 0.0f, 1.0f); //PURPLE
                 glNormal3f(0.0, 0.0, 1.0);
                //Lower Triangle
                glVertex3f(xOrigin, yOrigin, zExtend);
                glVertex3f(xExtend, yOrigin, zExtend);
                glVertex3f(xExtend, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zExtend);
                glVertex3f(xOrigin, yExtend, zExtend);
                glVertex3f(xExtend, yExtend, zExtend);
        // Square 4 -- Along the X AND Z AXIS
               // glColor3f(1.0f, 0.0f, 0.0f); //RED
                glNormal3f(1.0, 0.0, 0.0);
                //Lower Triangle
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zExtend);
                glVertex3f(xExtend, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zExtend);
        // Square 5 -- TOP OF CUBE
                glColor3f(0.0f, 0.0f, 0.0f); //BROWN
                glNormal3f(0.0, 1.0, 0.0);
                //Lower Triangle
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zExtend);
                glVertex3f(xOrigin, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zExtend);
        // Square 6 -- BOTTOM OF CUBE
                //glColor3f(1.0f, 0.5f, 0.5f); //PINK
                 glNormal3f(0.0, -1.0, 0.0);
                //Lower Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zExtend);
                glVertex3f(xOrigin, yOrigin, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zExtend);
	glEnd();
        
      //  glPopMatrix;
}
/*
void PitModel::drawSide(GLfloat xOrigin,GLfloat yOrigin, GLfloat zOrigin, GLfloat xExtend, GLfloat yExtend, GLfloat zExtend)
{
   // glPushMatrix();
    glBegin(GL_TRIANGLES);
        //                  X     Y     Z
        // Square 1 -- ALONG THE X AXIS
        glColor3f(0.0f, 1.0f, 1.0f);
                //Lower Triangle
                glColor3f(0.8f, 1.0f, 1.0f); // LIGHT BLUE
                glNormal3f(0.0, 0.0, -1.0);
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
        // Square 2 -- ALONG THE Z AXIS
               // glColor3f(0.0f, 1.0f, 1.0f); // DARKER BLUE
                glNormal3f(-1.0, 0.0, 0.0);
                 //Lower Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xOrigin, yOrigin, zExtend);
                glVertex3f(xOrigin, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xOrigin, yExtend, zExtend);
        // Square 3 -- ALONG THE X AXIS, extended off Z
               // glColor3f(1.0f, 0.0f, 1.0f); //PURPLE
                 glNormal3f(0.0, 0.0, 1.0);
                //Lower Triangle
                glVertex3f(xOrigin, yOrigin, zExtend);
                glVertex3f(xExtend, yOrigin, zExtend);
                glVertex3f(xExtend, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zExtend);
                glVertex3f(xOrigin, yExtend, zExtend);
                glVertex3f(xExtend, yExtend, zExtend);
        // Square 4 -- Along the X AND Z AXIS
               // glColor3f(1.0f, 0.0f, 0.0f); //RED
                glNormal3f(1.0, 0.0, 0.0);
                //Lower Triangle
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zExtend);
                glVertex3f(xExtend, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zExtend);
        // Square 5 -- TOP OF CUBE
                glColor3f(.5f, .2f, 0.1f); //BROWN
                glNormal3f(0.0, 1.0, 0.0);
                //Lower Triangle
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zExtend);
                glVertex3f(xOrigin, yExtend, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zOrigin);
                glVertex3f(xExtend, yExtend, zExtend);
        // Square 6 -- BOTTOM OF CUBE
                //glColor3f(1.0f, 0.5f, 0.5f); //PINK
                 glNormal3f(0.0, -1.0, 0.0);
                //Lower Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zExtend);
                glVertex3f(xOrigin, yOrigin, zExtend);
                //Upper Triangle
                glVertex3f(xOrigin, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zOrigin);
                glVertex3f(xExtend, yOrigin, zExtend);
	glEnd();
        
      //  glPopMatrix;
}*/