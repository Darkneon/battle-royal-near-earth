#ifndef TEXTUREMANAGER_H
#define	TEXTUREMANAGER_H

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include "imageloader.h"
#include <iostream>
#include <vector>
#include "..\Model.h"
#include <stdio.h>
#include <string.h>
#include "TextureTable.h"

using namespace std;

//Texture objects
#define TEXTURE_BRICK 0
#define TEXTURE_NUKE 1
#define TEXTURE_LOGO 2
#define TEXTURE_COUNT 4

class TextureManager
{
public:
	static TextureManager* getInstance();
	GLuint getTextures(char* fileName);
	TextureTable table;

private:
	TextureManager();
	static TextureManager* instance;
	
};

#endif