/* 
 * File:   BulletModel.cpp
 * Author: Jeffrey
 * Created on March 30, 2012
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "BulletModel.h"
#include "Material/MetalMaterial.h"

BulletModel::BulletModel(void)
{
	material = (Material*)(new MetalMaterial());
}

BulletModel::~BulletModel(void)
{
}

void BulletModel::render(){
	GLUquadricObj *quadratic = gluNewQuadric();		
	glPushMatrix();
		glColor3f(0.0f,0.0f,1.0f);
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("metal4.bmp"));	
		gluQuadricTexture(quadratic,true);	
		gluSphere(quadratic, BULLET_RADIUS, 10,10);
		glColor3f(0.5f,0.5f,0.5f);
	glPopMatrix();
	gluDeleteQuadric(quadratic);
}