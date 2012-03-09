#include "TextureEntry.h"

TextureEntry::TextureEntry(){
	textureId = 9999;
	fileName = "null";
}

TextureEntry::TextureEntry(GLuint id, const char* name)
{
	textureId = id;
	fileName = name;
}

TextureEntry::~TextureEntry(void)
{
}

const char* TextureEntry::getFileName(){
	return fileName;
}

GLuint TextureEntry::getTextureId(){
	return textureId;
}