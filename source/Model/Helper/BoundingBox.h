/* 
 * File:   boundingbox.h
 * Author: jeff
 *
 * Created on March 26, 2012
 */

#ifndef BOUNDING_BOX_H
#define	BOUNDING_BOX_H

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

struct V3{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

class BoundingBox
{
public:
	BoundingBox(void);
	BoundingBox(V3 min, V3 max);
	BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ);
	virtual ~BoundingBox(void);
	V3 min;
	V3 max;
};

#endif