
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

	rot = 0.0f;
	axis[0] = 1.0f;
	axis[1] = 0.0f;
	axis[2] = 0.0f;
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
void LightPost::setLookX(GLfloat x)
{
    lookX = x;
}
void LightPost::setLookY(GLfloat y)
{
    lookY = y;
}
void LightPost::setLookZ(GLfloat z)
{
    lookZ = z;
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
void LightPost::drawHeadLamp()
{
    glPushMatrix();
    glTranslatef(posX, posY, posZ); //Position to the source of the light
    rotateLamp();
        glPushMatrix();
                GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.2f, -6.0f, 0.2f); //Draw the lamppost
                glRotatef(45, -1, 0, 1); //Rotate 45 degrees
                glColor3f(0.0f, 0.0f, 1.0f);
                glTranslatef(-0.0f, -0.5f, 0.0f);
            GeoHelper::drawCube(-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f); //Draw the head of the lamp
            GeoHelper::drawCube(-0.2f, -0.2f, -0.2f, 1.2f, 1.2f, 1.2f);
            //Lightbulb 1
            glPushMatrix();
                glColor3f(1.0f, 1.0f, 1.0f);
                glTranslatef(0.0f, -0.5f, 0.0f);
                glutSolidSphere(0.25, 10, 10);
            glPopMatrix();
            //Lightbulb 2
            glPushMatrix();
                glTranslatef(0.6f, -0.5f, 0.0f);
                glutSolidSphere(0.25, 10, 10);
            glPopMatrix();
            //Lightbulb 3
            glPushMatrix();
                glTranslatef(0.6f, -0.5f, 0.5f);
                glutSolidSphere(0.25, 10, 10);
            glPopMatrix();
            //Lightbulb 4
            glPushMatrix();
                glTranslatef(0.0f, -0.5f, 0.5f);
                glutSolidSphere(0.25, 10, 10);
            glPopMatrix();//Lightbulb 3
            glPushMatrix();
                glTranslatef(0.6f, -0.5f, 0.5f);
                glutSolidSphere(0.25, 10, 10);
            glPopMatrix();
        glPopMatrix();
     glPopMatrix();

}
void LightPost::rotateLamp()
{
    if (lookX < 0 && lookZ > 0)
        glRotatef(90, 0, -1, 0);
    else if (lookX < 0 && lookZ < 0)
        glRotatef(180, 0, 1, 0);
    else if (lookX > 0 && lookZ < 0)
        glRotatef(90, 0, 1, 0);
}
void LightPost::render() 
{
   glPushMatrix();
   drawHeadLamp();
   glPopMatrix();
}