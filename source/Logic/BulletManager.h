#ifndef BULLET_MANAGER_H
#define	BULLET_MANAGER_H

#include "Bullet.h"
#include "../Model/Helper/BoundingBox.h"

class BulletManager
{
public:
	BulletManager(void);
	~BulletManager(void);

	static vector<Bullet *> bullets;

	void addBullet(Bullet* b);
	void addBullet(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz);
	void moveBullets();
	void drawBullets();
	void cleanUpBullets();

};

#endif