#include "BulletManager.h"
vector<Bullet *> BulletManager::bullets;

BulletManager::BulletManager(void){}

BulletManager::~BulletManager(void){}

void BulletManager::addBullet(Bullet* b){
	bullets.push_back(b);
}

void BulletManager::addBullet(GLfloat px, GLfloat py, GLfloat pz, GLfloat dx, GLfloat dy, GLfloat dz, GLfloat degrees){
	Bullet *b = new Bullet(px,py,pz,dx,dy,dz,degrees);
	bullets.push_back(b);
	b = NULL;
}

void BulletManager::moveBullets(){
	for(int i = 0; i < (int)(bullets.size()); i++){
		bullets.at(i)->moveBullet();
	}
}

void BulletManager::drawBullets(){
	bool cleanUp = false;
	for(int i = 0; i < (int)(bullets.size()); i++){
		bullets.at(i)->draw();
		bullets.at(i)->moveBullet();
		if(bullets.at(i)->isBulletDead()){
			cleanUp = true;
		}	
	}
	if(cleanUp){
			cleanUpBullets();
	}
}

void BulletManager::cleanUpBullets(){
	for(int i = 0; i < (int)(bullets.size()); i++){
		if(bullets.at(i)->isBulletDead()){
			bullets.erase(bullets.begin()+i);
		}
	}
}
