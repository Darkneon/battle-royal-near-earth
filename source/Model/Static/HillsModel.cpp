
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
			glColor3f(1.0f,1.0f,1.0f);
			glScalef(0.2f, 0.3f, 0.3f);
			GeoHelper::drawPeak();
		glPopMatrix();


		glPushMatrix();
			glColor3f(0.6f,0.6f,0.6f);
			glTranslatef(0.5f,0.0f,0.0f);
			glScalef(0.5f, 0.8f, 0.5f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f,1.0f,1.0f);
			glTranslatef(0.5f,0.0f,0.7f);
			glScalef(0.5f, 0.5f, 0.3f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.6f,0.6f,0.6f);
			glTranslatef(0.0f,0.0f,0.5f);
			glScalef(0.2f, 0.8f, 0.5f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f,1.0f,1.0f);
			glTranslatef(0.2f,0.0f,0.2f);
			glScalef(0.5f, 1.0f, 0.5f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8f,0.8f,0.8f);
			glTranslatef(0.0f,0.0f,0.3f);
			glScalef(0.2f, 0.4f, 0.3f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8f,0.8f,0.8f);
			glTranslatef(0.2f,0.0f,0.7f);
			glScalef(0.3f, 0.3f, 0.3f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8f,0.8f,0.8f);
			glTranslatef(0.2f,0.0f,0.0f);
			glScalef(0.3f, 0.6f, 0.3f);
			GeoHelper::drawPeak();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.8f,0.8f,0.8f);
			glTranslatef(0.7f,0.0f,0.5f);
			glScalef(0.3f, 0.4f, 0.3f);
			GeoHelper::drawPeak();
		glPopMatrix();
      
    glPopMatrix();
}
