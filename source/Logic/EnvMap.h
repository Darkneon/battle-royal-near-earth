#ifndef ENV_MAP_H
#define ENV_MAP_H


//#include <GLEE/glee.h>
#include "LevelRenderer.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


class EnvMap
{
public:
	EnvMap(void);
	~EnvMap(void);

	void init();
	void cleanup();
	void RegenerateEnvMap(LevelRenderer *level, GLfloat cameraX, GLfloat cameraZ);
	void tex();

private:
	GLuint windowWidth;
	GLuint textures[5];
	GLuint envMapTextureID;   
	GLuint width;
};

#endif