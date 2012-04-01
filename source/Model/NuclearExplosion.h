/* 
 * File:   NuclearExplosion.h
 * Author: Jonathan
 *
 * Created on April 1st, 2012, 3:51 PM
 */

#ifndef NUCLEAR_EXPLOSION_MODEL_H
#define	NUCLEAR_EXPLOSION_MODEL_H

#include "Model.h"
#include <time.h>

class NuclearExplosion : public Model {
public:
    NuclearExplosion();
	void render();

private:

	bool topStoppedGrowing;
	bool lightIsEmitting;

	double nukeTime;
	double lightTime;
	double flyTime;

	GLint topRadius;
	GLfloat cylinderHeight;
	GLfloat mushroomHeadSize;
	GLfloat botSize;

	GLfloat lightValue;
	void emitLight();
	void drawHalfACylinder(GLUquadricObj*, GLint);

};

#endif