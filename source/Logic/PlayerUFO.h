/* 
 * File:   PlayerUFO.h
 * Author: Jeff
 * Created on March 25, 2012
 */

#ifndef PLAYERUFO_H
#define	PLAYERUFO_H

#include "../Model/Player/PlayerModel.h"
#include "SpotLight.h"
#include "../Model/Light/LightPost.h"
#include "../Model/Helper/BoundingBox.h"
#define MAX_PLAYER_HEIGHT 8
#define MIN_PLAYER_HEIGHT 0

class PlayerUFO {
public:
	PlayerUFO(void);
	PlayerUFO(GLfloat x, GLfloat z);
	virtual ~PlayerUFO(void);
	void draw();
        void updateLights(GLfloat xPos, GLfloat yPos, GLfloat zPos);
	void incrementHeight(bool positive);
	GLfloat* pos;
	BoundingBox* box;

	void incrementXPos(bool positive);
	void incrementZPos(bool positive);

	bool ufoCollisionTest(GLfloat x, GLfloat y, GLfloat z);

private:
	Model* pModel;
        SpotLight* spotLight;
        LightPost* light;
        
	CollisionTester* ct;
};

#endif
