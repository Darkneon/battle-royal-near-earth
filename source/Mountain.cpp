/* 
 * File:   Mountain.cpp
 * Author: robert
 * 
 * Created on January 21, 2012, 10:43 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "Mountain.h"
#include "MountainModel.h"

Mountain::Mountain() {
      model = (Model*)(new MountainModel);
}

Mountain::~Mountain() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Mountain::draw() {
    model->draw();
}
