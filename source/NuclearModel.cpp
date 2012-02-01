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
#include "PhaserModel.h"

NuclearModel::NuclearModel() {
	PhaserModel *child = new PhaserModel();
	setNextChild( (Model*)child );
}

void NuclearModel::render() 
{
	GLUquadricObj *quadratic = gluNewQuadric();;
    glPushMatrix();
        glTranslatef(0.5f,0.8f,-0.3f);

        glScalef(0.8, 0.5, 0.8);
		glRotatef(-90, 1,0,0);
		gluCylinder(quadratic, .5, .5, 1, 8, 5);

		// Bottom
		glColor3f(1,0,0);
		gluDisk(quadratic, 0, .5, 8, 5);
		
		// Top
		glTranslatef(0,0,1);
		gluDisk(quadratic, 0, .5, 8, 5);
    glPopMatrix();

	gluDeleteQuadric(quadratic);
}