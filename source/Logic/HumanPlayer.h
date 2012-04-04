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
	HumanPlayer(GLfloat centerOfMapX, GLfloat CenterOfMapZ, GLfloat spawnX, GLfloat spawnZ, bool hasUFO);
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
	void robotStrafe(bool negate, int vectorIndex);
	void robotForward(bool negate, int vectorIndex);
	void ufoSetDestination(int vectorIndex);
	void lockRobotAndUfo();
	void cycleThroughComponents(int vectorIndex);
	void toggleComponentOn(int vectorIndex);
	void toggleComponentOff(int vectorIndex);
    PlayerUFO* getUFO() { return ufo; };
    void setEnvMap(bool value) { hasEnvMap = value; }
private:
	bool robotUfoLock;
	int currentCamera;
	int currentComponent;
	Camera *availableCams[9];
	PlayerUFO* ufo;

	bool aRobotIsSelected;
    bool hasEnvMap;
    
	void setUFOPosition(GLfloat setX, GLfloat setY, GLfloat setZ);
	void setUFOPosition(V3 v);
	void setRobotDestination(GLfloat x, GLfloat y, GLfloat z);


};

#endif	/* HUMANPLAYER_H */