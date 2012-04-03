/* 
 * File:   player.h
 * Author: Robert
 * Modified by: Jonathan, Jeff
 * Created on January 19, 2012, 3:18 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <cstdlib>
#include <vector>

#include "Robot.h"
#include "Base.h"

#define MAX_ROBOTS 2

class Player 
{
public:
	Player();
	Player(GLfloat spawnX, GLfloat spawnZ);
    ~Player();
	bool addRobot();
	void selectRobot(int i);
	virtual void render();
	
	vector<Robot *> robots;
	int selectedRobot;
	Base* base;
        GLfloat rows;
        GLfloat columns;

protected:
	GLfloat spawnPtX;
	GLfloat spawnPtZ;

};

#endif	/* PLAYER_H */