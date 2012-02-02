#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "TracksModel.h"
#include "PhaserModel.h"


TracksModel::TracksModel(void)
{
    PhaserModel *child = new PhaserModel();
	setNextChild( (Model*)child );
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
	glPushMatrix();
		//first track cylinder
		glColor3f(128, 128, 128);
		glPushMatrix();
			glTranslatef(0.5,0.5,0);
			gluCylinder(quadratic, 0.5, 0.5, 0.5, 15, 15);
			glTranslatef(-0.5,-0.5,0);
		glPopMatrix();

		//second track cylinder
		glPushMatrix();
			glTranslatef(1.5,0.5,0);
			gluCylinder(quadratic, 0.5, 0.5, 0.5, 15, 15);
			glTranslatef(-1.5,-0.5,0);
		glPopMatrix();

		//rectangle
		glPushMatrix();
			glBegin(GL_QUAD_STRIP);
				glVertex3f(0.5, 0, 0);
				glVertex3f(0.5, 0, 0.5);
				glVertex3f(0.5, 1, 0);
				glVertex3f(0.5, 1, 0.5);
				
				glVertex3f(1.5, 1, 0);
				glVertex3f(1.5, 1, 0.5);

				glVertex3f(1.5, 0, 0);
				glVertex3f(1.5, 0, 0.5);

				glVertex3f(0.5, 0, 0);
				glVertex3f(0.5, 0, 0.5);
			glEnd();
		glPopMatrix();

		glColor3f(0,0,50);
		//circles and squares to finish model
		glPushMatrix();
			glTranslatef(0.5,0.5,0);
			drawCircle(0.5);
			glTranslatef(-0.5,-0.5,0);

			glBegin(GL_QUADS);
				glVertex3f(0.5, 0, 0);
				glVertex3f(0.5, 1, 0);
				glVertex3f(1.5, 1, 0);
				glVertex3f(1.5, 0, 0);
			glEnd();

			glTranslatef(1.5,0.5,0);
			drawCircle(0.5);
			glTranslatef(-1.5,-0.5,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.5,0.5,0.5);
			drawCircle(0.5);
			glTranslatef(-0.5,-0.5,-0.5);

			glBegin(GL_QUADS);
				glVertex3f(0.5, 0, 0.5);
				glVertex3f(0.5, 1, 0.5);
				glVertex3f(1.5, 1, 0.5);
				glVertex3f(1.5, 0, 0.5);
			glEnd();

			glTranslatef(1.5,0.5,0.5);
			drawCircle(0.5);
			glTranslatef(-1.5,-0.5,-0.5);
		glPopMatrix();

	glPopMatrix();
	gluDeleteQuadric(quadratic);
}


//Code to draw a circle took from:
//http://steinsoft.net/index.php?site=Programming/Code%20Snippets/OpenGL/no5
void TracksModel::drawCircle(float radius)
{
	float DEG2RAD = 3.14159f/180;
	glBegin(GL_TRIANGLE_FAN);
 
	for (int i=0; i<360; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
	}
 
	glEnd();
}