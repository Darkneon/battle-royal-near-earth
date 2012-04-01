/* 
 * File:   HumanPlayer.h
 * Author: Jeff
 * Created on March 24, 2012
 */

#ifndef HUMANPLAYER_H
#define	HUMANPLAYER_H

#include "Model.h"
#include "CommanderCamera.h"
#include "FreeLookCamera.h"
#include "CirclingCamera.h"
#include "RobotCamera.h"
#include "LightCamera.h"
#include "FollowCamera.h"
#include "Player.h"
#include "PlayerUFO.h"
#include "../Helper/V3struct.h"


class HumanPlayer : public Player
{
public:
    HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF);
	HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF, GLfloat spawnX, GLfloat spawnZ);
	HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF, GLfloat spawnX, GLfloat spawnZ, bool hasUFO);
    ~HumanPlayer();
    void render();

	void changeCamera(int CAMERA);
	void view();
	int getCurrentCameraType();
	Camera *getCurrentCamera();
	void selectRobotView(Robot* robo);
	void levitateUFO();
	void moveUFOX(bool direction);
	void moveUFOZ(bool direction);
	void controlRobotAt(int index);

	int getScore();
	void increaseScore(int value = 1);

private:
	int score;
	bool robotUfoLock;
	int currentCamera;
	Camera *availableCams[9];
	PlayerUFO* ufo;

	bool aRobotIsSelected;

	void getUFOPosition(V3 p);
	void setUFOPosition(GLfloat setX, GLfloat setY, GLfloat setZ);
	bool getRobotPosition(V3 p, int vectorIndex);
	void lockRobotAndUfo();
};

#endif	/* HUMANPLAYER_H */