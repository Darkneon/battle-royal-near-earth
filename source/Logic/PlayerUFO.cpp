#include "PlayerUFO.h"

PlayerUFO::PlayerUFO(void)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;

	pos = new GLfloat[3];
	pos[0] = 0.0f;
	pos[1] = 0.0f;
	pos[2] = 0.0f;
	box = new BoundingBox(pos[0],pos[1],pos[2],pos[0]+1.0f,pos[1]+1.0f,pos[2]+1.0f);
}

PlayerUFO::PlayerUFO(GLfloat x, GLfloat z)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = x;
	pos[1] = 0;
	pos[2] = z;
	box = new BoundingBox(pos[0],pos[1],pos[2],pos[0]+1.0f,pos[1]+1.0f,pos[2]+1.0f);
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
			box->draw();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(pos[0],pos[1],pos[2]);
		pModel->draw();
	glPopMatrix();
}

void PlayerUFO::incrementHeight(bool positive){
	if(positive){
		if(pos[1]+0.05f <= MAX_PLAYER_HEIGHT){
			pos[1] += 0.05f;
			box->moveBox(0.0f,0.05f,0.0f);
		}
	}
	else{
		if(pos[1]-0.02f >= MIN_PLAYER_HEIGHT){
			pos[1] -= 0.02f;
			box->moveBox(0.0f,-0.02f,0.00f);
		}
	}
}

void PlayerUFO::incrementXPos(bool positive){
	if(positive){
		pos[0] += 0.05f;
		box->moveBox(0.05f,0.0f,0.0f);
	}
	else{
		pos[0] -= 0.05f;
		box->moveBox(-0.05f,0.0f,0.0f);
	}
}

void PlayerUFO::incrementZPos(bool positive){
	if(positive){
		pos[2] += 0.05f;
		box->moveBox(0.0f,0.0f,0.05f);
	}
	else{
		pos[2] -= 0.05f;
		box->moveBox(0.0f,0.0f,-0.05f);
	}
}