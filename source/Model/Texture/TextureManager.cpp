#include "TextureManager.h"

/*
#ifdef __APPLE__
	#include <dirent.h>
#elif __linux__
	#include <dirent.h>
#else
    #include "..\..\include\WinDirent\dirent.h"
#endif
	*/

#ifdef WIN32_LEAN_AND_MEAN
	#include "..\..\include\WinDirent\dirent.h"
	#include <direct.h>
#else
	#include <dirent.h>
#endif

#include <cstring>

TextureManager* TextureManager::instance = NULL;
string TextureManager::resourcePath;

TextureManager::TextureManager(void)
{
	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	//hash_map
	DirectoryManipHelper::getDirectoryListing(getResourcePath(), &directoryListing);
	
	//generates array of GLUints that represent textures
	int nbTextures = directoryListing.size();
	GLuint* textureID = new GLuint[nbTextures];
	glGenTextures(nbTextures, textureID);

	Image* image = NULL;
    
	for(int i = 0; i < nbTextures; i++){
		// takes file name, looks at file and converts to image
		string bmpToLoad = directoryListing.at(i);
		image = loadBMP( (getResourcePath() + bmpToLoad).c_str() );
		glBindTexture(GL_TEXTURE_2D, textureID[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		// assigns image data to respective texture ID
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

		//adds to hashtable
		textures.insert(texturePair(bmpToLoad, textureID[i]));
	}

	delete image;
}

string TextureManager::getResourcePath() {
    if (resourcePath == "") {
        char *cwd = new char[255];

#if WIN32_LEAN_AND_MEAN 
        _getcwd(cwd, 255);		
		strcat_s(cwd, 255, "/resource/");
#else
		getcwd(cwd, 255);
		strcat(cwd, "/resource/");
#endif
		resourcePath.assign(cwd);
        delete[] cwd;
    }
    
    return resourcePath;
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

