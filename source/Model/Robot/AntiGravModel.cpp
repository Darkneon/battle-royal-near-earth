#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/AntiGravModel.h"
#include "Robot/PhaserModel.h"
#include "Material/MetalMaterial.h"


AntiGravModel::AntiGravModel(void)
{
    teamNumber = new TeamNumberModel();
    material = (Material*)(new MetalMaterial());
}


void AntiGravModel::render(){
	TextureManager::getInstance()->enableTexture();

	GLUquadricObj *qGrav = gluNewQuadric();
	gluQuadricNormals(qGrav, GLU_SMOOTH);

	glPushMatrix();
        glTranslatef(0.125f, 0.2f, 0.125f);
		glScalef(0.5f, 0.5f, 0.5f);
    
		//first machine block
		drawMachineCube();

		//second machine block
		glTranslatef(1.0f,0.0f,0.0f);
		drawMachineCube();
		glTranslatef(-1.0f,0.0f,0.0f);

		//third machine block
		glTranslatef(1.0f,0.0f,1.0f);
		drawMachineCube();
		glTranslatef(-1.0f,0.0f,-1.0f);

		//fourth machine block
		glTranslatef(0.0f,0.0f,1.0f);
		drawMachineCube();
		glTranslatef(0.0f,0.0f,-1.0f);

		//rectangle
		glTranslatef(0.0f,0.8f,0.0f);
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("copper.bmp"));
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.2f, 0.2f, 0.2f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.3f, 0.2f, 0.2f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.3f, 0.0f, 0.2f);

				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 1.3f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.3f, 0.0f, 1.3f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.3f, 0.2f, 1.3f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.2f, 0.2f, 1.3f);
			glEnd();
	
			glBegin(GL_QUAD_STRIP);
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 1.3f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.2f, 0.2f, 0.2f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.2f, 0.2f, 1.3f);

				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(1.3f, 0.2f, 0.2f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.3f, 0.2f, 1.3f);

				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.3f, 0.0f, 0.2f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.3f, 0.0f, 1.3f);

				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 0.2f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.2f, 0.0f, 1.3f);
			glEnd();
		glPopMatrix();
		glTranslatef(0.0f,-0.8f,0.0f);

		glPushMatrix();
			glTranslatef(0.3f,1.0f,1.2f);
			TeamNumberModel teamNumber;
			teamNumber.render();
		glPopMatrix();

		//cylinder
		glTranslatef(1.0f,0.8f,1.0f);
		glColor3f(1.0f,1.0f,1.0f);
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("copper.bmp"));
		gluQuadricTexture(qGrav,true);

		glPushMatrix();
			glRotatef(45, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(qGrav, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-1.0f,-0.8f,-1.0f);

		glTranslatef(0.4f, 0.8f, 1.0f);
		glPushMatrix();
			glRotatef(-45, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(qGrav, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-0.4f,-0.8f,-1.0f);

		glTranslatef(1.0f, 0.8f, 0.5f);
		glPushMatrix();
			glRotatef(135, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(qGrav, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-1.0f,-0.8f,-0.5f);

		glTranslatef(0.5f,0.8f,0.5f);
		glPushMatrix();
			glRotatef(-135, 0.0f, 1.0f, 0.0f);
			glRotatef(68, 1.0f, 0.0f, 0.0f);
			gluCylinder(qGrav, 0.1, 0.1, 0.6, 15, 15);
		glPopMatrix();
		glTranslatef(-0.5f,-0.8f,-0.5f);

	glPopMatrix();

    glTranslatef(0, 0.7f, 0);
	gluDeleteQuadric(qGrav);
}

void AntiGravModel::drawMachineCube(){

	glColor3f(0.6f,0.6f,0.6f);
	glPushMatrix();
		glPushMatrix();
			
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("antigrav1.bmp"));
			glBegin(GL_QUAD_STRIP);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.0f, 0.3f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.5f, 0.3f, 0.0f);

				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.5f, 0.0f, 0.5f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.5f, 0.3f, 0.5f);

				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.5f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.0f, 0.3f, 0.5f);

				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.0f, 0.3f, 0.0f);

			glEnd();
		glPopMatrix();

		//top
		glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.3f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.0f, 0.3f, 0.5f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5f, 0.3f, 0.5f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5f, 0.3f, 0.0f);
		glEnd();

		//bottom
		glBegin(GL_QUADS);
			glNormal3f(0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5f, 0.0f, 0.5f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.5f);
		glEnd();

	glPopMatrix();
}
