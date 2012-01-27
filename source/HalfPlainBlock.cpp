/* 
 * File:   HalfPlainBlock.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:24 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "HalfPlainBlock.h"
#include "HalfPlainBlockModel.h"

HalfPlainBlock::HalfPlainBlock() {
      model = (Model*)(new HalfPlainBlockModel);
}

HalfPlainBlock::~HalfPlainBlock() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void HalfPlainBlock::draw() {
    model->draw();
}
