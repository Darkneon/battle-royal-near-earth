#include "Game.h"

Game::Game(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane,
	bool *keyStates, bool *funcKeyStates)
{
	//p1 = (Player*)new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	p1 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	playerInput1 = new PlayerInput(p1, keyStates, funcKeyStates);
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

void Game::render(){
	lr->render();
	p1->render();
	p1->view();
}