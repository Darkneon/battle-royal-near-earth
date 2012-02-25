#include "GeoHelper.h"

void GeoHelper::drawTriangularPrism()
{
	glPushMatrix();
		glRotatef(-135.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(-0.5f, -0.25f, 0.5f);
		
		glBegin(GL_TRIANGLES); //base 1
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES); //base 2
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
			glVertex3f(0.5f, 0.5f, -1.0f);
		glEnd();

		glBegin(GL_TRIANGLES); //the "under part"
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
		glEnd();

		glBegin(GL_TRIANGLES); //the "top left part"
			glVertex3f(0.5f, 0.5f, 0.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			glVertex3f(0.5f, 0.5f, -1.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES); //the "top right part"
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			glVertex3f(0.5f, 0.5f, -1.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, -1.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
		glEnd();

	glPopMatrix();
}

void GeoHelper::drawTrapezoidalPrism()
{
	glPushMatrix();
		glTranslatef(-0.5f, 0.25f, 0.0f);
		
		glPushMatrix();
			glTranslatef(0.0f, -0.24f, 0.0f);
			glScalef(1.0f, 1.4f, 2.0f);
			drawTriangularPrism();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.0f, 0.0f, 0.0f);
			glScalef(0.8f, 1.0f, 1.0f);
			drawRectangle();
		glPopMatrix();
	glPopMatrix();
}

void GeoHelper::drawRectangle()
{
	//phaser base
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-1.0f, -0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		glVertex3f(-1.0f, -0.5f,  1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
	glEnd();
}

void GeoHelper::drawCylinder(GLint degrees)
{
	const GLfloat PI_TO_DEGREE_RATIO = 3.14159265f / 180;

	GLfloat radius = 1.0f;
	GLfloat height = 1.5f;
	GLint increment = 10;
	
	glPushMatrix();

		glTranslatef(-radius/2, -height/2, -radius/2);

		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.0f, 0.0f);
			for (int i = 0; i <= degrees; i += increment)
			{
				GLfloat angle = (GLfloat)i;
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
			}
		glEnd();
		
		glBegin(GL_POLYGON);
			glVertex3f(0.0f, height, 0.0f);
			for (int i = 0; i <= degrees; i += increment)
			{
				GLfloat angle = (float)i;
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, height, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
			}
		glEnd();
	
		glBegin(GL_TRIANGLES); // 2 triangles on the Z axis
			glVertex3f(0.0f, 0.0f, radius);
			glVertex3f(0.0f, height, -radius);
			glVertex3f(0.0f, 0.0f, -radius);
			glVertex3f(0.0f, 0.0f, radius);
			glVertex3f(0.0f, height, radius);
			glVertex3f(0.0f, height, -radius);
			glVertex3f(0.0f, height, radius);
		glEnd();

		/*
		glBegin(GL_TRIANGLES); // 2 triangles on X
			glVertex3f(radius, 0.0f, 0.0f);
			glVertex3f(0.0f, height, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(radius, 0.0f, 0.0f);
			glVertex3f(radius, height, 0.0f);
			glVertex3f(0.0f, height, 0.0f);
			glVertex3f(radius, height, 0.0f);
		glEnd();
		*/

		for (int i = 0; i < degrees; i += increment) //all the triangles along the perimeter
		{
			GLint angleNext = i + increment;
			GLfloat angle = (GLfloat)i;

			GLfloat x0 = sin(angle * PI_TO_DEGREE_RATIO) * radius;
			GLfloat x1 = sin(angleNext * PI_TO_DEGREE_RATIO) * radius;
			GLfloat z0 = cos(angle * PI_TO_DEGREE_RATIO) * radius;
			GLfloat z1 = cos(angleNext * PI_TO_DEGREE_RATIO) * radius;

			glBegin(GL_POLYGON);
				glVertex3f(x1, 0.0f, z1);
				glVertex3f(x0, height, z0);
				glVertex3f(x0, 0.0f, z0);
				glVertex3f(x1, 0.0f, z1);
				glVertex3f(x1, height, z1);
				glVertex3f(x0, height, z0);
				glVertex3f(x1, 0.0f, z1);
			glEnd();
		}

	glPopMatrix();
}
void GeoHelper::drawAxis(GLfloat length)
{
    glPushMatrix();
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); //X--RED 
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(length, 0.0f, 0.0f);
       // glColor3f(0.0f, 1.0f, 0.0f); //Y--GREEN
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, length, 0.0f);
       // glColor3f(0.0f, 0.0f, 1.0f); //Z--BLUE
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, length);
    glPopMatrix();
}
void GeoHelper::drawCube(GLfloat xOrigin,GLfloat yOrigin, GLfloat zOrigin, GLfloat xExtend, GLfloat yExtend, GLfloat zExtend)
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
                glColor3f(0.0f, 1.0f, 1.0f); // DARKER BLUE
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
                glColor3f(1.0f, 0.0f, 1.0f); //PURPLE
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
                glColor3f(1.0f, 0.0f, 0.0f); //RED
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
                glColor3f(1.0f, 1.0f, 0.0f); //YELLOW
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
                glColor3f(1.0f, 0.5f, 0.5f); //PINK
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

