
#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "HillsModel.h"

HillsModel::HillsModel(void)
{
}

void HillsModel::render() {
    glPushMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glScalef(0.2, 0.3, 0.3);
			drawPeak();
		glPopMatrix();


		glPushMatrix();
			glColor3f(0.6,0.6,0.6);
			glTranslatef(0.5,0,0);
			glScalef(0.5, 0.8, 0.5);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.5,0,0.7);
			glScalef(0.5, 0.5, 0.3);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.6,0.6,0.6);
			glTranslatef(0,0,0.5);
			glScalef(0.2, 0.8, 0.5);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(0.2,0,0.2);
			glScalef(0.5, 1, 0.5);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8,0.8,0.8);
			glTranslatef(0,0,0.3);
			glScalef(0.2, 0.4, 0.3);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8,0.8,0.8);
			glTranslatef(0.2,0,0.7);
			glScalef(0.3, 0.3, 0.3);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8,0.8,0.8);
			glTranslatef(0.2,0,0);
			glScalef(0.3, 0.6, 0.3);
			drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8,0.8,0.8);
			glTranslatef(0.7,0,0.5);
			glScalef(0.3, 0.4, 0.3);
			drawPeak();
		glPopMatrix();
      
    glPopMatrix();
}

void HillsModel::drawPeak() {
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0.5f, 1, 0.5f);
        
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
        glVertex3f(0.5f, 1, 0.5f);
        
        glVertex3f(1, 0, 1);
        glVertex3f(0, 0, 1);
        glVertex3f(0.5f, 1, 0.5f);
        
        glVertex3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0.5f, 1, 0.5f);        
    glEnd();
}
