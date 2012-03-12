#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "LightRubbleModel.h"
#include "GrassModel.h"
#include "Material/RockMaterial.h"

LightRubbleModel::LightRubbleModel(void)
{
	GrassModel* child = new GrassModel;
	setNextChild( (Model*)child );
    
    material = (Material*)(new RockMaterial());
}

void LightRubbleModel::render() {
	glColor3f(.7f,.7f,.7f);
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
		glTranslatef(0.15f,0.0f,0.2f);
			drawRock();
		glTranslatef(-0.15f, 0.0f, -0.2f);

		glTranslatef(0.8f,0.0f,0.8f);
			drawBRock();
		glTranslatef(-0.8f, 0.0f, -0.8f);

		glTranslatef(0.5f,0.0f,0.5f);
			drawRock();
		glTranslatef(-0.5f, 0.0f, -0.5f);

		glTranslatef(0.1f,0.0f,0.6f);
			drawBRock();
		glTranslatef(-0.1f, 0.0f, -0.6f);

		glTranslatef(0.75f,0.0f,0.32f);
			drawRock();
		glTranslatef(-0.75f, 0.0f, -0.32f);

		glTranslatef(0.72f,0.0f,0.15f);
			//glColor3f(1.0f,1.0f,1.0f);
			drawBRock();
		glTranslatef(-0.72f, 0.0f, -0.15f);

		glTranslatef(0.25f,0.0f,0.85f);
			drawRock();
		glTranslatef(-0.25f, 0.0f, -0.85f);

		glTranslatef(0.3f,0.0f,0.4f);
			drawBRock();
		glTranslatef(-0.3f, 0.0f, -0.4f);

		glTranslatef(0.65f,0.0f,0.7f);
			drawRock();
		glTranslatef(-0.65f, 0.0f, -0.7f);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void LightRubbleModel::drawRock() {
	glPushMatrix();
		glScalef(0.15f,0.15f,0.2f);
        GLUquadric *qRock=gluNewQuadric();
		gluQuadricNormals(qRock, GLU_SMOOTH);
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("rusted_zinc.bmp"));
		gluQuadricTexture(qRock,true);

		gluSphere(qRock,0.5,10,10);
		gluDeleteQuadric(qRock);
	glPopMatrix();
}

void LightRubbleModel::drawBRock() {
	glPushMatrix();
		glScalef(0.25f,0.2f,0.3f);
        GLUquadric *qBRock=gluNewQuadric();
		gluQuadricNormals(qBRock, GLU_SMOOTH);
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("rusted_zinc.bmp"));
		gluQuadricTexture(qBRock,true);

		gluSphere(qBRock,0.5,10,10);
		gluDeleteQuadric(qBRock);
	glPopMatrix();
	
}