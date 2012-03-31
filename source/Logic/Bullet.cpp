#include "Bullet.h"

Bullet::Bullet(void)
{
	model = (Model*)(new BulletModel);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

	direction.x = 0.0f;
	direction.y = 0.0f;
	direction.z = 0.0f;

	duration = MAX_DURATION;
}

Bullet::Bullet(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz){
	model = (Model*)(new BulletModel);
	position.x = px;
	position.y = py;
	position.z = pz;

	direction.x = dx;
	direction.y = dy;
	direction.z = dz;

	duration = MAX_DURATION;
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
			glTranslatef(position.x,position.y,position.z);
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
	position.x += direction.x*BULLET_STEP_SIZE;
	position.y += direction.y*BULLET_STEP_SIZE;
	position.z += direction.z*BULLET_STEP_SIZE;
}