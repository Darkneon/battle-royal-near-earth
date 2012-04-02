#include "Bullet.h"

Bullet::Bullet(void)
{
	//model = (Model*)(new BulletModel);
	model = (Model*)(new MissileModel);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

	direction.x = 0.0f;
	direction.y = 0.0f;
	direction.z = 0.0f;
	degrees = 0.0f;

	duration = MAX_DURATION;

	ct = new CollisionTester;

	box = new BoundingBox(position.x - BULLET_RADIUS, position.y - BULLET_RADIUS, position.z - BULLET_RADIUS, 
		position.x + BULLET_RADIUS, position.y + BULLET_RADIUS, position.z + BULLET_RADIUS, true);
}

Bullet::Bullet(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz, GLfloat degrees){
	//model = (Model*)(new BulletModel);
	model = (Model*)(new MissileModel);
	position.x = px;
	position.y = py;
	position.z = pz;

	direction.x = dx;
	direction.y = dy;
	direction.z = dz;

	this->degrees = degrees+90;

	duration = MAX_DURATION;

	ct = new CollisionTester;

	box = new BoundingBox(position.x - BULLET_RADIUS, position.y - BULLET_RADIUS, position.z - BULLET_RADIUS, 
		position.x + BULLET_RADIUS, position.y + BULLET_RADIUS, position.z + BULLET_RADIUS, true);
}

Bullet::~Bullet(void)
{
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Bullet::draw(){
	if(model != NULL){
		glPushMatrix();
			box->draw();
			glTranslatef(position.x,position.y,position.z);
			glRotatef(degrees,0.0f,1.0f,0.0f);
			model->draw();
			duration--;
		glPopMatrix();
	}
}

V3 Bullet::getPosition(){
	return position;
}

bool Bullet::isBulletDead(){
	return (duration <= 0.0f);
}

void Bullet::moveBullet(){
	GLfloat xDist = direction.x*BULLET_STEP_SIZE;
	GLfloat yDist = direction.y*BULLET_STEP_SIZE;
	GLfloat zDist = direction.z*BULLET_STEP_SIZE;
	if(!bulletCollisionTest(position.x + xDist,position.y + yDist,position.z + zDist)){
		//no potential collision -> move
		position.x += xDist;
		position.y += yDist;
		position.z += zDist;
		box->moveBox(xDist, yDist, zDist);
	}
	else{
		//potential collision -> die
		duration = 0;
	}
}

bool Bullet::bulletCollisionTest(GLfloat x, GLfloat y, GLfloat z){
	if(ct->bulletCollTest(x,y,z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x+box->size.x, y, z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x,	y,z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x+box->size.x,	y,z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x,	y+box->size.y, z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x+box->size.x,	y+box->size.y,z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x,	y+box->size.y,z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->bulletCollTest(x+box->size.x,	y+box->size.y,z+box->size.z,box->movingBoxId)){
			return true;
		}

		return false;
}
