/* 
 * File:   PlainBlock.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:16 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "PlainBlock.h"
#include "PlainBlockModel.h"

PlainBlock::PlainBlock() {
      model = (Model*)(new PlainBlockModel);
}

PlainBlock::~PlainBlock() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void PlainBlock::draw() {
    model->draw();
}
