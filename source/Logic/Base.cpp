/* 
 * File:   Base.cpp
 * Author: Addisson
 * 
 * Created on January 31, 2012, 11:38 AM
 */

#include "Base.h"
#include "Buildings/BaseModel.h"

Base::Base() {
    model = (Model*)(new BaseModel);
    xPos = 0;
	zPos = 0;
}

Base::Base(GLfloat x, GLfloat z){
	model = (Model*)(new BaseModel);
    xPos = x;
	zPos = z;
}
Base::~Base() {
    if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Base::draw() {
	glPushMatrix();
		glTranslatef(xPos,0.0f,zPos);
		model->draw();
	glPopMatrix();
}
