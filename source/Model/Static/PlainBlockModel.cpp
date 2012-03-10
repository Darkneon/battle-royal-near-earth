/* 
 * File:   PlainBlockModel.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 6:39 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "PlainBlockModel.h"

PlainBlockModel::PlainBlockModel() {
}

void PlainBlockModel::render() {

	glPushMatrix();
		drawCube();
	glPopMatrix();
}

void PlainBlockModel::drawSquare(){
    glEnable(GL_TEXTURE_2D);
	GLuint temp = TextureManager::getInstance()->getTextures("brick.bmp");
	glBindTexture(GL_TEXTURE_2D, temp);
	glPushMatrix();
	glEnable(GL_BLEND);
	glColor4f(0.5f,0.5f,0.5f,0.5f);
		/*glBegin(GL_TRIANGLES);
			glTexCoord2f(0.0f,0.0f); glVertex3f(0.0f,0.0f,0.0f);
			glTexCoord2f(0.0f,1.0f); glVertex3f(0.0f,0.0f,1.0f);
			glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,0.0f,1.0f);

			glTexCoord2f(0.0f,0.0f); glVertex3f(0.0f,0.0f,0.0f);
			glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,0.0f,1.0f);
			glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,0.0f,0.0f);
		glEnd();*/
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f); glVertex3f(0.0f,0.0f,0.0f);
			glTexCoord2f(0.0f,1.0f); glVertex3f(0.0f,0.0f,1.0f);
			glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,0.0f,1.0f);
			glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,0.0f,0.0f);
		glEnd();
	glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void PlainBlockModel::drawCube(){
	glPushMatrix();
		//bottom
		glPushMatrix();
			drawSquare();
		glPopMatrix();
		//top
		glPushMatrix();
			glTranslatef(0.0f,1.0f,0.0f);
			drawSquare();
		glPopMatrix();
		//left
		glPushMatrix();
			glTranslatef(0.0f,0.5f,0.5f);
			glRotatef(-90.f,1.0f,0.0f,0.0f);
			glTranslatef(0.0f,-0.5f,-0.5f);
			glRotatef(90.f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//right
		glPushMatrix();
			glTranslatef(1.0f, .5f, 0.5f);
			glRotatef(90.f,1.0f,0.0f,0.0f);
			glTranslatef(0.0f,0.5f,-0.5f);
			glRotatef(-90.f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//near
		glPushMatrix();
			glRotatef(-90.f, 1.0f,0.0f,0.0f);
			drawSquare();
		glPopMatrix();
		//far
		glPushMatrix();
			glTranslatef(0.0f,1.0f,1.0f);
			glRotatef(90.f, 1.0f,0.0f,0.0f);
			drawSquare();
		glPopMatrix();
	glPopMatrix();
}