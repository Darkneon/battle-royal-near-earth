#ifndef BULLET_H
#define	BULLET_H

#include "Model.h"
#include "../Model/Robot/BulletModel.h"
#include "../Model/Helper/BoundingBox.h"

#define MAX_DURATION 100
#define BULLET_STEP_SIZE 0.05f;

class Bullet
{
public:
	Bullet(void);
	Bullet(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz);
	virtual ~Bullet(void);
	void draw();
	V3 getPosition();
	bool isBulletDead();
	void moveBullet();
private:
	Model *model;
	V3 position;
	V3 direction;
	GLfloat duration;
};

#endif