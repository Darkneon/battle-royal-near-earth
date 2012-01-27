/* 
 * File:   Phaser.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 3:11 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "Phaser.h"
#include "PhaserModel.h"

Phaser::Phaser() {
      model = (Model*)(new PhaserModel);
}

Phaser::~Phaser() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Phaser::draw() {
    model->draw();
}
