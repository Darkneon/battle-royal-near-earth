/* 
 * File:   AntiGrav.cpp
 * Author: Stefanie Lavoie
 * 
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "AntiGrav.h"
#include "AntiGravModel.h"

AntiGrav::AntiGrav() {
      model = (Model*)(new AntiGravModel);
}

AntiGrav::~AntiGrav() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void AntiGrav::draw() {
    model->draw();
}
