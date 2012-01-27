/* 
 * File:   Pit.cpp
 * Author: Jeffrey
 * 
 * Created on January 21, 2012, 9:17 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "Pit.h"
#include "PitModel.h"

Pit::Pit() {
      model = (Model*)(new PitModel(true));
}

Pit::~Pit() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Pit::switchPitType()
{
	((PitModel*)model)->switchPitType();
}

void Pit::draw() {
    model->draw();
}
