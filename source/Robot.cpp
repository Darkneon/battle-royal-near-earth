#include "Robot.h"
#include "PhaserModel.h"
#include "CannonModel.h"
#include "BipodModel.h"
#include "Bipod.h"
#include "TracksModel.h"
#include "AntiGravModel.h"
#include "MissileLauncherModel.h"

Robot::Robot() {
    head1 = (Model*)(new NuclearModel());
    head2 = (Model*)(new ElectronicsModel());
    
    middle1 = (Model*)(new PhaserModel);
    middle2 = (Model*)(new CannonModel);
    middle3 = (Model*)(new MissileLauncherModel);
    
    bottom1 = (Model*)(new BipodModel);
    bottom2 = (Model*)(new TracksModel);
    bottom3 = (Model*)(new AntiGravModel);
    
    model = bottom3;
    currentMiddle = middle1;
    changeMiddle();
    
    topCounter = 0;
    middleCounter = 0;
    bottomCounter = 0;
        
}

Robot::~Robot() {
    //Deleting the head frees up its children as well */
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
    vector<Model *> children = currentMiddle->getChildren();
    
    switch(topCounter % 2) {
        case 0:
            children[0] = head1;
            break;
        case 1:
            children[0] = head2;
            break;
    }
    
    topCounter += 1;
    currentMiddle->setChildren(children);
}

void Robot::changeMiddle() {
    vector<Model *> children = model->getChildren();    
    vector<Model *> subchildren = children[0]->getChildren();
    
    
    switch(middleCounter % 3) {
        case 0:
            children[0] = middle1;
            middle1->setChildren(subchildren);
            currentMiddle = middle1;
            break;
        case 1:
            children[0] = middle2;
            middle2->setChildren(subchildren);
            currentMiddle = middle2;    
            break;
        case 2:
            children[0] = middle3;
            middle3->setChildren(subchildren);
            currentMiddle = middle3;    
            break;
    }
    
    middleCounter += 1;
    model->setChildren(children);
}

void Robot::changeBottom() {
    vector<Model *> children = model->getChildren();
    
    switch (bottomCounter % 3) {
        case 0:
            model = bottom1;
            break;
        case 1:
            model = bottom2;
            break;
        case 2:
            model = bottom3;
            break;
    }
    
    model->setChildren(children);
    
    bottomCounter += 1;
}

void Robot::draw() {
	model->draw();
    
    glPushMatrix();
        glScalef(.5f, 1, 0.5f);
        glTranslatef(0.75f, 3.5f, 1.9f);
        teamNumberModel.render();
    glPopMatrix();
}
