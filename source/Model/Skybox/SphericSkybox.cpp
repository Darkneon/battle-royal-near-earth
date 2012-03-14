#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "SphericSkybox.h"

SphericSkybox::SphericSkybox() {	
}

void SphericSkybox::render() 
{
    TextureManager::getInstance()->enableTexture();

	glCullFace( GL_FRONT );
	
	GLUquadricObj *quadratic = gluNewQuadric();

	gluQuadricTexture(quadratic,true);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("spheremap.bmp")); 

	glPushMatrix();

	glTranslatef(20.0f, 0.0f, 0.0f);
	gluSphere(quadratic, 60.0, 15, 15);

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadratic);

	glCullFace( GL_BACK );
}
