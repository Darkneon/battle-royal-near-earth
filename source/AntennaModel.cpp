#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL\glut.h>
#endif

#include <cstdlib>

#include "Model.h"
#include "AntennaModel.h"

AntennaModel::AntennaModel() {	
}

void AntennaModel::render() {
    GLUquadric *quadratic = gluNewQuadric(); 
	gluQuadricNormals(quadratic, GLU_SMOOTH);

	glPushMatrix();
		glTranslatef(1.5f, 2.0f, 1.5f);
		glRotatef(90.0f, 1.0f, 0, 0);
		gluCylinder(quadratic, 0.1f, 0.1f, 1, 10, 10);
	glPopMatrix();
    
    gluDeleteQuadric(quadratic);
}
