/* 
 * File:   Tracks.cpp
 * Author: Stefanie Lavoie
 * 
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "Tracks.h"
#include "TracksModel.h"

Tracks::Tracks() {
      model = (Model*)(new TracksModel);
}

Tracks::~Tracks() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void Tracks::draw() {
    model->draw();
}
