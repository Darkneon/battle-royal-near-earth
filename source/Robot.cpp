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

void Robot::changeTop() {
    vector<Model *> children = model->getChildren();
    
    if (model != head1) {
        model = head1;
    }
    else {
        model = head2;
    }
    
    model->setChildre(children);
}

void Robot::draw() {
	model->draw();
}
