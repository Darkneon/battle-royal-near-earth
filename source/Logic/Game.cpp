#include "Game.h"

Game::Game(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane,
	bool *keyStates, bool *funcKeyStates)
{
	p1 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane,30.0f,30.0f);
	//p2 = new Player(40.0f, 35.0f);
	p2 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 0.0f, 0.0f);
		
	playerInput1 = new PlayerInput(p1, keyStates, funcKeyStates);
	playerInput2 = new JoystickInput(p2);

	lr = new LevelRenderer();

	this->viewHeight = viewHeight;
	this->viewWidth = viewWidth;

	isTwoPlayerGame = false;
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

void Game::toggleTwoPlayerMode()
{
	isTwoPlayerGame = !isTwoPlayerGame;
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
	if (isTwoPlayerGame)
	{
		p1->view();
		renderScene();
		glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight / 2);
		
		p2->view();
		renderScene();
		glViewport(0, (GLint)viewHeight / 2, (GLsizei)viewWidth, (GLsizei)viewHeight / 2);
		
	}
	else
	{
		renderScene();
		p1->view();	
	}	
}

void Game::renderScene()
{
	lr->render();
	p1->render();
	p2->render();
}