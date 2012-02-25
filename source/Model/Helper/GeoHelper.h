
#ifndef GEOHELPER_H
#define GEOHELPER_H

#include <math.h>

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

class GeoHelper
{
public:
	static void drawRectangle();
	static void drawCylinder(GLint degrees);
	static void drawCube(GLfloat xOrigin,GLfloat yOrigin, GLfloat zOrigin, GLfloat xEnd, GLfloat yEnd, GLfloat zEnd);
	static void drawTrapezoidalPrism();
	static void drawTriangularPrism();
	static void drawMidBuilding(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin);
	static void drawMidBuildingFront(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin);
	static void drawGarage(GLfloat xOrigin, GLfloat yOrigin, GLfloat zOrigin);
    static void drawAxis(GLfloat length);
	static void drawPeak();

	static GLfloat* findNormal3f(GLfloat* vector1, GLfloat* vector2, GLfloat* vector3);
    static GLfloat* findNormal3f(GLfloat u1, GLfloat u2, GLfloat u3,
                                 GLfloat v1, GLfloat v2, GLfloat v3,
                                 GLfloat w1, GLfloat w2, GLfloat w3);
};

#endif