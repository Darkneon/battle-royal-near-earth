#include "TextureManager.h"


TextureManager* TextureManager::instance = NULL;

TextureManager::TextureManager(void)
{
	glEnable(GL_TEXTURE_2D);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	//creates array of texture file names
	const char *textureFiles[TEXTURE_COUNT] = {"brick2.bmp", "nuclearTexture64.bmp", "metal1.bmp", "brick.bmp"};
	
	//generates array of GLUints that represent textures
	GLuint textureID[TEXTURE_COUNT];
	glGenTextures(TEXTURE_COUNT, textureID);

	Image* image = NULL;
	TextureEntry* te = NULL;
	for(int i = 0; i < TEXTURE_COUNT; i++){
		// takes file name, looks at file and converts to image
		image = loadBMP(textureFiles[i]);
		glBindTexture(GL_TEXTURE_2D, textureID[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		// assigns image data to respective texture ID
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

		//adds to hashtable
		te = new TextureEntry(textureID[i], textureFiles[i]);
		table.add(*te);
	}

	delete image;
	delete te;

}

TextureManager* TextureManager::getInstance(){
	if(instance == NULL){
		instance = new TextureManager();
	}
	return instance;
}

GLuint TextureManager::getTextures(char* fileName){
	return table.convertNameToId(fileName);
}

