#include "Game.h"

Game::Game(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane,
	bool *keyStates, bool *funcKeyStates)
{
	p1 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 4.0f, 6.0f, true);
	p2 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 28.0f, 10.0f, false);
		
	playerInput1 = new PlayerInput(p1, keyStates, funcKeyStates);
	playerInput2 = new JoystickInput(p2);

	lr = new LevelRenderer();

	player1Score = 0;
	player2Score = 0;

	nukePowerUp = new NukePowerUp(4.0f, 28.0f);
	nuke = new NuclearExplosion();

	twoPlayerIsOn = false;
	aNukeWentOff = false;

	ct = new CollisionTester(p1->robots.at(0)->getRobotId(), 
		p2->robots.at(0)->getRobotId());
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

void Game::update(bool* gameOver)
{
	Robot* r1 = p1->robots.at(0);
	Robot* r2 = p2->robots.at(0);

	if (ct->nukePowerUpCollisionTest(r1->xPos, r1->height, r1->zPos, r1->getRobotId()) || 
		ct->nukePowerUpCollisionTest(r2->xPos, r2->height, r2->zPos, r2->getRobotId()))
	{
		aNukeWentOff = true;
		twoPlayerIsOn = false;
		*gameOver = true;
	}
	
}

void Game::getInput(int keyModifier)
{
	playerInput1->functionKeyOperations(keyModifier);
	playerInput1->keyOperations(keyModifier);
}

void Game::render()
{
	lr->render();

	if (aNukeWentOff)
	{
		glPushMatrix();
			glTranslatef(15.0f, 0.0f, 15.0f);
			glScalef(3.0f, 1.5f, 3.0f);
			nuke->render();
		glPopMatrix();
	}
	else
	{
		p1->render();
		p2->render();
	}

	if (twoPlayerIsOn)
		nukePowerUp->draw();
}