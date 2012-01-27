/* 
 * File:   NuclearModel.cpp
 * Author: Jeffrey
 * 
 * Created on January 27, 2012, 1:24 AM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "NuclearModel.h"

NuclearModel::NuclearModel() {}

void NuclearModel::render() 
{
	GLUquadricObj *quadratic = gluNewQuadric();;

    glPushMatrix();
		glRotatef(90, 1,0,0);
		gluCylinder(quadratic, 1, 1, 1, 8, 5);

		// Bottom
		
		glTranslatef(0,0,0);
		gluDisk(quadratic, 0, 1, 8, 5);
		
		// Top
		glTranslatef(0,0,1);
		gluDisk(quadratic, 0, 1, 8, 5);
    glPopMatrix();

	gluDeleteQuadric(quadratic);
}