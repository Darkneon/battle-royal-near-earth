#include "BoundingBox.h"
#include "../../Logic/Robot.h"

bool BoundingBox::showBoxes = true;
GLuint BoundingBox::movingCount = 0;

BoundingBox::BoundingBox(void)
{
	min.x = 0.0f;
	min.y = 0.0f;
	min.z = 0.0f;
	max.x = 1.0f;
	max.y = 1.0f;
	max.z = 1.0f;
	size.x = 1.0f;
	size.y = 1.0f;
	size.z = 1.0f;
	movingBoxId = 0;
	//robot = NULL;
	hasRobot = false;
	hasNukePowerUp = false;
}

BoundingBox::BoundingBox(V3 min, V3 max){
	this->min = min;
	this->max = max;
	size.x = max.x-min.x;
	size.y = max.y-min.y;
	size.z = max.z-min.z;
	movingBoxId = 0;
	//robot = NULL;
	hasRobot = false;
	hasNukePowerUp = false;
}

BoundingBox::BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ){
	min.x = minX;
	min.y = minY;
	min.z = minZ;
	max.x = maxX;
	max.y = maxY;
	max.z = maxZ;
	size.x = max.x-min.x;
	size.y = max.y-min.y;
	size.z = max.z-min.z;
	movingBoxId = 0;
//	robot = NULL;
	hasRobot = false;
	hasNukePowerUp = false;
}

BoundingBox::BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ, bool moving){
	min.x = minX;
	min.y = minY;
	min.z = minZ;
	max.x = maxX;
	max.y = maxY;
	max.z = maxZ;
	size.x = max.x-min.x;
	size.y = max.y-min.y;
	size.z = max.z-min.z;
	if(moving){
		movingCount++;
		movingBoxId = movingCount;
	}
	else{
		movingBoxId = 0;
	}
	//robot = NULL;
	hasRobot = false;
	hasNukePowerUp = false;
}

BoundingBox::BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ, bool moving, Robot* r){
	min.x = minX;
	min.y = minY;
	min.z = minZ;
	max.x = maxX;
	max.y = maxY;
	max.z = maxZ;
	size.x = max.x-min.x;
	size.y = max.y-min.y;
	size.z = max.z-min.z;
	if(moving){
		movingCount++;
		movingBoxId = movingCount;
	}
	else{
		movingBoxId = 0;
	}
	robot = r;
	hasRobot = true;
	hasNukePowerUp = false;
}

BoundingBox::~BoundingBox(void){
	//robot = NULL;
}

void BoundingBox::drawSquare(){
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

void BoundingBox::drawCube(){
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
			glRotatef(90.0f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//right
		glPushMatrix();
			glTranslatef(1.0f, 1.0f, 0.0f);
			glRotatef(-90.0f, 0.0f,0.0f,1.0f);
			drawSquare();
		glPopMatrix();
		//near
		glPushMatrix();
			glRotatef(-90.0f, 1.0f,0.0f,0.0f);
			drawSquare();
		glPopMatrix();
		//far
		glPushMatrix();
			glTranslatef(0.0f,1.0f,1.0f);
			glRotatef(90.0f, 1.0f,0.0f,0.0f);
			drawSquare();
		glPopMatrix();
	glPopMatrix();
}


void BoundingBox::resize(GLfloat xa, GLfloat ya, GLfloat za){
	size.x = xa;
	size.y = ya;
	size.z = za;
}

void BoundingBox::draw(){
	if(showBoxes){
		glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glColor3f(0.0f,0.5f,1.0f);
			glTranslatef(min.x,min.y,min.z);
			glScalef(size.x,size.y,size.z);
			drawCube();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glColor3f(0.5f,0.5f,0.5f);
		glPopMatrix();
	}
}

void BoundingBox::moveBox(GLfloat xDist, GLfloat yDist, GLfloat zDist){
	min.x = min.x+ xDist;
	min.y = min.y+ yDist;
	min.z = min.z+ zDist;
	max.x = max.x+ xDist;
	max.y = max.y+ yDist;
	max.z = max.z+ zDist;

}
//Added by Addison, allows to set the actual position of the collision box... Used for having it follow the position of a specific object
void BoundingBox::lockBox(GLfloat xPos, GLfloat yPos, GLfloat zPos){
	min.x = xPos;
	min.y = yPos;
	min.z = zPos;
	max.x = xPos+size.x;
	max.y = yPos+size.y;
	max.z = zPos+size.z;
}
