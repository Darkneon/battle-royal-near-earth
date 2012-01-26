/* 
 * File:   Grass.cpp
 * Author: robert
 * 
 * Created on January 26, 2012, 1:34 PM
 */

#include "Grass.h"
#include "GrassModel.h"
Grass::Grass() {
    GrassModel* gm = new GrassModel();
    model = (Model*)gm;
}

Grass::~Grass() {
    if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Grass::draw() {
    model->draw();
}

