#ifndef TEXTURE_TABLE_H
#define	TEXTURE_TABLE_H

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "TextureEntry.h"

class TextureTable
{
public:
	TextureTable(void);
	~TextureTable(void);
	GLuint convertNameToId(char* name);
	void add(TextureEntry t);

private:
	int size;
	int capacity;
	TextureEntry table[10];
};

#endif