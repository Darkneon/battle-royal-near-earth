#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "AntiGravModel.h"

AntiGravModel::AntiGravModel(void)
{
}


AntiGravModel::~AntiGravModel(void)
{
}

void AntiGravModel::render(){
	GLUquadricObj *quadratic = gluNewQuadric();

	glPushMatrix();
		//first machine block
		drawMachineCube();

		//second machine block
		glTranslatef(1.0f,0.0f,0.0f);
		drawMachineCube();
		glTranslatef(-1.0f,0.0f,0.0f);

		//third machine block
		glTranslatef(1.0f,0.0f,1.0f);
		drawMachineCube();
		glTranslatef(-1.0f,0.0f,-1.0f);

		//fourth machine block
		glTranslatef(0.0f,0.0f,1.0f);
		drawMachineCube();
		glTranslatef(0.0f,0.0f,-1.0f);

		//rectangle
		glTranslatef(0.0f,0.8f,0.0f);
		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glBegin(GL_QUADS);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glVertex3f(0.2f, 0.2f, 0.2f);
				glVertex3f(1.3f, 0.2f, 0.2f);
				glVertex3f(1.3f, 0.0f, 0.2f);

				glVertex3f(0.2f, 0.0f, 1.3f);
				glVertex3f(0.2f, 0.2f, 1.3f);
				glVertex3f(1.3f, 0.2f, 1.3f);
				glVertex3f(1.3f, 0.0f, 1.3f);
			glEnd();
	
			glBegin(GL_QUAD_STRIP);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glVertex3f(0.2f, 0.0f, 1.3f);
				glVertex3f(0.2f, 0.2f, 0.2f);
				glVertex3f(0.2f, 0.2f, 1.3f);

				glVertex3f(1.3f, 0.2f, 0.2f);
				glVertex3f(1.3f, 0.2f, 1.3f);

				glVertex3f(1.3f, 0.0f, 0.2f);
				glVertex3f(1.3f, 0.0f, 1.3f);

				glVertex3f(0.2f, 0.0f, 0.2f);
				glVertex3f(0.2f, 0.0f, 1.3f);
			glEnd();
		glPopMatrix();
		glTranslatef(0.0f,-0.8f,0.0f);

		//cylinder
		glColor3f(0.5f, 0.0f, 0.5f);
		glTranslatef(1.0f,0.8f,1.0f);
		glPushMatrix();
			glRotatef(45, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(quadratic, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-1.0f,-0.8f,-1.0f);

		glTranslatef(0.4f, 0.8f, 1.0f);
		glPushMatrix();
			glRotatef(-45, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(quadratic, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-0.4f,-0.8f,-1.0f);

		glTranslatef(1.0f, 0.8f, 0.5f);
		glPushMatrix();
			glRotatef(135, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(quadratic, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-1.0f,-0.8f,-0.5f);

		glTranslatef(0.5f,0.8f,0.5f);
		glPushMatrix();
			glRotatef(-135, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(quadratic, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-0.5f,-0.8f,-0.5f);

	glPopMatrix();

	gluDeleteQuadric(quadratic);
}

void AntiGravModel::drawMachineCube(){
	glPushMatrix();
		glPushMatrix();
			glColor3f(0, 0, 10);
			//first side
			drawRectangle();

			//second side
			glTranslatef(0.0f, 0.0f, 0.4f);
			drawRectangle();
			glTranslatef(0.0f, 0.0f, -0.4f);

			//third side
			glRotated(-90,0.0,1.0,0.0);
			drawRectangle();
			glRotated(90,0.0,1.0,0.0);

			//fourth side
			glRotated(-90,0.0,1.0,0.0);
			glTranslatef(0.0f,0.0f,-0.5f);
			drawRectangle();
			glTranslatef(0.0f,0.0f,0.5f);
			glRotated(90,0.0,1.0,0.0);
		glPopMatrix();

		//top
		glBegin(GL_QUADS);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.3f, 0.0f);
			glVertex3f(0.5f, 0.3f, 0.0f);
			glVertex3f(0.5f, 0.3f, 0.5f);
			glVertex3f(0.0f, 0.3f, 0.5f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.1f, 0.05f, 0.0f);
			glVertex3f(0.4f, 0.05f, 0.0f);
			glVertex3f(0.4f, 0.05f, 0.4f);
			glVertex3f(0.1f, 0.05f, 0.4f);
		glEnd();

	glPopMatrix();
}

void AntiGravModel::drawRectangle(){
	glPushMatrix();
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.3f, 0.0f);
			glVertex3f(0.5f, 0.3f, 0.0f);
			glVertex3f(0.5f, 0.0f, 0.0f);

			glVertex3f(0.0f, 0.0f, 0.1f);
			glVertex3f(0.0f, 0.3f, 0.1f);
			glVertex3f(0.5f, 0.3f, 0.1f);
			glVertex3f(0.5f, 0.0f, 0.1f);
		glEnd();
	
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.1f);
			glVertex3f(0.0f, 0.3f, 0.0f);
			glVertex3f(0.0f, 0.3f, 0.1f);

			glVertex3f(0.5f, 0.3f, 0.0f);
			glVertex3f(0.5f, 0.3f, 0.1f);

			glVertex3f(0.5f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.0f, 0.1f);

			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.1f);
		glEnd();
	glPopMatrix();
}
