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

#include <cstdlib>
#include <vector>
using namespace std;

struct V3{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

class BoundingBox {

public:

	static bool showBoxes;
	static GLuint movingCount;
	GLuint movingBoxId;
	
	BoundingBox(void);
	BoundingBox(V3 min, V3 max);
	BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ);
	BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ, bool moving);
	virtual ~BoundingBox(void);
	V3 min;
	V3 max;
	V3 size;
	void draw();
	void draw2();
	void resize(GLfloat xa, GLfloat ya, GLfloat za);
	void moveBox(GLfloat xDist, GLfloat yDist, GLfloat zDist);
	bool collision(GLfloat x, GLfloat y, GLfloat z);


private:
	void drawSquare();
	void drawCube();
};

#endif /*BOUNDING_BOX_H*/