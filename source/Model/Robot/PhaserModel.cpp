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
    /*NuclearModel *model = new NuclearModel();
    setNextChild( (Model*)model );*/
    teamNumber = new TeamNumberModel();
    
    material = (Material*)(new MetalMaterial());
}

void PhaserModel::render() {

	

	glPushMatrix();
    glTranslatef(-0.1f,0.05f,0.0f);    
	//Draw number -- Addison
        glPushMatrix();
                glTranslatef(0.4f, 0.85f, 0.6f);
                glScalef(0.5f, 0.5f, 0.5f);
                teamNumber->render();
        glPopMatrix();
		TextureManager::getInstance()->enableTexture();
		glColor3f(0.7f, 0.7f, 0.7f);
		GLUquadricObj *quadratic = gluNewQuadric();

		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smooth_metal.bmp"));
		gluQuadricTexture(quadratic,true);

		glPushMatrix();
			glTranslatef(.3f, .55f, .71f);
			glScalef(.4f, .4f, .4f);

			glPushMatrix();
				glTranslatef(0.5f, -0.745f, -0.55f);
				glPushMatrix();
					glRotatef(-90, 0.0f, 1.0f, 0.0f);
					glRotatef(-90, 1.0f, 0.0f, 0.0f);	
					GLdouble coordinate[4] = {0.0, 1.0, 0.0, 0.0};
					glClipPlane(GL_CLIP_PLANE0, coordinate);
					glEnable(GL_CLIP_PLANE0);
					gluCylinder(quadratic, 1.0, 1.0, 1.5, 12, 12);

					//closing thing for phaser
					GLfloat* normal = new GLfloat[3];

					glBegin(GL_TRIANGLES);
						GeoHelper::findNormal3f(-1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.5f, normal);
						glNormal3fv(normal);

						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(-1.0f, 0.0f, 0.0f);

						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(1.0f, 0.0f, 0.0f);

						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(-1.0f, 0.0f, 1.5f);

						GeoHelper::findNormal3f(-1.0f, 0.0f, 1.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.5f, normal);
						glNormal3fv(normal);

						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(-1.0f, 0.0f, 1.5f);

						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(1.0f, 0.0f, 0.0f);

						glTexCoord2f(1.0f, 1.0f);
						glVertex3f(1.0f, 0.0f, 1.5f);
					glEnd();


					glPushMatrix();
						glTranslatef(0.0f, 0.0f, 1.5f);
						gluDisk(quadratic, 0.0, 1.0, 12, 12);

						glTranslatef(0.0f, 0.0f, -1.5f);
						glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
						gluDisk(quadratic, 0.0, 1.0, 12, 12);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();

			glDisable(GL_CLIP_PLANE0);
			
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("mech.bmp"));

			//cannon barrel
			glPushMatrix();
				glTranslatef(0.2f, 0.0f, -0.55f);
				glScalef(0.25f, 1.0f, 0.4f);
				GeoHelper::drawRectangle();


				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("energy.bmp"));
				glTranslatef(-1.01f, 0.0f, 0.0f);
				glScalef(1.0f, 1.0f, 2.0f);


				glBegin(GL_TRIANGLES);
					GeoHelper::findNormal3f(0.0f, -0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, 0.5f, -0.5f, normal);
					glNormal3fv(normal);

					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(0.0f, -0.5f, -0.5f);

					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(0.0f, -0.5f, 0.5f);

					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(0.0f, 0.5f, -0.5f);

					GeoHelper::findNormal3f(0.0f, 0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, 0.5f, normal);
					glNormal3fv(normal);

					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(0.0f, 0.5f, 0.5f);

					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(0.0f, 0.5f, -0.5f);

					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(0.0f, -0.5f, 0.5f);
				glEnd();
			glEnd();
					
			glPopMatrix();

			
			
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("smooth_metal.bmp"));
			//cannon base
			glPushMatrix();
				glTranslatef(0.75f, -1.5f, -0.5f);

				glPushMatrix();
					glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
					gluCylinder(quadratic, 0.7, 0.7, 0.75, 10, 10);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0f, 0.75f, 0.0f);
					glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
					gluDisk(quadratic, 0.0, 0.7, 10, 10);
				glPopMatrix();
			
			glPopMatrix();
		glPopMatrix();
    glPopMatrix();
    glTranslatef(0, 0.9f, 0);

	gluDeleteQuadric(quadratic);

	delete [] normal;
}