#include "Player.h"
#include "PlayerModel.h"


Player::Player() {
    PlayerModel *pm = new PlayerModel;
    model = (Model*)pm;
}

Player::~Player() {    
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Player::draw() {
    model->draw();
}