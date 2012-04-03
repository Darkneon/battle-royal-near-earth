#include "Game.h"

Game::Game(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane,
	bool *keyStates, bool *funcKeyStates)
{

	/*if (twoPlayerIsOn)
		p1 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 4.0f, 6.0f, false);
	else*/
	p1 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 4.0f, 6.0f, true);

	p2 = new HumanPlayer(viewWidth, viewHeight, viewNearPlane, viewFarPlane, 28.0f, 10.0f, false);
	p2->robots.at(0)->computerControlled = true;

	playerInput1 = new PlayerInput(p1, keyStates, funcKeyStates);
	playerInput2 = new JoystickInput(p2);

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

	if (twoPlayerIsOn)
	{

		if(player1Score >= 10 || player2Score >= 10)
		{
			if (ct->nukePowerUpCollisionTest(4.0f,0.5f,28.0f,100)){
				aNukeWentOff = true;
				twoPlayerIsOn = false;
				*gameOver = true;
			}
		}

		if (p1->robots.at(0)->robotLife <= 0.0f && p1->robots.at(0)->isAlive)
		{
			player2Score++;
			p1->robots.at(0)->isAlive = false;
		}

		if (p2->robots.at(0)->robotLife <= 0.0f && p2->robots.at(0)->isAlive)
		{
			player1Score++;
			p2->robots.at(0)->isAlive = false;
		}

	}
}

void Game::getInput(int keyModifier)
{
	playerInput1->functionKeyOperations(keyModifier);
	playerInput1->keyOperations(keyModifier);
}

void Game::render()
{
    glPushMatrix();
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

	if (twoPlayerIsOn){
		if(player1Score >= 10 || player2Score >= 10){
			nukePowerUp->draw();
		}
	}
	glPopMatrix();
}

void Game::setMap(string mapName){
	lr = new LevelRenderer(mapName);
	playerInput1->attachLevelRenderer(lr);
}