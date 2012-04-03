#ifndef ENV_MAP_H
#define ENV_MAP_H

#ifndef GL_TEXTURE_CUBE_MAP_POSITIVE_X
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#endif
#ifndef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#endif
#ifndef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#endif
#ifndef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#endif
#ifndef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#endif
#ifndef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#endif
#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE                  0x812F
#endif

#ifndef GL_GENERATE_MIPMAP
#define GL_GENERATE_MIPMAP                0x8191
#endif

#ifndef GL_REFLECTION_MAP
#define GL_REFLECTION_MAP                 0x8512
#endif

#ifndef GL_TEXTURE_CUBE_MAP
#define GL_TEXTURE_CUBE_MAP               0x8513
#endif

//#include <GLEE/glee.h>
#include "LevelRenderer.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>

#ifndef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#endif
#ifndef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#endif
#ifndef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#endif
#ifndef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#endif
#ifndef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#endif
#ifndef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#endif
#ifndef GL_CLAMP_TO_EDGE
	#define GL_CLAMP_TO_EDGE                  0x812F
#endif

#ifndef GL_GENERATE_MIPMAP
	#define GL_GENERATE_MIPMAP                0x8191
#endif

#ifndef GL_REFLECTION_MAP
	#define GL_REFLECTION_MAP                 0x8512
#endif

#ifndef GL_TEXTURE_CUBE_MAP
	#define GL_TEXTURE_CUBE_MAP               0x8513
#endif

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