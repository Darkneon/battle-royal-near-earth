/* 
 * File:   HalfHollowBlock.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 6:44 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "HalfHollowBlock.h"
#include "HalfHollowBlockModel.h"

HalfHollowBlock::HalfHollowBlock() {
      model = (Model*)(new HalfHollowBlockModel);
}

HalfHollowBlock::~HalfHollowBlock() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void HalfHollowBlock::draw() {
    model->draw();
}
