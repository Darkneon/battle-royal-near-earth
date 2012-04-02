#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "HumanPlayer.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif
#include <time.h>

class PlayerInput
{
public:
	PlayerInput(HumanPlayer* player, bool *keyStates, bool *funcKeyStates);
	void functionKeyOperations(int keyModifier);
	void keyOperations(int keyModifier);
	void mousePassiveOperations(int x, int y);
	void mouseButtons(int button, int state);
	void attachLevelRenderer(LevelRenderer* lr);

private:
	HumanPlayer* player;
	LevelRenderer* lr;
	bool *keyStates;
	bool *funcKeyStates;
	int *keyModifier;

	double lastPress;
	double currentTime;
};

#endif