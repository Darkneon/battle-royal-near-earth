/* 
 * File:   player.h
 * Author: Robert
 * Modified by: Jonathan
 * Created on January 19, 2012, 3:18 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Model.h"
#include "CommanderCamera.h"
#include "FreeLookCamera.h"
#include "CirclingCamera.h"

class Player 
{
public:
    Player(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane);
    ~Player();
    void draw();

	void changeCamera(int CAMERA);
	void view();
	int getCurrentCameraType();
	Camera *getCurrentCamera();
	
private:
	int currentCamera;
    Model *model;
	Camera *availableCams[3];
};

#endif	/* PLAYER_H */

