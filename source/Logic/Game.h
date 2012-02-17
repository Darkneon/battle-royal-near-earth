//Jonathan's Class

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "PlayerInput.h"

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
	
	Player* p1;
	PlayerInput* playerInput1;

	void updateGameState(); // Modification to the game logic here, no drawing here
	void getInput(int keyModifier); //gets user input

private:
	
};

#endif