/* 
 * File:   PlayerUFO.h
 * Author: Jeff
 * Created on March 25, 2012
 */

#ifndef COLLISION_TESTER_H
#define	COLLISION_TESTER_H

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "BoundingBox.h"

#include <vector>
using namespace std;

class CollisionTester
{
public:
	CollisionTester(void);
	virtual ~CollisionTester(void);
	//list of all boxes (not just static)
	static vector<BoundingBox *> staticBoxes;
	//tests collision on one bounding box
	bool collision(BoundingBox* b, GLfloat x, GLfloat y, GLfloat z, GLuint id);
	//tests collision on every bounding box
	bool collisionTest(GLfloat x, GLfloat y, GLfloat z, GLuint id);
	bool bulletCollTest(GLfloat x, GLfloat y, GLfloat z, GLuint id);
};

#endif