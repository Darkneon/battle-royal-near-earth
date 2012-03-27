//Jonathan's Class

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "PlayerInput.h"
#include "HumanPlayer.h"
#include "LevelRenderer.h"
#include "AIPlayer.h"

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
	Player* p2;
	PlayerInput* playerInput1;
	LevelRenderer* lr;

	void render();
	void updateGameState(); // Modification to the game logic here, no drawing here
	void getInput(int keyModifier); //gets user input

	void toggleTwoPlayerMode();

private:
	bool isTwoPlayerGame;
	void renderScene();
	GLint viewHeight, viewWidth;
};

#endif