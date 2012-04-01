#ifndef BULLET_H
#define	BULLET_H

#include "Model.h"
#include "../Model/Robot/BulletModel.h"
#include "../Model/Helper/BoundingBox.h"
#include "../Model/Helper/CollisionTester.h"
#include "../Model/MissileModel.h"

#define MAX_DURATION 5000
#define BULLET_STEP_SIZE 0.5f;

class Bullet
{
public:
	Bullet(void);
	Bullet(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz, GLfloat degrees);
	virtual ~Bullet(void);
	void draw();
	V3 getPosition();
	bool isBulletDead();
	void moveBullet();
	bool bulletCollisionTest(GLfloat x, GLfloat y, GLfloat z);

private:
	Model *model;
	BoundingBox *box;
	V3 position;
	V3 direction;
	GLfloat duration;
	CollisionTester* ct;
	GLfloat degrees;
};

#endif