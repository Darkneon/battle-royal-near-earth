/* 
 * File:   CannonModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 6:59 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "CannonModel.h"
#include "NuclearModel.h"

CannonModel::CannonModel() {
    NuclearModel *model = new NuclearModel();
    setNextChild( (Model*)model );
}

void CannonModel::render() {
    glPushMatrix();
        glTranslatef(0.5f ,0.1f,0.5f); //by Jeff
        glScalef(.3f,.4f,.3f);//by Jeff
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			GeoHelper::drawTrapezoidalPrism();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.4f, 0.4f, 0.4f);
			glTranslatef(-0.9f, 0.35f, 0.5f);
			glRotatef(90, 0.0f, 0.0f, 1.0f);
			glScalef(0.1f, 0.6, 0.1f);
			GeoHelper::drawCylinder(360);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.4f, 0.4f, 0.4f);
			glTranslatef(-0.9f, 0.35f, -0.5f);
			glRotatef(90, 0.0f, 0.0f, 1.0f);
			glScalef(0.1f, 0.6, 0.1f);
			GeoHelper::drawCylinder(360);
		glPopMatrix();
	glPopMatrix();
    
    glTranslatef(0, 0.4f, 0);
}