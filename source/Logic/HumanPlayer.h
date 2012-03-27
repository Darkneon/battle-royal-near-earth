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


class HumanPlayer : public Player
{
public:
    HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF);
	HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF, GLfloat spawnX, GLfloat spawnZ);
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

private:
	int currentCamera;
   // Model *model;
	Camera *availableCams[9];
	PlayerUFO* ufo;
};

#endif	/* HUMANPLAYER_H */