/* 
 * File:   PlayerUFO.h
 * Author: Jeff
 * Created on March 25, 2012
 */

#ifndef PLAYERUFO_H
#define	PLAYERUFO_H

#include "../Model/Player/PlayerModel.h"
#include "../Model/Helper/BoundingBox.h"
#define MAX_PLAYER_HEIGHT 2
#define MIN_PLAYER_HEIGHT 0

class PlayerUFO {
public:
	PlayerUFO(void);
	PlayerUFO(GLfloat x, GLfloat z);
	virtual ~PlayerUFO(void);
	void draw();
	void incrementHeight(bool positive);
	GLfloat* pos;
	BoundingBox* box;

	void incrementXPos(bool positive);
	void incrementZPos(bool positive);

private:
	Model* pModel;
};

#endif
