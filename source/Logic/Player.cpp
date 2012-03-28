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

