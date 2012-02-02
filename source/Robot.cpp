#include "Robot.h"
#include "ElectronicsModel.h"
#include "NuclearModel.h"
#include "ElectronicsModel.h"

Robot::Robot() {
	NuclearModel *nuclearModel = new NuclearModel();
    ElectronicsModel *electronicModel = new ElectronicsModel();
    
    head1 = (Model*)nuclearModel;
    head2 = (Model*)electronicModel;
    model = this->head1;
}

Robot::~Robot() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
    /*
    if (head1 != NULL) {
        delete head1;
        head1 = NULL;
    }
    
    if (head2 != NULL) {
        delete head2;
        head2 = NULL;
    }
    */
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
