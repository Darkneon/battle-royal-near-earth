/* 
 * File:   HollowBlock.cpp
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


#include "HollowBlock.h"
#include "HollowBlockModel.h"

HollowBlock::HollowBlock() {
      model = (Model*)(new HollowBlockModel);
}

HollowBlock::~HollowBlock() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void HollowBlock::draw() {
    model->draw();
}
