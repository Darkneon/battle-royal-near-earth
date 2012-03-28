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
	
	//coordinates
	V3 min;
	V3 max;
	V3 size;

	//Constructors and Destructor
	BoundingBox(void);
	BoundingBox(V3 min, V3 max);
	BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ);
	BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ, bool moving);
	virtual ~BoundingBox(void);
	
	//box size, placement and drawing
	void draw();
	void resize(GLfloat xa, GLfloat ya, GLfloat za);
	void moveBox(GLfloat xDist, GLfloat yDist, GLfloat zDist);

private:
	//drawing the box
	void drawSquare();
	void drawCube();
};

#endif /*BOUNDING_BOX_H*/