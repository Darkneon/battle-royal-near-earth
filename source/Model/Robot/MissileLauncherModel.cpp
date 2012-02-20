/* 
 * File:   MissileLauncherModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:30 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "MissileLauncherModel.h"
#include "NuclearModel.h"

MissileLauncherModel::MissileLauncherModel() {
    NuclearModel *model = new NuclearModel();
    setNextChild( (Model*)model );
	//height approx. .3
        teamNumber = new TeamNumberModel();
}

void MissileLauncherModel::render() {
                 //Draw number -- Addison
                glPushMatrix();
                        glTranslatef(0.2f, 0.3f, 0.6f);
                        glScalef(0.5f, 0.5f, 0.5f);
                        teamNumber->render();
                glPopMatrix();
                
	
    glPushMatrix();
        glTranslatef(0.5f,0.175f,0.5f);//by jeff
        glScalef(.27f,.27f,.27f);//by jeff
		glRotatef(-90, 0.0f, 1.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 4.0f, 0.0f);
			glScalef(1.1f, 0.9f, 0.8f);
			GeoHelper::drawRectangle();
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.5f, 0.0f, 0.5f);
			glPushMatrix();
				glTranslatef(-1.3f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.5f, 0.0f, 0.5f);
				glTranslatef(1.6f, -0.5f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glScalef(0.3f, 1.7f, 0.3f);
				GeoHelper::drawCylinder(360);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
    
    glTranslatef(0, 0.3f, 0);
}