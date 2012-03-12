#include "GeoHelper.h"

void GeoHelper::drawTriangularPrism()
{
	glPushMatrix();
		glRotatef(-135.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(-0.5f, -0.25f, 0.5f);
		GLfloat* normal = new GLfloat[3];
		glBegin(GL_TRIANGLES); //side 1
			GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.0f, normal);
			glNormal3fv(normal);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
		glEnd();

		
		glBegin(GL_TRIANGLES); //side 2
			GeoHelper::findNormal3f(0.0f, 0.0f, -1.0f, 0.5f, 0.5f, -1.0f, 1.0f, 0.0f, -1.0f, normal);
			glNormal3fv(normal);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(0.5f, 0.5f, -1.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
		glEnd();

		glBegin(GL_TRIANGLES); //the "top left part"
			GeoHelper::findNormal3f(0.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, normal);
			glNormal3fv(normal);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES); //the "top right part"
			GeoHelper::findNormal3f(1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, normal);
			glNormal3fv(normal);
			glVertex3f(1.0f, 0.0f, -1.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();

		delete [] normal;

	glPopMatrix();
}

void GeoHelper::drawTrapezoidalPrism()
{
	glPushMatrix();
		glTranslatef(-0.5f, 0.25f, 0.0f);
		
		glPushMatrix();
			glTranslatef(0.05f, -0.24f, 0.0f);
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
	GLfloat* normal = new GLfloat[3];
	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(-1.0f, -0.5f,  1.0f, 1.0f, -0.5f,  1.0f, -1.0f,  0.5f,  1.0f, normal);
		glNormal3fv(normal);
		
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -0.5f,  1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);

		GeoHelper::findNormal3f(-1.0f,  0.5f,  1.0f, 1.0f, -0.5f,  1.0f, 1.0f,  0.5f,  1.0f, normal);
		glNormal3fv(normal);
		
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		
		GeoHelper::findNormal3f(1.0f,  0.5f,  1.0f, -1.0f,  0.5f, -1.0f, -1.0f,  0.5f,  1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		
		GeoHelper::findNormal3f(1.0f,  0.5f, 1.0f, 1.0f,  0.5f, -1.0f, -1.0f,  0.5f, -1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  0.5f, 1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 0.5f, -1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 0.5f, -1.0f);
		
		GeoHelper::findNormal3f(-1.0f,  -0.5f, 1.0f, -1.0f, -0.5f, -1.0f, 1.0f, -0.5f, 1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -0.5f, 1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -0.5f, 1.0f);

		GeoHelper::findNormal3f(-1.0f,  -0.5f, -1.0f, 1.0f, -0.5f, -1.0f, 1.0f, -0.5f, 1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,  -0.5f, -1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,  -0.5f, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  -0.5f, 1.0f);

		GeoHelper::findNormal3f(-1.0f,  -0.5f, -1.0f, -1.0f, 0.5f, -1.0f, 1.0f, -0.5f, -1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,  -0.5f, -1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,  -0.5f, -1.0f);

		GeoHelper::findNormal3f(-1.0f,  0.5f, -1.0f, 1.0f,  0.5f, -1.0f, 1.0f,  -0.5f, -1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  0.5f, -1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,  -0.5f, -1.0f);
	glEnd();

	
	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(1.0f, -0.5f, -1.0f, 1.0f,  0.5f, -1.0f, 1.0f,  0.5f,  1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,  0.5f, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);

		GeoHelper::findNormal3f(1.0f, -0.5f, -1.0f, 1.0f,  0.5f,  1.0f, 1.0f, -0.5f,  1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
	
		GeoHelper::findNormal3f(-1.0f,  0.5f,  1.0f, -1.0f,  0.5f, -1.0f, -1.0f, -0.5f, -1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		
		GeoHelper::findNormal3f(-1.0f, -0.5f,  1.0f, -1.0f,  0.5f,  1.0f, -1.0f, -0.5f, -1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -0.5f,  1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
	glEnd();

	delete [] normal;

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
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			for (int i = 0; i >= -degrees; i -= increment)
			{
				GLfloat angle = (GLfloat)i;
				glVertex3f(0.0f - sin(angle * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f - cos(angle * PI_TO_DEGREE_RATIO) * radius);
			}
		glEnd();
		
		glBegin(GL_POLYGON);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, height, 0.0f);
			for (int i = 0; i <= degrees; i += increment)
			{
				GLfloat angle = (GLfloat)i;
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, height, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
			}
		glEnd();
	
		glBegin(GL_TRIANGLES); // 2 triangles on the Z axis
			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, radius);
			glVertex3f(0.0f, height, -radius);
			glVertex3f(0.0f, 0.0f, -radius);

			glNormal3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, radius);
			glVertex3f(0.0f, height, radius);
			glVertex3f(0.0f, height, -radius);
		glEnd();

		GLfloat incementForTex = 1.0f / (degrees / increment);
		GLfloat currentTex = 0.0f;

		for (int i = 0; i < degrees; i += increment) //all the triangles along the perimeter
		{
			GLint angleNext = i + increment;
			GLfloat angle = (GLfloat)i;

			GLfloat x0 = sin(angle * PI_TO_DEGREE_RATIO) * radius;
			GLfloat x1 = sin(angleNext * PI_TO_DEGREE_RATIO) * radius;
			GLfloat z0 = cos(angle * PI_TO_DEGREE_RATIO) * radius;
			GLfloat z1 = cos(angleNext * PI_TO_DEGREE_RATIO) * radius;

			GLfloat* normal = new GLfloat[3];

			glBegin(GL_POLYGON);
				GeoHelper::findNormal3f(x1, 0.0f, z1, x0, height, z0, x0, 0.0f, z0, normal);
				glNormal3fv(normal);

				glTexCoord2f(currentTex + incementForTex, currentTex);
				glVertex3f(x1, 0.0f, z1);

				glTexCoord2f(currentTex, currentTex + incementForTex);
				glVertex3f(x0, height, z0);

				glTexCoord2f(currentTex, currentTex);
				glVertex3f(x0, 0.0f, z0);

				GeoHelper::findNormal3f(x1, 0.0f, z1, x1, height, z1, x0, height, z0, normal);
				glNormal3fv(normal);

				glTexCoord2f(currentTex + incementForTex, currentTex);
				glVertex3f(x1, 0.0f, z1);

				glTexCoord2f(currentTex + incementForTex, currentTex + incementForTex);
				glVertex3f(x1, height, z1);

				glTexCoord2f(currentTex, currentTex + incementForTex);
				glVertex3f(x0, height, z0);
			glEnd();


			currentTex += incementForTex;
			delete [] normal;
		}

	glPopMatrix();
}
void GeoHelper::drawAxis(GLfloat length)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glColor3f(1.0f, 0.0f, 0.0f); //X--RED 
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(length, 0.0f, 0.0f);
            glColor3f(0.0f, 1.0f, 0.0f); //Y--GREEN
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, length, 0.0f);
            glColor3f(0.0f, 0.0f, 1.0f); //Z--BLUE
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, length);
        glEnd();
    glPopMatrix();
}
void GeoHelper::drawCube(GLfloat xOrigin,GLfloat yOrigin, GLfloat zOrigin, GLfloat xExtend, GLfloat yExtend, GLfloat zExtend)
{
    glBegin(GL_TRIANGLES);
        //                  X     Y     Z
        // Square 1 -- ALONG THE X AXIS (BACK)
        glColor3f(0.5f, 0.5f, 0.5f);
        //Lower Triangle
        glNormal3f(0.0, 0.0, -1.0);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xExtend, yOrigin, zOrigin);
                
        //Upper Triangle
        glTexCoord2f(1.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
               
                
        // Square 2 -- ALONG THE Z AXIS (LEFT)
        glNormal3f(-1.0, 0.0, 0.0);
        //Lower Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin); 
        glTexCoord2f(1.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend); 
        glTexCoord2f(1.0f,0.0f); glVertex3f(xOrigin, yExtend, zExtend); 
        //Upper Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin); 
        glTexCoord2f(1.0f,0.0f); glVertex3f(xOrigin, yExtend, zExtend); 
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
                
        // Square 3 -- ALONG THE X AXIS, extended off Z (FRONT)
        glNormal3f(0.0, 0.0, 1.0); 
        //Lower Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend); //c
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend); //d
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);//b
        //Upper Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend);//c
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);//b
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zExtend);//a
                
        // Square 4 -- Along the X AND Z AXIS (RIGHT)
        glNormal3f(1.0, 0.0, 0.0);
        //Lower Triangle
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend);
                
        //Upper Triangle
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zOrigin);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);


        // Square 5 -- TOP OF CUBE
        glNormal3f(0.0, 1.0, 0.0);
        //Lower Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yExtend, zExtend);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yExtend, zExtend);
                
        //Upper Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yExtend, zExtend);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
                
        // Square 6 -- BOTTOM OF CUBE
        glNormal3f(0.0, -1.0, 0.0);
        //Lower Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend);
        //Upper Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yOrigin, zOrigin);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend);
	glEnd();
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
	GLfloat* normal = new GLfloat[3];
    glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(0.0f,  0.0f, 0.0f, 0.5f,  1.0f, 0.5f, 1.0f,  0.0f, 0.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);   
        glVertex3f(0.0f, 0.0f, 0.0f);

		glTexCoord2f(1.0f, 0.0f);   
		glVertex3f(0.5f, 1, 0.5f);

		glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(1.0f, 0.0f, 0.0f);
        
		GeoHelper::findNormal3f(1.0f,  0.0f, 0.0f, 0.5f,  1.0f, 0.5f, 1.0f,  0.0f, 1.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 0.0f);   
        glVertex3f(1.0f, 0.0f, 0.0f);

		glTexCoord2f(0.5f, 1.0f);   
		glVertex3f(0.5f, 1.0f, 0.5f);

		glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(1.0f, 0.0f, 1.0f);
        
		GeoHelper::findNormal3f(0.0f,  0.0f, 0.0f, 1.5f,  1.0f, 0.5f, 1.0f,  0.0f, 0.0f, normal);
		glNormal3fv(normal);
		
		glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(0.0f, 0.0f, 1.0f);

		glTexCoord2f(1.0f, 0.0f);   
		glVertex3f(1.0f, 0.0f, 1.0f);

		glTexCoord2f(0.5f, 1.0f);   
        glVertex3f(0.5f, 1.0f, 0.5f);
        
		GeoHelper::findNormal3f(0.0f,  0.0f, 0.0f, 0.5f,  1.0f, 0.5f, 1.0f,  0.0f, 0.0f, normal);
		glNormal3fv(normal);
		
		glTexCoord2f(0.0f, 0.0f);   
		glVertex3f(0.0f, 0.0f, 0.0f);

		glTexCoord2f(1.0f, 0.0f);   
        glVertex3f(0.0f, 0.0f, 1.0f);

		glTexCoord2f(0.5f, 1.0f);   
        glVertex3f(0.5f, 1.0f, 0.5f);
    glEnd();
	delete [] normal;
 }

void GeoHelper::findNormal3f(GLfloat* vector1, GLfloat* vector2, GLfloat* vector3, GLfloat* result)
{
	GLfloat usedVector1[3] = { vector1[0] - vector3[0], vector1[1] - vector3[1], vector1[2] - vector3[2] };
	GLfloat usedVector2[3] = { vector2[0] - vector3[0], vector2[1] - vector3[1], vector2[2] - vector3[2] };

	result[0] = usedVector1[1] * usedVector2[2] - usedVector2[1] * usedVector1[2];
	result[1] = -(usedVector1[0] * usedVector2[2] - usedVector2[0] * usedVector1[2]);
	result[2] = usedVector1[0] * usedVector2[1] - usedVector2[0] * usedVector1[1];       

}

 void GeoHelper::findNormal3f(GLfloat u1, GLfloat u2, GLfloat u3,
                                  GLfloat v1, GLfloat v2, GLfloat v3,
                                  GLfloat w1, GLfloat w2, GLfloat w3, GLfloat* result) {
     GLfloat u[3] = {u1, u2, u3};
     GLfloat v[3] = {v1, v2, v3};
     GLfloat w[3] = {w1, w2, w3};
     
     findNormal3f(u, v, w, result);     
 }
