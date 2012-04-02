/* 
 * File:   NuclearExplosion.h
 * Author: Jonathan
 *
 * Created on April 1st, 2012, 3:51 PM
 */

#include "NuclearExplosion.h"

NuclearExplosion::NuclearExplosion()
{
	nukeTime = clock();
	lightTime = clock();
	flyTime = clock();

	topRadius = 2;
	botSize = 0.5f;
	mushroomHeadSize = 1.0f;
	cylinderHeight = 0.0f;
	topStoppedGrowing = false;
	lightValue = 1.0f;
	lightIsEmitting = false;
	currentTime = clock();
}

void NuclearExplosion::render()
{
	TextureManager::getInstance()->enableTexture();
	
	GLUquadricObj *quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);

	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.0f);

	currentTime = clock();
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("nukeFire.bmp"));

	if ((currentTime - nukeTime) >= 200 && mushroomHeadSize <= 2.5f)
	{
		mushroomHeadSize += .25f;

		if (mushroomHeadSize == 2.5f)
		{
			topStoppedGrowing = true;
			lightIsEmitting = true;
		}
		
		nukeTime = clock();
	}


	if (lightIsEmitting) emitLight();

	if (lightIsEmitting && (currentTime - lightTime) >= 500)
	{
		
		lightValue -= 0.05f;
		lightTime = clock();
		if (lightValue == 0)
		{
			lightIsEmitting = false;
			glDisable(GL_LIGHT0);
		}
	}

	if (topStoppedGrowing && (currentTime - flyTime) >= 100)
	{
		if (cylinderHeight <= 8.0f)
		{
			cylinderHeight += 0.75f;
			botSize += 0.25f;
			flyTime = clock();
		}
		
	}


	glPushMatrix();
		glTranslatef(0.0f, cylinderHeight, 0.0f);
		glScalef(mushroomHeadSize, mushroomHeadSize, mushroomHeadSize);
		drawHalfASphere(quadric, topRadius);
	glPopMatrix();

	
	if (topStoppedGrowing)
	{
		glPushMatrix();
			glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
			gluCylinder(quadric, topRadius / 2.0f, topRadius / 2.0f, cylinderHeight, 8, 8);
		glPopMatrix();

		glPushMatrix();
			glScalef(botSize, botSize, botSize);
			drawHalfASphere(quadric, topRadius / 2);
		glPopMatrix();
	}

	glPopMatrix();

	gluDeleteQuadric(quadric);
	glDisable(GL_TEXTURE_2D);
}



void NuclearExplosion::emitLight()
{
	GLfloat light[] = {lightValue, 3.0f, 0.0f, 1.0f};
	
	glLightfv(GL_LIGHT0, GL_SPECULAR, light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light);
	glLightf(GL_LIGHT0, GL_SHININESS, 128.0f);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 255.0f);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 255.0f); 

	glEnable(GL_LIGHT0);
}

void NuclearExplosion::drawHalfASphere(GLUquadricObj* quadric, GLint radius)
{
	GLdouble coordinate[4] = {0,1,0,.15};
	glClipPlane(GL_CLIP_PLANE0, coordinate);
	glEnable(GL_CLIP_PLANE0);

	gluSphere(quadric, radius, 8, 8);
	
	glDisable(GL_CLIP_PLANE0);
}