/* 
 * File:   MissileLauncher.cpp
 * Author: Jonathan
 * 
 * Created on January 26, 2012, 7:33 PM
 */

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


#include "MissileLauncher.h"
#include "MissileLauncherModel.h"

MissileLauncher::MissileLauncher() {
      model = (Model*)(new MissileLauncherModel);
}

MissileLauncher::~MissileLauncher() {
	if (model != NULL) {
		delete model;
		model = NULL;
	}
}

void MissileLauncher::draw() {
    model->draw();
}
