#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Robot/TracksModel.h"
#include "Robot/PhaserModel.h"


TracksModel::TracksModel()
{
	teamNumber = new TeamNumberModel();
    
    //material = (Material*)(new MetalMaterial());   
}

void TracksModel::render(){
	glPushMatrix();
		glTranslatef(0.1f, 0.0f, 0.2f);
		glScalef(0.4f,0.4f,0.4f);
		
		//track 1
		drawTrack();
		
		//track2
		glTranslatef(0,0,1);
		drawTrack();
		glTranslatef(0,0,-1);
	
	glPopMatrix();
    
    glTranslatef(0, 0.42f, 0);
}

void TracksModel::drawTrack(){
	TextureManager::getInstance()->enableTexture();
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

	GLUquadricObj *qTracks = gluNewQuadric();
	gluQuadricNormals(qTracks, GLU_SMOOTH);

	GLUquadricObj *qDisk = gluNewQuadric();
	gluQuadricNormals(qDisk, GLU_SMOOTH);

	glPushMatrix();
		//first track cylinder
		//glColor3f(1.0f, 1.0f, 1.0f);
		glPushMatrix();
			glTranslatef(0.5f, 0.5f, 0.0f);
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks1.bmp"));
			gluQuadricTexture(qTracks,true);
			gluCylinder(qTracks, 0.5, 0.5, 0.5, 15, 15);
			glTranslatef(-0.5f, -0.5f, 0.0f);
		glPopMatrix();

		//second track cylinder
		glPushMatrix();
			glTranslatef(1.5f, 0.5f, 0.0f);
			gluCylinder(qTracks, 0.5, 0.5, 0.5, 15, 15);
			glTranslatef(-1.5f, -0.5f, 0.0f);
		glPopMatrix();

		//rectangle
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks1.bmp"));
		glPushMatrix();
			glBegin(GL_QUADS);
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.5f, 1.0f, 0.5f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(1.5f, 1.0f, 0.5f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.5f, 1.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.5f, 1.0f, 0.0f);

				glNormal3f(0,-1,0);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.5, 0, 0.5);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(0.5, 0, 0);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.5, 0, 0);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(1.5, 0, 0.5);

			glEnd();
		glPopMatrix();

		//glColor3f(0.3f, 0.3f, 0.3f);
		//circles and squares to finish model
		glPushMatrix();
			glRotatef(180, 0.0f,1.0f, 0.0f);
			glTranslatef(-2.0f, 0.0f, 0.0f);

			glTranslatef(0.5,0.5,0);
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks2.bmp"));
			gluQuadricTexture(qDisk,true);
			gluDisk(qDisk,0,0.5,15,15);
			glTranslatef(-0.5,-0.5,0);

			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks2.bmp"));
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.5, 0, 0.0);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.5, 0, 0.0);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.5, 1, 0.0);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.5, 1, 0.0);
			glEnd();

			glTranslatef(1.5,0.5,0);
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks2.bmp"));
			gluQuadricTexture(qDisk,true);
			gluDisk(qDisk,0,0.5,15,15);
			glTranslatef(-1.5,-0.5,0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.5,0.5,0.5);
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks2.bmp"));
			gluQuadricTexture(qDisk,true);
			gluDisk(qDisk,0,0.5,15,15);
			glTranslatef(-0.5,-0.5,-0.5);

			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks2.bmp"));
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.5, 0, 0.5);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.5, 0, 0.5);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.5, 1, 0.5);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.5, 1, 0.5);
			glEnd();

			glTranslatef(1.5,0.5,0.5);
			glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->getTextures("tracks2.bmp"));
			gluQuadricTexture(qDisk,true);
			gluDisk(qDisk,0,0.5,15,15);
			glTranslatef(-1.5,-0.5,-0.5);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.5f,0.0f, 0.0f);
			glRotatef(180, 0.0f,1.0f, 0.0f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			teamNumber->render();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(.5f,0.0f, 0.5f);
			glRotatef(90, 1.0f,0.0f, 0.0f);
			teamNumber->render();
		glPopMatrix();

	glPopMatrix();
	gluDeleteQuadric(qTracks);
	gluDeleteQuadric(qDisk);
}