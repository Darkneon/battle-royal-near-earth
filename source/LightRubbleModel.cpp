#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "LightRubbleModel.h"

LightRubbleModel::LightRubbleModel(void)
{
}


void LightRubbleModel::render() {
	glPushMatrix();
		glTranslatef(0.15,0,0.2);
			drawRock();
		glTranslatef(-0.15, 0, -0.2);

		glTranslatef(0.8,0,0.8);
			drawBRock();
		glTranslatef(-0.8, 0, -0.8);

		glTranslatef(0.5,0,0.5);
			drawRock();
		glTranslatef(-0.5, 0, -0.5);

		glTranslatef(0.1,0,0.6);
			drawBRock();
		glTranslatef(-0.1, 0, -0.6);

		glTranslatef(0.75,0,0.32);
			drawRock();
		glTranslatef(-0.75, 0, -0.32);

		glTranslatef(0.72,0,0.15);
			drawBRock();
		glTranslatef(-0.72, 0, -0.15);

		glTranslatef(0.25,0,0.85);
			drawRock();
		glTranslatef(-0.25, 0, -0.85);

		glTranslatef(0.3,0,0.4);
			drawBRock();
		glTranslatef(-0.3, 0, -0.4);

		glTranslatef(0.65,0,0.7);
			drawRock();
		glTranslatef(-0.65, 0, -0.7);
	glPopMatrix();
}

void LightRubbleModel::drawRock() {
	glPushMatrix();
		glScalef(0.15,0.15,0.2);
        GLUquadric *quadratic=gluNewQuadric();
		gluSphere(quadratic,0.5,10,10);
	glPopMatrix();
}

void LightRubbleModel::drawBRock() {
	glPushMatrix();
		glScalef(0.25,0.2,0.3);
        GLUquadric *quadratic=gluNewQuadric();
		gluSphere(quadratic,0.5,10,10);
	glPopMatrix();
}