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

	GLfloat* normal = new GLfloat[3];
	
	const GLfloat FLOOR = -5.0f;
	const GLfloat CEILING = 20.0f;
	const GLfloat LEFT = -10.0f;
	const GLfloat RIGHT = 60.0f;

	glColor3f(0.7f, 0.7f, 0.7f);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("moon.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, FLOOR, LEFT, RIGHT, FLOOR, LEFT, LEFT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, LEFT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		GeoHelper::findNormal3f(LEFT, CEILING, LEFT, RIGHT, FLOOR, LEFT, RIGHT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, LEFT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("sun.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, FLOOR, RIGHT, LEFT, CEILING, RIGHT, RIGHT, FLOOR, RIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, RIGHT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, RIGHT);
		
		GeoHelper::findNormal3f(LEFT, CEILING, RIGHT, RIGHT, CEILING, RIGHT, RIGHT, FLOOR, RIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RIGHT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, RIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, RIGHT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("nebula.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, FLOOR, LEFT, LEFT, CEILING, RIGHT, LEFT, FLOOR, RIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, RIGHT);
		
		GeoHelper::findNormal3f(LEFT, FLOOR, LEFT, LEFT, CEILING, LEFT, LEFT, CEILING, RIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RIGHT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("stars1.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(RIGHT, FLOOR, LEFT, RIGHT, FLOOR, RIGHT, RIGHT, CEILING, RIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, RIGHT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, RIGHT);
		
		GeoHelper::findNormal3f(RIGHT, FLOOR, LEFT, RIGHT, CEILING, RIGHT, RIGHT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, RIGHT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, LEFT);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("milky.bmp"));

	glBegin(GL_TRIANGLES);

		GeoHelper::findNormal3f(RIGHT, CEILING, RIGHT, LEFT, CEILING, RIGHT, LEFT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, RIGHT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RIGHT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, CEILING, LEFT);
		
		GeoHelper::findNormal3f(RIGHT, CEILING, RIGHT, LEFT, CEILING, LEFT, RIGHT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, CEILING, RIGHT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, CEILING, LEFT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("stars2.bmp"));

	glBegin(GL_TRIANGLES);

		GeoHelper::findNormal3f(RIGHT, FLOOR, RIGHT, LEFT, FLOOR, LEFT, LEFT, FLOOR, RIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, FLOOR, RIGHT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, FLOOR, RIGHT);

		
		GeoHelper::findNormal3f(RIGHT, FLOOR, RIGHT, RIGHT, FLOOR, LEFT, LEFT, FLOOR, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RIGHT, FLOOR, RIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RIGHT, FLOOR, LEFT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	delete [] normal;
}
