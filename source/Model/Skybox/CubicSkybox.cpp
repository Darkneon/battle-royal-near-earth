#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "CubicSkybox.h"

CubicSkybox::CubicSkybox(int height, int width) {	
	build(height, width);
}

void CubicSkybox::build(int height, int width)
{
	glNewList(3, GL_COMPILE);

	GLfloat* normal = new GLfloat[3];
	
	const GLfloat FLOOR = -5.0f;
	const GLfloat CEILING = 20.0f;
	const GLfloat LEFT = -10.0f;
	const GLfloat RWIDTH = (GLfloat)width + 10;
	const GLfloat RHEIGHT = (GLfloat)height + 10;

	glColor3f(0.7f, 0.7f, 0.7f);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("moon.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, FLOOR, LEFT, RWIDTH, FLOOR, LEFT, LEFT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, LEFT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		GeoHelper::findNormal3f(LEFT, CEILING, LEFT, RWIDTH, FLOOR, LEFT, RWIDTH, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, LEFT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("sun.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, FLOOR, RHEIGHT, LEFT, CEILING, RHEIGHT, RWIDTH, FLOOR, RHEIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, RHEIGHT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RHEIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, RHEIGHT);
		
		GeoHelper::findNormal3f(LEFT, CEILING, RHEIGHT, RWIDTH, CEILING, RHEIGHT, RWIDTH, FLOOR, RHEIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RHEIGHT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, RHEIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, RHEIGHT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("nebula.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(LEFT, FLOOR, LEFT, LEFT, CEILING, RHEIGHT, LEFT, FLOOR, RHEIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RHEIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, RHEIGHT);
		
		GeoHelper::findNormal3f(LEFT, FLOOR, LEFT, LEFT, CEILING, LEFT, LEFT, CEILING, RHEIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RHEIGHT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("stars1.bmp"));

	glBegin(GL_TRIANGLES);
		GeoHelper::findNormal3f(RWIDTH, FLOOR, LEFT, RWIDTH, FLOOR, RHEIGHT, RWIDTH, CEILING, RHEIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, RHEIGHT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, RHEIGHT);
		
		GeoHelper::findNormal3f(RWIDTH, FLOOR, LEFT, RWIDTH, CEILING, RHEIGHT, RWIDTH, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, LEFT);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, RHEIGHT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, LEFT);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("milky.bmp"));

	glBegin(GL_TRIANGLES);

		GeoHelper::findNormal3f(RWIDTH, CEILING, RHEIGHT, LEFT, CEILING, RHEIGHT, LEFT, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, RHEIGHT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, CEILING, RHEIGHT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, CEILING, LEFT);
		
		GeoHelper::findNormal3f(RWIDTH, CEILING, RHEIGHT, LEFT, CEILING, LEFT, RWIDTH, CEILING, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, CEILING, RHEIGHT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, CEILING, LEFT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, CEILING, LEFT);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("stars2.bmp"));

	glBegin(GL_TRIANGLES);

		GeoHelper::findNormal3f(RWIDTH, FLOOR, RHEIGHT, LEFT, FLOOR, LEFT, LEFT, FLOOR, RHEIGHT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, FLOOR, RHEIGHT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(LEFT, FLOOR, RHEIGHT);

		
		GeoHelper::findNormal3f(RWIDTH, FLOOR, RHEIGHT, RWIDTH, FLOOR, LEFT, LEFT, FLOOR, LEFT, normal);
		glNormal3fv(normal);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(RWIDTH, FLOOR, RHEIGHT);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(RWIDTH, FLOOR, LEFT);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(LEFT, FLOOR, LEFT);
	glEnd();

	glEndList();

	delete [] normal;
}

void CubicSkybox::render() 
{
    TextureManager::getInstance()->enableTexture();

	glCallList(3);

	glDisable(GL_TEXTURE_2D);
	
}
