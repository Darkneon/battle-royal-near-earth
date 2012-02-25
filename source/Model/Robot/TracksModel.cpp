#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/TracksModel.h"
#include "Robot/PhaserModel.h"
//#include "Material/MetalMaterial.h"

TracksModel::TracksModel()
{
    PhaserModel *child = new PhaserModel();
	setNextChild( (Model*)child );
	teamNumber = new TeamNumberModel();
    
    //material = (Material*)(new MetalMaterial());   
}

void TracksModel::render(){
	glPushMatrix();
		glTranslatef(0.1f, 0.0f, 0.2f);
		glScalef(0.4f,0.4f,0.4f);
		
		//track 1
		drawTrack();
		
		//track2
		glTranslatef(0,0,1);
		drawTrack();
		glTranslatef(0,0,-1);
	
	glPopMatrix();
    
    glTranslatef(0, 0.5f, 0);
}

void TracksModel::drawTrack(){
	GLUquadricObj *quadratic = gluNewQuadric();
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	glPushMatrix();
		//first track cylinder
		glColor3f(1.0f, 1.0f, 1.0f);
		glPushMatrix();
			glTranslatef(0.5f, 0.5f, 0.0f);
			gluCylinder(quadratic, 0.5, 0.5, 0.5, 15, 15);
			glTranslatef(-0.5f, -0.5f, 0.0f);
		glPopMatrix();

		//second track cylinder
		glPushMatrix();
			glTranslatef(1.5f, 0.5f, 0.0f);
			gluCylinder(quadratic, 0.5, 0.5, 0.5, 15, 15);
			glTranslatef(-1.5f, -0.5f, 0.0f);
		glPopMatrix();

		//rectangle
		glPushMatrix();
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.5f, 1.0f, 0.5f);
				glVertex3f(1.5f, 1.0f, 0.5f);			
				glVertex3f(1.5f, 1.0f, 0.0f);
				glVertex3f(0.5f, 1.0f, 0.0f);

				glNormal3f(0,-1,0);
				glVertex3f(0.5, 0, 0.5);
				glVertex3f(0.5, 0, 0);
				glVertex3f(1.5, 0, 0);
				glVertex3f(1.5, 0, 0.5);

			glEnd();
		glPopMatrix();

		glColor3f(0.0f, 0.0f, 1.0f);
		//circles and squares to finish model
		glPushMatrix();
			glRotatef(180, 0.0f,1.0f, 0.0f);
			glTranslatef(-2.0f, 0.0f, 0.0f);

			glTranslatef(0.5,0.5,0);
			gluDisk(quadratic,0,0.5,15,15);
			glTranslatef(-0.5,-0.5,0);

			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glVertex3f(0.5, 0, 0.0);
				glVertex3f(1.5, 0, 0.0);
				glVertex3f(1.5, 1, 0.0);
				glVertex3f(0.5, 1, 0.0);
			glEnd();

			glTranslatef(1.5,0.5,0);
			gluDisk(quadratic,0,0.5,15,15);
			glTranslatef(-1.5,-0.5,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.5,0.5,0.5);
			gluDisk(quadratic,0,0.5,15,15);
			glTranslatef(-0.5,-0.5,-0.5);

			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glVertex3f(0.5, 0, 0.5);
				glVertex3f(1.5, 0, 0.5);
				glVertex3f(1.5, 1, 0.5);
				glVertex3f(0.5, 1, 0.5);
			glEnd();

			glTranslatef(1.5,0.5,0.5);
			gluDisk(quadratic,0,0.5,15,15);
			glTranslatef(-1.5,-0.5,-0.5);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.5f,0.0f, 0.0f);
			glRotatef(180, 0.0f,1.0f, 0.0f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			teamNumber->render();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(.5f,0.0f, 0.5f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			teamNumber->render();
		glPopMatrix();

	glPopMatrix();
	gluDeleteQuadric(quadratic);
}