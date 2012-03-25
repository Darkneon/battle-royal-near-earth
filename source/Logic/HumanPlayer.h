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
#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF);
	HumanPlayer(GLint viewW, GLint viewH, GLfloat viewN, GLfloat viewF, GLfloat spawnX, GLfloat spawnZ);
    ~HumanPlayer();
    void draw();

	void changeCamera(int CAMERA);
	void view();
	int getCurrentCameraType();
	Camera *getCurrentCamera();
	void selectRobotView(Robot* robo);
	
private:
	int currentCamera;
    Model *model;
	Camera *availableCams[8];

	GLfloat ufoXPos;
	GLfloat ufoZPos;
};

#endif	/* HUMANPLAYER_H */