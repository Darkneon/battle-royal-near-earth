#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/TracksModel.h"
#include "Robot/PhaserModel.h"

TracksModel::TracksModel(void)
{
    PhaserModel *child = new PhaserModel();
	setNextChild( (Model*)child );
	teamNumber = new TeamNumberModel();
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
			GeoHelper::drawCircle(0.5);
			glTranslatef(-0.5,-0.5,0);

			glBegin(GL_QUADS);
				glVertex3f(0.5, 0, 0);
				glVertex3f(0.5, 1, 0);
				glVertex3f(1.5, 1, 0);
				glVertex3f(1.5, 0, 0);
			glEnd();

			glTranslatef(1.5,0.5,0);
			GeoHelper::drawCircle(0.5);
			glTranslatef(-1.5,-0.5,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.5,0.5,0.5);
			GeoHelper::drawCircle(0.5);
			glTranslatef(-0.5,-0.5,-0.5);

			glBegin(GL_QUADS);
				glVertex3f(0.5, 0, 0.5);
				glVertex3f(0.5, 1, 0.5);
				glVertex3f(1.5, 1, 0.5);
				glVertex3f(1.5, 0, 0.5);
			glEnd();

			glTranslatef(1.5,0.5,0.5);
			GeoHelper::drawCircle(0.5);
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