//Jonathan's Class

#ifndef GAME_H
#define GAME_H

#include "LevelRenderer.h"
#include "Player.h"
#include "PlayerInput.h"
#include "JoystickInput.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <string>
#include "../Model/Buildings/FlagModel.h"
#include "MissileModel.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

class Game
{
public:
	Game(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane, 
		bool *keyStates, bool *funcKeyStates);
	~Game();
	
	HumanPlayer* p1;
	HumanPlayer* p2;
	int player1Score;
	int player2Score;
	//bool noDisplayList;
        FlagModel* flag;
	PlayerInput* playerInput1;
	JoystickInput* playerInput2;
	LevelRenderer* lr;
	MissileModel mm;
        GLfloat rows;
        GLfloat columns;
	void render();
	void getInput(int keyModifier); //gets user input
	void setMap(string mapName);
};

#endif