/* 
 * File:   PlayerModel.cpp
 * Author: robert
 * 
 * Created on January 19, 2012, 3:47 PM
 */


#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "PlayerModel.h"
#include "AntennaModel.h"
#include <cstdlib>

PlayerModel::PlayerModel() {
    AntennaModel *child = new AntennaModel;
    setNextChild( (Model*)child );
}

void PlayerModel::render() {
    glColor3f(0, 1, 0);
    
	renderPlane();

	glColor3f(1, 1, 1);
	glPushMatrix();
		glTranslatef(0, 1.0f, 0);
		renderPlane();
	glPopMatrix();

	glColor3f(1, 1, 0);
    //front
    renderOneSide();
    
    //right side
    glPushMatrix();
        glTranslatef(3.0f, 0.0f, 0.0f);
        glRotated(-90.0f, 0, 1.0f, 0);
        renderOneSide();
    glPopMatrix();
    
    
    glColor3f(0, 1, 1);
    //back
    glPushMatrix();
        glTranslatef(3.0f, 0.0f, 3.0f);
        glRotated(180.0f, 0, 1.0f, 0);
        renderOneSide();
    glPopMatrix();
    
    //left side
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 3.0f);
        glRotated(90.0f, 0, 1.0f, 0);
        renderOneSide();
    glPopMatrix();
       
}
void PlayerModel::renderOneSide() {
    glBegin(GL_TRIANGLES);
        //front left square
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 1, 0);
        
        glVertex3f(1, 0, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(0, 1, 0);
        
        //front left inner
        glVertex3f(1, 1, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 0.5f);
        
        glVertex3f(1, 0, 0.5f);
        glVertex3f(1, 1, 0.5f);
        glVertex3f(1, 1, 0);
        
        //front inner
        glVertex3f(1, 1, 0.5f);
        glVertex3f(1, 0, 0.5f);
        glVertex3f(2, 1, 0.5f);
        
        glVertex3f(2, 1, 0.5f);
        glVertex3f(1, 0, 0.5f);
        glVertex3f(2, 0, 0.5f);
        
        //front right inner
        glVertex3f(2, 1, 0.5f);
        glVertex3f(2, 0, 0.5f);
        glVertex3f(2, 0, 0);
        
        glVertex3f(2, 1, 0.5f);
        glVertex3f(2, 0, 0);
        glVertex3f(2, 1, 0);
        
        //front right square
        glVertex3f(2, 0, 0);
        glVertex3f(3, 0, 0);
        glVertex3f(2, 1, 0);
        
        glVertex3f(2, 1, 0);
        glVertex3f(3, 0 ,0);
        glVertex3f(3, 1, 0);
       
    glEnd();
}

void PlayerModel::renderPlane() {
	glBegin(GL_TRIANGLES);
		//corner 1
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 0, 1);

		glVertex3f(0, 0, 1);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 0, 1);

		//corner 2
		glVertex3f(2, 0, 0);
		glVertex3f(3, 0, 0);
		glVertex3f(2, 0, 1);

		glVertex3f(2, 0, 1);
		glVertex3f(3, 0, 0);
		glVertex3f(3, 0, 1);

		//corner 3
		glVertex3f(2, 0, 2);
		glVertex3f(3, 0, 2);
		glVertex3f(2, 0, 3);

		glVertex3f(2, 0, 3);
		glVertex3f(3, 0, 2);
		glVertex3f(3, 0, 3);

		//corner 4
		glVertex3f(0, 0, 2);
		glVertex3f(1, 0, 2);
		glVertex3f(0, 0, 3);

		glVertex3f(0, 0, 3);
		glVertex3f(1, 0, 2);
		glVertex3f(1, 0, 3);

		//middle
		glVertex3f(0.5f, 0, 1);
		glVertex3f(2.5f, 0, 1);
		glVertex3f(0.5f, 0, 2);

		glVertex3f(2.5f, 0, 1);
		glVertex3f(2.5f, 0, 2);		
		glVertex3f(0.5f, 0, 2);

		//space between squares
		//space 1
		glVertex3f(1, 0, 0.5f);
		glVertex3f(2, 0, 0.5f);
		glVertex3f(1, 0, 1);

		glVertex3f(2, 0, 0.5f);
		glVertex3f(2, 0, 1);
		glVertex3f(1, 0, 1);		

		//space2
		glVertex3f(1, 0, 2);
		glVertex3f(2, 0, 2);
		glVertex3f(1, 0, 2.5f);

		glVertex3f(2, 0, 2);
		glVertex3f(2, 0, 2.5f);
		glVertex3f(1, 0, 2.5f);	
	glEnd();
}
