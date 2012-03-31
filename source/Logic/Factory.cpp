/* 
 * File:   Factory.cpp
 * Author: Addisson
 * 
 * Created on February 2, 2012, 2:19 PM
 */

#include "Factory.h"
#include "Buildings/FactoryModel.h"

Factory::Factory() {
    model = (Model*)(new FactoryModel);
}

Factory::~Factory() {
    if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Factory::draw() {
    model->draw();
}
