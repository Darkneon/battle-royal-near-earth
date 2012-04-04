#include "Game.h"

Game::Game(string mapName, bool *keyStates, bool *funcKeyStates, bool isTwoPlayer)
{

	lr = new LevelRenderer(mapName);
	if (isTwoPlayer)
		p1 = new HumanPlayer(lr->getCenterOfMapX(), lr->getCenterOfMapZ(), 4.0f, 6.0f, false, (GLfloat)lr->rows, (GLfloat)lr->columns);
	else
		p1 = new HumanPlayer(lr->getCenterOfMapX(), lr->getCenterOfMapZ(), 4.0f, 6.0f, true, (GLfloat)lr->rows, (GLfloat)lr->columns);

	p2 = new HumanPlayer(lr->getCenterOfMapX(), lr->getCenterOfMapZ(), 28.0f, 10.0f, false, (GLfloat)lr->rows, (GLfloat)lr->columns);

	p2->robots.at(0)->computerControlled = true;

	playerInput1 = new PlayerInput(p1, keyStates, funcKeyStates);
	playerInput1->attachLevelRenderer(lr);
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

		if(player1Score >= KILL_LIMIT || player2Score >= KILL_LIMIT)
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
        //Sets rows and columns for use with rendering shadows
        rows = (GLfloat)lr->rows;
        columns = (GLfloat)lr->columns;
        p1->rows = rows;
        p1->columns = columns;
        p2->rows = rows;
        p2->columns = columns;
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
		if(player1Score >= KILL_LIMIT || player2Score >= KILL_LIMIT){
			nukePowerUp->draw();
		}
	}
	glPopMatrix();
}
