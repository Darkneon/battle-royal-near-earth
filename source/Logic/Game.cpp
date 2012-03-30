#include "Game.h"


Game::Game(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane,
	bool *keyStates, bool *funcKeyStates)
{
	p1 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 4.0f, 6.0f);
	p2 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 28.0f, 10.0f);
		
	playerInput1 = new PlayerInput(p1, keyStates, funcKeyStates);
	playerInput2 = new JoystickInput(p2);

	lr = new LevelRenderer();
}

Game::~Game()
{
	if (p1 != NULL)
	{
		delete p1;
		p1 = NULL;
	}

	if (playerInput1 != NULL)
	{
		delete playerInput1;
		playerInput1 = NULL;
	}
}

void Game::updateGameState()
{
	
}

void Game::getInput(int keyModifier)
{
	playerInput1->functionKeyOperations(keyModifier);
	playerInput1->keyOperations(keyModifier);
}

void Game::render()
{
	/*
	glPushMatrix();
		glTranslatef(30.0f, 1.0f, 30.0f);

	mm.render();
	glPopMatrix();

	*/

	lr->render();	
	p1->render();
	p2->render();
}