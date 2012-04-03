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
#include "../Model/Helper/CollisionTester.h"
#include "../Helper/V3struct.h"
#include <gl\GL.h>

#define MAX_PLAYER_HEIGHT 3
#define MIN_PLAYER_HEIGHT 0
#define SIDE_STEP 0.2f
#define UP_STEP 0.2f
#define DOWN_STEP 0.05f

class PlayerUFO {
public:
	//constructors and destructor
	PlayerUFO(void);
	PlayerUFO(GLfloat x, GLfloat z);
	virtual ~PlayerUFO(void);

	void draw();
    void updateLights(GLfloat xPos, GLfloat yPos, GLfloat zPos);
	
	//translates ufo if no collision
	void incrementHeight(bool positive);
	void incrementXPos(bool positive);
	void incrementZPos(bool positive);
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	V3 getPosition();
	//collision detection
	int ufoCollisionTest(GLfloat x, GLfloat y, GLfloat z);

	GLfloat* pos;
	BoundingBox* box;

private:
	Model* pModel;
    SpotLight* spotLight;
    LightPost* light;
	CollisionTester* ct;
};

#endif
