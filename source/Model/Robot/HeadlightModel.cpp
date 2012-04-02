#include "HeadlightModel.h"
#include "Material/MetalMaterial.h"

HeadlightModel::HeadlightModel(void)
{
	material = (Material*)(new MetalMaterial());
	whiteLight = false;
}


void HeadlightModel::render(void)
{

	GLUquadricObj *quadratic = gluNewQuadric();
	//Note: eye is at (.3,.15,.5)
	
	glPushMatrix();
		glTranslatef(.5f, 0.0f, .5f);
		glScalef(0.5f,0.5f,0.5f);
		glTranslatef(-.5f, 0.0f, -.5f);
		//draw rectangular up-post
		glPushMatrix();
			glTranslatef(.45f, 0.0f, .45f);
			glScalef(.1f, .5f, .1f);
			glColor3f(0.2f, 0.2f, 0.2f);
			drawCube();
		glPopMatrix();
		//draw rectangular 70 degree post
		glPushMatrix();
			glTranslatef(.525f, 0.4f, .45f);
			glRotatef(110,0.0f,0.0f,1.0f);
			glScalef(.1f, .29f, .1f);
			glColor3f(0.2f, 0.2f, 0.2f);
			drawCube();
		glPopMatrix();
		//lamp head
		glPushMatrix();
			glTranslatef(0.23f,0.35f,0.5f);
			glRotatef(20.0f, 0.0f, 0.0f, 1.0f);
			glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
			glColor4f(0.2f, 0.2f, 0.2f, 0.0f);
			//outside cylinder
			gluCylinder(quadratic, 0.1f, 0.2f, 0.2f, 15, 15);
			//inside cylinder
			gluQuadricOrientation(quadratic, GLU_INSIDE);
			gluCylinder(quadratic, 0.1f, 0.2f, 0.2f, 15, 15);
			gluQuadricOrientation(quadratic, GLU_OUTSIDE);

			//bulb cylinder
			glColor4f(0.4f, 0.4f, 0.4f, 0.4f);
			gluCylinder(quadratic, 0.1f, 0.1f, 0.1f, 15, 15);
			gluQuadricOrientation(quadratic, GLU_INSIDE);
			gluDisk(quadratic, 0.0f, 0.1f, 15, 5);
			gluQuadricOrientation(quadratic, GLU_OUTSIDE);
			
			glPushMatrix();
				glTranslatef(0.0f,0.0f,0.1f);
				if(!whiteLight){
					glColor4f(0.4f, 0.4f, 0.4f, 0.4f);
				}
				else{
					glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
				}
				gluDisk(quadratic, 0.0f,0.1f,15,5);
			glPopMatrix();
			
		glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(quadratic);
}
void HeadlightModel::drawSquare(){
	glPushMatrix();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(0.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,1.0f);

			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(1.0f,0.0f,1.0f);
			glVertex3f(1.0f,0.0f,0.0f);
		glEnd();
	glPopMatrix();
}

void HeadlightModel::drawCube(){
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
			glRotatef(90.f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//right
		glPushMatrix();
			glTranslatef(1.0f, 1.0f, 0.0f);
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