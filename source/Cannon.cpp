/* 
 * File:   Cannon.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:08 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "Cannon.h"
#include "CannonModel.h"

Cannon::Cannon() {
      model = (Model*)(new CannonModel);
}

Cannon::~Cannon() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Cannon::draw() {
    model->draw();
}
