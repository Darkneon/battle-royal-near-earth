#ifndef TEXTURE_ENTRY_H
#define	TEXTURE_ENTRY_H

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

class TextureEntry
{
public:
	TextureEntry();
	TextureEntry(GLuint id, const char* name);
	~TextureEntry(void);
	const char* getFileName();
	GLuint getTextureId();

private:
	GLuint textureId;
	const char* fileName;
};

#endif