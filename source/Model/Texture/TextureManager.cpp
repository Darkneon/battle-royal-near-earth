#include "TextureManager.h"


TextureManager* TextureManager::instance = NULL;

TextureManager::TextureManager(void)
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	//hash_map
	DirectoryManipHelper::getDirectoryListing("../textures", &directoryListing);
	
	//generates array of GLUints that represent textures
	int nbTextures = directoryListing.size();
	GLuint* textureID = new GLuint[nbTextures];
	glGenTextures(nbTextures, textureID);

	Image* image = NULL;

	for(int i = 0; i < nbTextures; i++){
		// takes file name, looks at file and converts to image
		string bmpToLoad = directoryListing.at(i);
		image = loadBMP(bmpToLoad.c_str());
		glBindTexture(GL_TEXTURE_2D, textureID[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		// assigns image data to respective texture ID
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

		//adds to hashtable
		textures.insert( texturePair(bmpToLoad, textureID[i]));
	}

	delete image;
}

TextureManager* TextureManager::getInstance(){
	if(instance == NULL){
		instance = new TextureManager();
	}
	return instance;
}

GLuint TextureManager::getTextures(string fileName){
	return textures[fileName];
}

