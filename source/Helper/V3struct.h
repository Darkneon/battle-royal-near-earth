#pragma once
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
