#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "SphericSkybox.h"

SphericSkybox::SphericSkybox(int height, int width) {	
	build(height, width);
}


void SphericSkybox::build(int height, int width)
{
	int halfWidth = width/2;
	int halfHeight = height/2;

	int radius;

	if(halfWidth > halfHeight){
		radius = halfWidth + 15;
	}else{
		radius = halfHeight + 15;
	}

	glNewList(4, GL_COMPILE);
	
	glCullFace( GL_FRONT );
	
	GLUquadricObj *quadratic = gluNewQuadric();

	gluQuadricTexture(quadratic,true);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("spheremap.bmp")); 

	glPushMatrix();

	glTranslatef((GLfloat)halfWidth, 0.0f, (GLfloat)halfHeight);
	gluSphere(quadratic, (GLfloat)radius, 15, 15);

	glPopMatrix();

	
	gluDeleteQuadric(quadratic);

	glCullFace( GL_BACK );

	glEndList();
}

void SphericSkybox::render() 
{
    TextureManager::getInstance()->enableTexture();

	glCallList(4);

	glDisable(GL_TEXTURE_2D);

}
