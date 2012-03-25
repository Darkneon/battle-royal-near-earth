/* 
 * File:   PlayerUFO.h
 * Author: Jeff
 * Created on March 25, 2012
 */

#ifndef PLAYERUFO_H
#define	PLAYERUFO_H

#include "../Model/Player/PlayerModel.h"
#define MAX_PLAYER_HEIGHT 2
#define MIN_PLAYER_HEIGHT 0

class PlayerUFO {
public:
	PlayerUFO(void);
	PlayerUFO(GLfloat x, GLfloat z);
	virtual ~PlayerUFO(void);
	void draw();
	void incrementHeight(bool positive);

private:
	Model* pModel;
	GLfloat* pos;
};

#endif
