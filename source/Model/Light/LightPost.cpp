
#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "LightPost.h"
#include "math.h"

// PI
#define GL_PI 3.14159f

LightPost::LightPost(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat lookX, GLfloat lookY, GLfloat lookZ){
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->lookX = lookX;
    this->lookY = lookY;
    this->lookZ = lookZ;
    lightPos[0] = this->posX;
    lightPos[1] = this->posY;
    lightPos[2] = this->posZ;
    lightPos[3] = 1.0f;
    spotDir[0] = this->lookX;
    spotDir[1] = this->lookY;
    spotDir[2] = this->lookZ;
}

GLfloat LightPost::getPosX()
{
    return posX;
}
GLfloat LightPost::getPosY()
{
    return posY;
}
GLfloat LightPost::getPosZ()
{
    return posZ;
}
void LightPost::setPosX(GLfloat x)
{
    posX = x;
}
void LightPost::setPosY(GLfloat Y)
{
    posY = Y;
}
void LightPost::setPosZ(GLfloat z)
{
    posZ = z;
}
void LightPost::updatePosition(GLfloat x, GLfloat y, GLfloat z)
{
    posX = x;
    posY = y;
    posZ = z;
    lightPos[0] = this->posX;
    lightPos[1] = this->posY;
    lightPos[2] = this->posZ;
    spotDir[0] = this->lookX;
    spotDir[1] = this->lookY;
    spotDir[2] = this->lookZ;
}

GLfloat LightPost::getLookX()
{
    return lookX;
}
GLfloat LightPost::getLookY()
{
    return lookY;
}
GLfloat LightPost::getLookZ()
{
    return lookZ;
}
GLfloat* LightPost::getPositionArray()
{
   return lightPos;
}
GLfloat* LightPost::getDirectionArray()
{
   return spotDir;
}
void LightPost::render() {
        glPushMatrix();
                glTranslatef(posX, posY, posZ);
                //Draw a cylinder at the camera position
                glColor3f(1.0f, 1.0f, 1.0f);
                        glLineWidth(5);
                        glBegin(GL_LINES);
                                glVertex3f(0, 0, 0);
                                glVertex3f(lookX, lookY, lookZ);
                        glEnd();
						glLineWidth(1);
                if (lookX > 0 )
                        glRotatef(acos(lookX/(sqrt((lookX*lookX)+(lookZ*lookZ))))*(180/GL_PI), 0, -1, 0);
                else if (lookX < 0 || lookZ < 0)
                        glRotatef(-acos(lookX/(sqrt((lookX*lookX)+(lookZ*lookZ))))*(180/GL_PI), 0, -1, 0);
                glRotatef(acos(lookY/(sqrt((lookX*lookX)+(lookY*lookY))))*(180/GL_PI), 0, 0, -1);      
                //glRotatef(66, 1, 0, 0);
                GeoHelper::drawAxis(5);
                glPushMatrix();
                glColor3f(0.0f, 0.0f, 1.0f);
                GeoHelper::drawCylinder(360);
                glPopMatrix();
        glPopMatrix();
}