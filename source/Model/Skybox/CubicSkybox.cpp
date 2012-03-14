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
	const GLfloat BOTTOM = -5.0f;

	GLfloat* normal = new GLfloat[3];
	
	glColor3f(0.7f, 0.7f, 0.7f);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("moon.bmp"));
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("moon.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(-10.0f, -5.0f, 0.0f, 60.0f, -5.0f, 0.0f, -10.0f, 20.0f, 0.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-10.0f, -5.0f, -10.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(60.0f, -5.0f, -10.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-10.0f, 20.0f, -10.0f);

		GeoHelper::findNormal3f(-10.0f, 20.0f, 0.0f, 60.0f, -5.0f, 60.0f, 60.0f, 20.0f, 0.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-10.0f, 20.0f, -10.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(60.0f, -5.0f, -10.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(60.0f, 20.0f, -10.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("sun.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(-10.0f, -5.0f, 60.0f, -10.0f, 20.0f, 60.0f, 60.0f, -5.0f, 60.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-10.0f, -5.0f, 60.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-10.0f, 20.0f, 60.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(60.0f, -5.0f, 60.0f);
		
		GeoHelper::findNormal3f(-10.0f, 20.0f, 60.0f, 60.0f, 20.0f, 60.0f, 60.0f, -5.0f, 60.0f, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-10.0f, 20.0f, 60.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(60.0f, 20.0f, 60.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(60.0f, -5.0f, 60.0f);
	glEnd();


	glBegin(GL_TRIANGLES);
		glVertex3f(-10.0f, -5.0f, -10.0f);
		glVertex3f(-10.0f, 20.0f, 60.0f);
		glVertex3f(-10.0f, -5.0f, 60.0f);
		
		glVertex3f(-10.0f, -5.0f, -10.0f);
		glVertex3f(-10.0f, 20.0f, -10.0f);
		glVertex3f(-10.0f, 20.0f, 60.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(60.0f, -5.0f, -10.0f);
		glVertex3f(60.0f, -5.0f, 60.0f);
		glVertex3f(60.0f, 20.0f, 60.0f);
		
		glVertex3f(60.0f, -5.0f, -10.0f);
		glVertex3f(60.0f, 20.0f, 60.0f);
		glVertex3f(60.0f, 20.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(60.0f, 20.0f, 60.0f);
		glVertex3f(-10.0f, 20.0f, 60.0f);
		glVertex3f(-10.0f, 20.0f, -10.0f);
		
		glVertex3f(60.0f, 20.0f, 60.0f);
		glVertex3f(-10.0f, 20.0f, -10.0f);
		glVertex3f(60.0f, 20.0f, -10.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	delete [] normal;
}
