/* 
 * File:   Fence.cpp
 * Author: robert
 * 
 * Created on January 21, 2012, 9:52 PM
 */

#include "Fence.h"
#include "FenceModel.h"

Fence::Fence() {
    model = (Model*)(new FenceModel);
    
}

Fence::~Fence() {
    if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Fence::draw() {
    model->draw();
}
