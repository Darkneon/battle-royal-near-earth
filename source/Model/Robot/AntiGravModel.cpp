#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/AntiGravModel.h"
#include "Robot/PhaserModel.h"
#include "Static/TeamNumberModel.h"
#include "Material/MetalMaterial.h"


AntiGravModel::AntiGravModel(void)
{
    PhaserModel *child = new PhaserModel();
	setNextChild( (Model*)child );
    
    material = (Material*)(new MetalMaterial());
}


void AntiGravModel::render(){
	GLUquadricObj *quadratic = gluNewQuadric();
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	glPushMatrix();
        glTranslatef(0.125f, 0.2f, 0.125f);
		glScalef(0.5f, 0.5f, 0.5f);
    
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
			glColor3f(0.4f, 0.4f, 0.4f);
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glVertex3f(0.2f, 0.2f, 0.2f);
				glVertex3f(1.3f, 0.2f, 0.2f);
				glVertex3f(1.3f, 0.0f, 0.2f);

				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(0.2f, 0.0f, 1.3f);
				glVertex3f(1.3f, 0.0f, 1.3f);
				glVertex3f(1.3f, 0.2f, 1.3f);
				glVertex3f(0.2f, 0.2f, 1.3f);
			glEnd();
	
			glBegin(GL_QUAD_STRIP);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glVertex3f(0.2f, 0.0f, 1.3f);
				glVertex3f(0.2f, 0.2f, 0.2f);
				glVertex3f(0.2f, 0.2f, 1.3f);

				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f(1.3f, 0.2f, 0.2f);
				glVertex3f(1.3f, 0.2f, 1.3f);

				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(1.3f, 0.0f, 0.2f);
				glVertex3f(1.3f, 0.0f, 1.3f);

				glNormal3f(0.0f, -1.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glVertex3f(0.2f, 0.0f, 1.3f);
			glEnd();
		glPopMatrix();
		glTranslatef(0.0f,-0.8f,0.0f);

		glPushMatrix();
			glTranslatef(0.3f,1.0f,1.2f);
			TeamNumberModel *teamNumber = new TeamNumberModel();
			teamNumber->render();
		glPopMatrix();

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

    glTranslatef(0, 0.7f, 0);
	gluDeleteQuadric(quadratic);
}

void AntiGravModel::drawMachineCube(){
	glPushMatrix();
		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glBegin(GL_QUAD_STRIP);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, 0.3f, 0.0f);
				glVertex3f(0.5f, 0.0f, 0.0f);
				glVertex3f(0.5f, 0.3f, 0.0f);

				glNormal3f(1.0f, 0.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, 0.5f);
				glVertex3f(0.5f, 0.3f, 0.5f);

				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(0.0f, 0.0f, 0.5f);
				glVertex3f(0.0f, 0.3f, 0.5f);

				glNormal3f(-1.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(0.0f, 0.3f, 0.0f);

			glEnd();
		glPopMatrix();

		//top
		glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.3f, 0.0f);
			glVertex3f(0.0f, 0.3f, 0.5f);
			glVertex3f(0.5f, 0.3f, 0.5f);
			glVertex3f(0.5f, 0.3f, 0.0f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.0f, 0.0f);
			glVertex3f(0.5f, 0.0f, 0.5f);
			glVertex3f(0.0f, 0.0f, 0.5f);
		glEnd();

	glPopMatrix();
}
