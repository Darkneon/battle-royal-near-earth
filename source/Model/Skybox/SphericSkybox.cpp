#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "SphericSkybox.h"

SphericSkybox::SphericSkybox() {	
	build();
}


void SphericSkybox::build()
{
	glNewList(4, GL_COMPILE);
	
	glCullFace( GL_FRONT );
	
	GLUquadricObj *quadratic = gluNewQuadric();

	gluQuadricTexture(quadratic,true);
	glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("spheremap.bmp")); 

	glPushMatrix();

	glTranslatef(20.0f, 0.0f, 0.0f);
	gluSphere(quadratic, 60.0, 15, 15);

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
