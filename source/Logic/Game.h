//Jonathan's Class

#ifndef GAME_H
#define GAME_H


#include "../Model/Helper/CollisionTester.h"
#include "NukePowerUp.h"
#include "LevelRenderer.h"
#include "Player.h"
#include "NuclearExplosion.h"
#include "PlayerInput.h"
#include "JoystickInput.h"
#include "HumanPlayer.h"
#include <string>



#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif
	

class Game
{
public:
	Game(GLint viewWidth, GLint viewHeight, GLdouble viewNearPlane, GLdouble viewFarPlane, 
		bool *keyStates, bool *funcKeyStates, bool isTwoPlayer);
	~Game();
	
	HumanPlayer* p1;
	HumanPlayer* p2;
	int player1Score;
	int player2Score;
	//bool noDisplayList;

	bool twoPlayerIsOn;
	bool aNukeWentOff;

	PlayerInput* playerInput1;
	JoystickInput* playerInput2;
	LevelRenderer* lr;
	NuclearExplosion* nuke;
	NukePowerUp* nukePowerUp;

	CollisionTester* ct;

	void render();
	void update(bool* gameOver);
	void getInput(int keyModifier); //gets user input
	void setMap(string mapName);
};



#endif