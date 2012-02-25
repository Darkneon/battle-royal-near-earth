/* 
 * File:   PhaserModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 2:55 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/PhaserModel.h"
#include "Robot/NuclearModel.h"
#include "Material/MetalMaterial.h"

PhaserModel::PhaserModel() {
    NuclearModel *model = new NuclearModel();
    setNextChild( (Model*)model );
    teamNumber = new TeamNumberModel();
    
    material = (Material*)(new MetalMaterial());
}

void PhaserModel::render() {
                //Draw number -- Addison
                glPushMatrix();
                        glTranslatef(0.4f, 0.85f, 0.6f);
                        glScalef(0.5f, 0.5f, 0.5f);
                        teamNumber->render();
                glPopMatrix();
    glPushMatrix();
        glTranslatef(.3f, .55f, .71f);
		glScalef(.4f, .4f, .4f);

		//back panel
		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glTranslatef(1.0f, 0.0f, 0.0f);
			glScalef(1.2f, 1.0f, 1.2f);
			GeoHelper::drawCylinder(180);
		glPopMatrix();

		//cannon barrel
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glTranslatef(-0.1f, 0.0f, -0.6f);
			glScalef(0.5f, 1.1f, 0.4f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		//cannon base
		glPushMatrix();
			glColor3f(0.4f,0.4f,0.4f);
			glTranslatef(1.1f, -1.1f, -0.125f);
			glScalef(0.9f, 0.5f, 0.9f);
			GeoHelper::drawCylinder(360);
		glPopMatrix();
	glPopMatrix();
    
    glTranslatef(0, 0.85f, 0);
}