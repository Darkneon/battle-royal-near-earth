#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "CubicSkybox.h"

CubicSkybox::CubicSkybox() {	
}

void CubicSkybox::render() 
{
    TextureManager::getInstance()->enableTexture();
	
	const GLfloat TOP = 20.0f;
	const GLfloat LEFT = -10.0f;
	const GLfloat RIGHT = 60.0f;
	const GLfloat BOTTOM = -20.0f;

	GLfloat* normal = new GLfloat[3];
	
	glColor3f(0.7f, 0.7f, 0.7f);

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, BOTTOM, 0.0f, RIGHT, BOTTOM, 0.0f, LEFT, TOP, 0.0f, normal);
		glNormal3fv(normal);

		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("moon.bmp"));

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, BOTTOM, 0.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, BOTTOM, 0.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, TOP, 0.0f);

		GeoHelper::findNormal3f(LEFT, TOP, 0.0f, RIGHT, BOTTOM, 0.0f, RIGHT, TOP, 0.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, TOP, 0.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, BOTTOM, 0.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, TOP, 0.0f);

		//=============================

		//glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, BOTTOM, 50.0f);
		glVertex3f(LEFT, TOP, 50.0f);
		glVertex3f(RIGHT, BOTTOM, 50.0f);
		
		glVertex3f(LEFT, TOP, 50.0f);
		glVertex3f(RIGHT, TOP, 50.0f);
		glVertex3f(RIGHT, BOTTOM, 50.0f);

		//==============================

		glVertex3f(0.0f, BOTTOM, 0.0f);
		glVertex3f(0.0f, TOP, 50.0f);
		glVertex3f(0.0f, BOTTOM, 50.0f);
		
		glVertex3f(0.0f, BOTTOM, 0.0f);
		glVertex3f(0.0f, TOP, 0.0f);
		glVertex3f(0.0f, TOP, 50.0f);

		//==================================

		glVertex3f(50.0f, BOTTOM, 0.0f);
		glVertex3f(50.0f, BOTTOM, 50.0f);
		glVertex3f(50.0f, TOP, 50.0f);
		
		glVertex3f(50.0f, BOTTOM, 0.0f);
		glVertex3f(50.0f, TOP, 50.0f);
		glVertex3f(50.0f, TOP, 0.0f);

		//==================================

		glVertex3f(50.0f, TOP, 50.0f);
		glVertex3f(0.0f, TOP, 50.0f);
		glVertex3f(0.0f, TOP, 0.0f);
		
		glVertex3f(50.0f, TOP, 50.0f);
		glVertex3f(0.0f, TOP, 0.0f);
		glVertex3f(50.0f, TOP, 0.0f);
	glEnd();
	

	delete [] normal;
}
