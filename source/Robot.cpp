#include "Robot.h"
#include "PhaserModel.h"
#include "CannonModel.h"
#include "BipodModel.h"
#include "Bipod.h"
#include "TracksModel.h"
#include "AntiGravModel.h"

Robot::Robot() {
    NuclearModel *nuclearModel = new NuclearModel();
    ElectronicsModel *electronicModel = new ElectronicsModel();
    
    head1 = (Model*)nuclearModel;
    head2 = (Model*)electronicModel;
    
    
    middle1 = (Model*)(new PhaserModel);
    middle2 = (Model*)(new CannonModel);
    
    
    bottom1 = (Model*)(new BipodModel);
    bottom2 = (Model*)(new TracksModel);
    bottom3 = (Model*)(new AntiGravModel);
    
    model = head1;
    currentMiddle = middle1;
    changeMiddle();
    
    bottomCounter = 0;

}

Robot::~Robot() {
    //Deleting the head frees up its children as well
    
    if (head1 != NULL) {
        delete head1;
        head1 = NULL;
    }
    
    if (head2 != NULL) {
        delete head2;
        head2 = NULL;
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
    
    model->setChildren(children);
}

void Robot::changeMiddle() {
    vector<Model *> children = model->getChildren();    
    vector<Model *> subchildren = children[0]->getChildren();
    
    
    if (children[0] != middle1) {
        children[0] = middle1;
        middle1->setChildren(subchildren);
        currentMiddle = middle1;
    }
    else {
        children[0] = middle2;
        middle2->setChildren(subchildren);
        currentMiddle = middle2;
    }   
    
    model->setChildren(children);
}

void Robot::changeBottom() {
    vector<Model *> children = currentMiddle->getChildren();
    
    switch (bottomCounter % 3) {
        case 0:
            children[0] = bottom1;
            break;
        case 1:
            children[0] = bottom2;
            break;
        case 2:
            children[0] = bottom3;
            break;
    }
    
    currentMiddle->setChildren(children);
    
    bottomCounter += 1;
}

void Robot::draw() {
	model->draw();
}
