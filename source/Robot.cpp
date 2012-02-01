#include "Robot.h"

Robot::Robot() {
	NuclearModel *nuclearModel = new NuclearModel();
	model = (Model*)nuclearModel;
}

Robot::~Robot() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Robot::draw() {
	model->draw();
}
