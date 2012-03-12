#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/BipodModel.h"
#include "Robot/PhaserModel.h"
#include "Material/MetalMaterial.h"

BipodModel::BipodModel(void)
{
    teamNumber = new TeamNumberModel();
    material = (Material*)(new MetalMaterial());
}


void BipodModel::render(){
	TextureManager::getInstance()->enableTexture();

	glPushMatrix();
		glTranslatef(.8f, 0.0f, 1.0f);
		glRotatef(180,0,1,0);
		glScalef(.65f, .65f, .65f);
		//first leg
		drawLeg();

		//second leg
		glTranslatef(0.0f, 0.0f, 1.0f);
		drawLeg();
		glTranslatef(0.0f, 0.0f, -1.0f);


		glTranslatef(0.f, 1.3f, 0.f);
		//rectangle
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("rustymetal.bmp"));
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.0f, 0.2f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0f, 0.2f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.0f, 0.0f, 0.0f);

				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.0f, 0.0f, 1.5f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0f, 0.2f, 1.5f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.0f, 0.2f, 1.5f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 1.5f);
			glEnd();
	
			glBegin(GL_QUAD_STRIP);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 1.5f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.0f, 0.2f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.0f, 0.2f, 1.5f);
				
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(1.0f, 0.2f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.0f, 0.2f, 1.5f);

				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0f, 0.0f, 1.5f);

				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 1.5f);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	glTranslated(0,1,0);
}

void BipodModel::drawLeg(){
	GLUquadricObj *qbipod = gluNewQuadric();
	gluQuadricNormals(qbipod, GLU_SMOOTH);

	glPushMatrix();
		glTranslatef(0.25f,0.4f,0.25f);
		glPushMatrix();
			//thigh
			glTranslatef(0.0f,1.0f,0.0f);
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("steel.bmp"));
				gluQuadricTexture(qbipod,true);

				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glRotatef(45, 1.0f, 0.0f, 0.0f);
				gluCylinder(qbipod, 0.1, 0.1, 0.6, 15, 15);
			glPopMatrix();
			glTranslatef(0.0f,-1.0f,0.0f);

			//leg
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("steel.bmp"));
				gluQuadricTexture(qbipod,true);

				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glRotatef(-45, 1.0f, 0.0f, 0.0f);
				gluCylinder(qbipod, 0.1, 0.1, 0.6, 15, 15);
			glPopMatrix();

			//knee
			glTranslatef(0.45f, 0.5f, 0.0f);
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("steel.bmp"));
				gluQuadricTexture(qbipod,true);

				gluSphere(qbipod,0.15,15,15);
			glPopMatrix();
			glTranslatef(-0.45f, -0.5f, 0.0f);
		glPopMatrix();
		glTranslatef(-0.25f,-0.4f,-0.25f);


		//feet
		glPushMatrix();
			glScalef(.5f,.5f,.5f);
			glRotatef(-90, 0.0f,1.0f, 0.0f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			TeamNumberModel teamNumber;
			teamNumber.render();
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("bipodf.bmp"));
		glBegin(GL_QUADS);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.0f, 0.5f, 0.0f);
			glTexCoord2f(0.5f, 1.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.5f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.5f);
			glTexCoord2f(0.5f, 1.0f);
			glVertex3f(0.5f, 0.5f, 0.5f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.0f, 0.5f, 0.5f);
		glEnd();

		glBegin(GL_QUAD_STRIP);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.5f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.0f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.0f, 0.5f, 0.5f);

			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.5f);

			glNormal3f(1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(1.0f, 0.0f, 0.5f);

			glNormal3f(0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.5f);
		glEnd();
	glPopMatrix();
	gluDeleteQuadric(qbipod);
}