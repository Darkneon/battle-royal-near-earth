#include "PlayerUFO.h"

PlayerUFO::PlayerUFO(void)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;

	pos = new GLfloat[3];
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
}

PlayerUFO::PlayerUFO(GLfloat x, GLfloat z)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = x;
	pos[1] = 0;
	pos[2] = z;
}

PlayerUFO::~PlayerUFO(void)
{
	if (pModel != NULL) {
		delete pModel;
		pModel = NULL;
	}
}

void PlayerUFO::draw(){
	incrementHeight(false);
	glPushMatrix();
		glTranslatef(pos[0],pos[1],pos[2]);
		pModel->draw();
	glPopMatrix();
}

void PlayerUFO::incrementHeight(bool positive){
	if(positive){
		if(pos[1]+0.05f <= MAX_PLAYER_HEIGHT){
			pos[1] += 0.05f;
		}
	}
	else{
		if(pos[1]-0.02f >= MIN_PLAYER_HEIGHT){
			pos[1] -= 0.02f;
		}
	}
}