#include "GeoHelper.h"
#include "Texture/TextureManager.h"
void GeoHelper::drawTriangularPrism()
{
	glPushMatrix();
		glRotatef(-135.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(-0.5f, -0.25f, 0.5f);
		GLfloat* normal = new GLfloat[3];

		//Side
		glBegin(GL_TRIANGLES);
			GeoHelper::findNormal3f(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.0f, normal);
			glNormal3fv(normal);

			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
		glEnd();

		//Other side
		glBegin(GL_TRIANGLES);
			GeoHelper::findNormal3f(0.0f, 0.0f, -1.0f, 0.5f, 0.5f, -1.0f, 1.0f, 0.0f, -1.0f, normal);
			glNormal3fv(normal);

			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);

			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5f, 0.5f, -1.0f);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);
		glEnd();

		//inclined left part
		glBegin(GL_TRIANGLES);
			GeoHelper::findNormal3f(0.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, normal);
			glNormal3fv(normal);

			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);

			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();

		//inclined right part
		glBegin(GL_TRIANGLES);
			GeoHelper::findNormal3f(1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, normal);
			glNormal3fv(normal);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, -1.0f);

			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glTexCoord2f(0.0f, 1.0f);
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
    GLfloat* normal = new GLfloat[3];
    glBegin(GL_TRIANGLES);
        //                  X     Y     Z
        // Square 1 -- ALONG THE X AXIS (BACK)
        glColor3f(0.5f, 0.5f, 0.5f);
        //Lower Triangle
        //glNormal3f(0.0, 0.0, -1.0);
        findNormal3f(xOrigin, yOrigin, zOrigin, xExtend, yExtend, zOrigin, xExtend, yOrigin, zOrigin, normal);
        glNormal3fv(normal);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xExtend, yOrigin, zOrigin);
                
        //Upper Triangle
        glTexCoord2f(1.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
               
                
        // Square 2 -- ALONG THE Z AXIS (LEFT)
        findNormal3f(xOrigin, yOrigin, zOrigin, xOrigin, yOrigin, zExtend, xOrigin, yExtend, zExtend, normal);
        glNormal3fv(normal);
        //Lower Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin); 
        glTexCoord2f(1.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend); 
        glTexCoord2f(1.0f,0.0f); glVertex3f(xOrigin, yExtend, zExtend); 
        //Upper Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zOrigin); 
        glTexCoord2f(1.0f,0.0f); glVertex3f(xOrigin, yExtend, zExtend); 
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
                
        // Square 3 -- ALONG THE X AXIS, extended off Z (FRONT)
        findNormal3f(xOrigin, yOrigin, zExtend, xExtend, yOrigin, zExtend, xExtend, yExtend, zExtend, normal);
        glNormal3fv(normal);
        //Lower Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend); //c
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend); //d
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);//b
        //Upper Triangle
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend);//c
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);//b
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zExtend);//a
                
        // Square 4 -- Along the X AND Z AXIS (RIGHT)
        findNormal3f(xExtend, yOrigin, zOrigin, xExtend, yExtend, zExtend, xExtend, yOrigin, zExtend, normal);
        glNormal3fv(normal);
        //Lower Triangle
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend);
                
        //Upper Triangle
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zOrigin);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
        glTexCoord2f(0.0f,0.0f); glVertex3f(xExtend, yExtend, zExtend);


        // Square 5 -- TOP OF CUBE
        findNormal3f(xOrigin, yExtend, zOrigin, xOrigin, yExtend, zExtend, xExtend, yExtend, zExtend, normal);
        glNormal3fv(normal);
        //Lower Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yExtend, zExtend);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yExtend, zExtend);
                
        //Upper Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yExtend, zOrigin);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yExtend, zExtend);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yExtend, zOrigin);
                
        // Square 6 -- BOTTOM OF CUBE
        findNormal3f(xOrigin, yOrigin, zOrigin, xExtend, yOrigin, zExtend, xOrigin, yOrigin, zExtend, normal);
        glNormal3fv(normal);
        //Lower Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend);
        glTexCoord2f(0.0f,1.0f); glVertex3f(xOrigin, yOrigin, zExtend);
        //Upper Triangle
        glTexCoord2f(0.0f,0.0f); glVertex3f(xOrigin, yOrigin, zOrigin);
        glTexCoord2f(1.0f,0.0f); glVertex3f(xExtend, yOrigin, zOrigin);
        glTexCoord2f(1.0f,1.0f); glVertex3f(xExtend, yOrigin, zExtend);
	glEnd();
        
        delete [] normal;
}

//Used to draw a middle smaller building
void GeoHelper::drawMidBuilding(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin)
{
    TextureManager::getInstance()->enableTexture();
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("camo.bmp"));
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin+50, yOrigin+25, zOrigin+50);
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metal1.bmp"));

    drawCube(xOrigin, yOrigin+25, zOrigin, xOrigin+5, yOrigin+30, zOrigin+50);
    drawCube(xOrigin+45, yOrigin+25, zOrigin, xOrigin+50, yOrigin+30, zOrigin+50);
    glDisable(GL_TEXTURE_2D);
}


//Draws the front of the smaller building
void GeoHelper::drawMidBuildingFront(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin)
{
    TextureManager::getInstance()->enableTexture();
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("camo.bmp"));
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin+50, yOrigin+25, zOrigin+50);
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metal1.bmp"));
    drawCube(xOrigin, yOrigin+25, zOrigin, xOrigin+5, yOrigin+30, zOrigin+50);
    drawCube(xOrigin+45, yOrigin+25, zOrigin, xOrigin+50, yOrigin+30, zOrigin+50);
    //Draw the roofing
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metal1.bmp"));
    drawCube(xOrigin, yOrigin+25, zOrigin+45, xOrigin, yOrigin+30, zOrigin+50);
    drawCube(xOrigin, yOrigin+25, zOrigin+45, xOrigin+50, yOrigin+30, zOrigin+50);
    glDisable(GL_TEXTURE_2D);
}

//Used to draw a garage(Block with hole in it)
void GeoHelper::drawGarage(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin)
{
    TextureManager::getInstance()->enableTexture();
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("camo.bmp"));
    drawCube(xOrigin, yOrigin + 15, zOrigin, xOrigin + 50, yOrigin + 50, zOrigin + 50);
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin + 16.66f, yOrigin + 20.0f, zOrigin + 50.0f);
    drawCube(xOrigin + 33.33f, yOrigin, zOrigin, xOrigin + 50.0f, yOrigin + 20.0f, zOrigin + 50.0f);
    drawCube(xOrigin, yOrigin, zOrigin, xOrigin+50, yOrigin+50, zOrigin+20);
    //Draw the roofing
    glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metal1.bmp"));
    drawCube(xOrigin, yOrigin+50, zOrigin+45, xOrigin, yOrigin+55, zOrigin+50);
    drawCube(xOrigin, yOrigin+50, zOrigin+45, xOrigin+50, yOrigin+55, zOrigin+50);
    glDisable(GL_TEXTURE_2D);
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
