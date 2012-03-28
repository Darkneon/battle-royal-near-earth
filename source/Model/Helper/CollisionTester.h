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

#include <vector>
#include "BoundingBox.h"
using namespace std;

class CollisionTester
{
public:
	CollisionTester(void);
	virtual ~CollisionTester(void);
	static vector<BoundingBox *> staticBoxes;
	static vector<BoundingBox *> movingBoxes;
	static GLuint movingBoxId;
	bool collisionTest(GLfloat x, GLfloat y, GLfloat z);
	bool collisionTest(GLfloat x, GLfloat y, GLfloat z, GLuint id);
	bool collision(BoundingBox* b, GLfloat x, GLfloat y, GLfloat z);
	bool collision(BoundingBox* b, GLfloat x, GLfloat y, GLfloat z, GLuint id);
};

#endif