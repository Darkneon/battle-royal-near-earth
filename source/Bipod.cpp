/* 
 * File:   Bipod.cpp
 * Author: Stefanie Lavoie
 * 
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "Bipod.h"
#include "BipodModel.h"

Bipod::Bipod() {
      model = (Model*)(new BipodModel);
}

Bipod::~Bipod() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Bipod::draw() {
    model->draw();
}
