/* 
 * File:   Base.cpp
 * Author: Addisson
 * 
 * Created on January 31, 2012, 11:38 AM
 */

#include "Base.h"
#include "BaseModel.h"

Base::Base() {
    model = (Model*)(new BaseModel);
    
}

Base::~Base() {
    if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Base::draw() {
    model->draw();
}
