#include "Player.h"
#include "Player/PlayerModel.h"

Player::Player() {
	//init spawn points
	spawnPtX = 25.0f;
	spawnPtZ = 25.0f;
	//init base
	base = new Base(spawnPtX-2,spawnPtZ-4);
	//init robots
	selectedRobot = 0;
	Robot* newRobot = new Robot(spawnPtX, spawnPtZ);
	robots.push_back(newRobot);
	newRobot = NULL;
	delete newRobot;
}

Player::Player(GLfloat spawnX, GLfloat spawnZ) {
	//init spawn points
	spawnPtX = spawnX;
	spawnPtZ = spawnZ;

	//init base
	base = new Base(spawnPtX-2,spawnPtZ-4);

	//init robots
	selectedRobot = 0;
	Robot* newRobot = new Robot(spawnPtX, spawnPtZ);
	robots.push_back(newRobot);
	newRobot = NULL;
	delete newRobot;
}

Player::~Player() {    
	robots.clear();
}

bool Player::addRobot(){
	if(robots.size() < MAX_ROBOTS){
		//if enough room -> push robot
		Robot* newRobot = new Robot;
		robots.push_back(newRobot);
		//delete pointer
		newRobot = NULL;
		delete newRobot;
		return true;
	}
	else{
		return false;
	}
}

void Player::selectRobot(int i){
	selectedRobot = i;
}

void Player::render(){
	//base->draw();
	//keep drawing until all the children are done
    for(int j = 0; j < (int)robots.size(); j++){
		robots.at(j)->draw();
	}
}

static int respawnLocation = 0;

void Player::respawn()
{
	robots.at(0)->robotLife = MAX_LIFE;
	robots.at(0)->isAlive = true;
	
	 // this is a really bad way of doing this but our structure would require too much time to change
	respawnLocation = respawnLocation++ % 3;

	switch(respawnLocation)
	{
	case (0):
		robots.at(0)->xPos = 28.0f;
		robots.at(0)->zPos = 10.0f;
		break;

	case (1):
		robots.at(0)->xPos = 4.0f;
		robots.at(0)->zPos = 6.0f;
		break;

	case (2):
		robots.at(0)->xPos = 28.0f;
		robots.at(0)->zPos = 28.0f;
		break;
	};

	if (robots.at(0)->box != NULL)
		delete robots.at(0)->box;
	robots.at(0)->box = new BoundingBox(robots.at(0)->xPos,0.0f,robots.at(0)->zPos,robots.at(0)->xPos+1.0f,robots.at(0)->height,
		robots.at(0)->zPos+1.0f, true, robots.at(0));

	glutPostRedisplay();
}