//Used to draw a middle smaller building
void GeoHelper::drawMidBuilding(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin)
{
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin+50, yOrigin+25, zOrigin+50);
    drawCube(xOrigin, yOrigin+25, zOrigin, xOrigin+5, yOrigin+30, zOrigin+50);
    drawCube(xOrigin+45, yOrigin+25, zOrigin, xOrigin+50, yOrigin+30, zOrigin+50);
}


//Draws the front of the smaller building
void GeoHelper::drawMidBuildingFront(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin)
{
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin+50, yOrigin+25, zOrigin+50);
    drawCube(xOrigin, yOrigin+25, zOrigin, xOrigin+5, yOrigin+30, zOrigin+50);
    drawCube(xOrigin+45, yOrigin+25, zOrigin, xOrigin+50, yOrigin+30, zOrigin+50);
    //Draw the roofing
    drawCube(xOrigin, yOrigin+25, zOrigin+45, xOrigin, yOrigin+30, zOrigin+50);
    drawCube(xOrigin, yOrigin+25, zOrigin+45, xOrigin+50, yOrigin+30, zOrigin+50);
}

//Used to draw a garage(Block with hole in it)
void GeoHelper::drawGarage(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin)
{
    drawCube(xOrigin, yOrigin + 15, zOrigin, xOrigin + 50, yOrigin + 50, zOrigin + 50);
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin + 16.66f, yOrigin + 20.0f, zOrigin + 50.0f);
    drawCube(xOrigin + 33.33f, yOrigin, zOrigin, xOrigin + 50.0f, yOrigin + 20.0f, zOrigin + 50.0f);
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin+50, yOrigin+50, zOrigin+20);
    //Draw the roofing
    drawCube(xOrigin, yOrigin+50, zOrigin+45, xOrigin, yOrigin+55, zOrigin+50);
    drawCube(xOrigin, yOrigin+50, zOrigin+45, xOrigin+50, yOrigin+55, zOrigin+50);
}

//Used to draw the peaks for the mountains and hills
 void GeoHelper::drawPeak() {
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 1, 0.5f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        
        glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 1.0f, 0.5f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        
        glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.5f, 1.0f, 0.5f);
        
		glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.5f, 1.0f, 0.5f);
    glEnd();
}


GLfloat* GeoHelper::findNormal3f(GLfloat* vector1, GLfloat* vector2, GLfloat* vector3)
{
	GLfloat usedVector1[3] = { vector1[0] - vector3[0], vector1[1] - vector3[1], vector1[2] - vector3[2] };
	GLfloat usedVector2[3] = { vector2[0] - vector3[0], vector2[1] - vector3[1], vector2[2] - vector3[2] };

	GLfloat* answerVector = new GLfloat[3];
	answerVector[0] = usedVector1[1] * usedVector2[2] - usedVector2[1] * usedVector1[2];
	answerVector[1] = -(usedVector1[0] * usedVector2[2] - usedVector2[0] * usedVector1[2]);
	answerVector[2] = usedVector1[0] * usedVector2[1] - usedVector2[0] * usedVector1[1];       
    
	return answerVector;
}

 GLfloat* GeoHelper::findNormal3f(GLfloat u1, GLfloat u2, GLfloat u3,
                                  GLfloat v1, GLfloat v2, GLfloat v3,
                                  GLfloat w1, GLfloat w2, GLfloat w3) {
     GLfloat u[3] = {u1, u2, u3};
     GLfloat v[3] = {v1, v2, v3};
     GLfloat w[3] = {w1, w2, w3};
     
     return findNormal3f(u, v, w);     
 }