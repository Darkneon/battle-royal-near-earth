#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "BipodModel.h"
#include "TeamNumberModel.h"

BipodModel::BipodModel(void)
{
}


BipodModel::~BipodModel(void)
{
}

void BipodModel::render(){
	glPushMatrix();
		//first leg
		drawLeg();

		//second leg
		glTranslatef(0.0f, 0.0f, 1.0f);
		drawLeg();
		glTranslatef(0.0f, 0.0f, -1.0f);


		glTranslatef(0.f, 1.3f, 0.f);
		//rectangle
		glPushMatrix();
			glColor3f(0.5f, 0.0f, 0.5f);
			glBegin(GL_QUADS);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, 0.2f, 0.0f);
				glVertex3f(1.0f, 0.2f, 0.0f);
				glVertex3f(1.0f, 0.0f, 0.0f);

				glVertex3f(0.0f, 0.0f, 1.5f);
				glVertex3f(0.0f, 0.2f, 1.5f);
				glVertex3f(1.0f, 0.2f, 1.5f);
				glVertex3f(1.0f, 0.0f, 1.5f);
			glEnd();
	
			glBegin(GL_QUAD_STRIP);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 1.5f);
				glVertex3f(0.0f, 0.2f, 0.0f);
				glVertex3f(0.0f, 0.2f, 1.5f);

				glVertex3f(1.0f, 0.2f, 0.0f);
				glVertex3f(1.0f, 0.2f, 1.5f);

				glVertex3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.0f, 0.0f, 1.5f);

				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 1.5f);
			glEnd();
		glPopMatrix();
		glTranslatef(0.0f,-1.3f,0.0f);

	glPopMatrix();
}

void BipodModel::drawLeg(){
	GLUquadricObj *quadratic = gluNewQuadric();
	glPushMatrix();
		glTranslatef(0.25f,0.4f,0.25f);
		glPushMatrix();
			//thigh
			glColor3f(0.0f, 0.0f, 2.0f);
			glTranslatef(0.0f,1.0f,0.0f);
			glPushMatrix();
				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glRotatef(45, 1.0f, 0.0f, 0.0f);
				gluCylinder(quadratic, 0.1, 0.1, 0.6, 15, 15);
			glPopMatrix();
			glTranslatef(0.0f,-1.0f,0.0f);

			//leg
			glPushMatrix();
				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glRotatef(-45, 1.0f, 0.0f, 0.0f);
				gluCylinder(quadratic, 0.1, 0.1, 0.6, 15, 15);
			glPopMatrix();

			//knee
			glTranslatef(0.45f, 0.5f, 0.0f);
			glPushMatrix();
				glColor3f(1.0f, 1.0f, 1.0f);
				gluSphere(quadratic,0.15,15,15);
			glPopMatrix();
			glTranslatef(-0.45f, -0.5f, 0.0f);
		glPopMatrix();
		glTranslatef(-0.25f,-0.4f,-0.25f);


		//feet
		glPushMatrix();
			glScalef(.5f,.5f,.5f);
			glRotatef(-90, 0.0f,1.0f, 0.0f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			TeamNumberModel *teamNumber = new TeamNumberModel();
			teamNumber->render();
		glPopMatrix();

		glColor3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.5f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glVertex3f(0.0f, 0.0f, 0.5f);
			glVertex3f(0.0f, 0.5f, 0.5f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glVertex3f(1.0f, 0.0f, 0.5f);
		glEnd();

		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.5f);
			glVertex3f(0.0f, 0.5f, 0.0f);
			glVertex3f(0.0f, 0.5f, 0.5f);

			glVertex3f(0.5f, 0.5f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.5f);

			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.5f);

			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.5f);
		glEnd();
	glPopMatrix();
	gluDeleteQuadric(quadratic);
}