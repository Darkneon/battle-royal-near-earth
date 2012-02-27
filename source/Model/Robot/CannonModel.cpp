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

#include "Robot/CannonModel.h"
#include "Robot/NuclearModel.h"
#include "Material/MetalMaterial.h"

CannonModel::CannonModel() {    
	teamNumber = new TeamNumberModel();
    material = (Material*)(new MetalMaterial());
}    

void CannonModel::render() {    
	glPushMatrix();
		glTranslatef(-0.1f,0.0f,0.0f);
		glPushMatrix();
			glTranslatef(0.5f, 0.1f, 0.5f);
			glScalef(.3f,.4f,.3f);
			glPushMatrix();
				glColor3f(1.0f, 0.0f, 0.0f);
				//glTranslatef(7.5f, 0.0f, 0.0f);
				GeoHelper::drawTrapezoidalPrism();
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.4f, 0.4f, 0.4f);
				glTranslatef(-0.9f, 0.35f, 0.5f);
				glRotatef(90, 0.0f, 0.0f, 1.0f);
				glScalef(0.1f, 0.6f, 0.1f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.4f, 0.4f, 0.4f);
				glTranslatef(-0.9f, 0.35f, -0.5f);
				glRotatef(90, 0.0f, 0.0f, 1.0f);
				glScalef(0.1f, 0.6f, 0.1f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.89f,0.0f,0.75f);
			glScalef(0.5f, 0.5f, 0.5f);
			glRotatef(90, 0.0f,1.0f, 0.0f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			teamNumber->render();
		glPopMatrix();
    glPopMatrix();
    glTranslatef(0.0f, 0.4f, 0.0f);
}