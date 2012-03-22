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
bool TextureManager::texturesEnabled = true;
int TextureManager::currentSkin = 0;
//int TextureManager::NUM_SKINS = 2;

TextureManager::TextureManager(void)
{
    
    int nbTextures = 0;
    DirectoryManipHelper::getDirectoryListing(getResourcePath(), &directoryListing);
    nbTextures += directoryListing.size();
    
    DirectoryManipHelper::getDirectoryListing(getResourcePath() + "skins/0/", &directoryListing);
    nbTextures += directoryListing.size();
    
    DirectoryManipHelper::getDirectoryListing(getResourcePath() + "skins/1/", &directoryListing);
    nbTextures += directoryListing.size();
    
    //generates array of GLUints that represent textures	
	GLuint* textureID = new GLuint[nbTextures];
	glGenTextures(nbTextures, textureID);
    
    addTexturesFromFolder(getResourcePath(), textures, textureID);	
    addTexturesFromFolder(getResourcePath() + "skins/0/", textures, textureID, 0);
    addTexturesFromFolder(getResourcePath() + "skins/1/", textures, textureID, 1);
    
    delete[] textureID;
}

void TextureManager::addTexturesFromFolder(string folder, map<string, GLuint> &textureList, GLuint* textureIDs) {
    addTexturesFromFolder(folder, textureList, textureIDs, -1);
}

void TextureManager::addTexturesFromFolder(string folder, map<string,GLuint>& textureList, GLuint* textureIDs, int skinNum) {
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	//hash_map
	DirectoryManipHelper::getDirectoryListing(folder, &directoryListing);	
	Image* image = NULL;
    
    int start = textureList.size() + skinTextures[0].size();
    int end = start + directoryListing.size();
	for(int i = start; i < end; i++){
		// takes file name, looks at file and converts to image
		string bmpToLoad = directoryListing.at(i-start);
		image = loadBMP( (folder + bmpToLoad).c_str() );
		glBindTexture(GL_TEXTURE_2D, textureIDs[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		
		// assigns image data to respective texture ID
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
		
        cout << i << endl;
        if (skinNum == -1) {
            textureList.insert(texturePair(bmpToLoad, textureIDs[i]));
        } else {
            skinTextures[skinNum].insert(texturePair(bmpToLoad, textureIDs[i]));
        }
	}        

	delete image;
  //  delete[] textureID;
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
    
    if (textures.end() != textures.find(fileName)) {
        return textures[fileName];
    }
    else {
        
        return skinTextures[currentSkin][fileName];
    }
}

void TextureManager::toggleTextures(){
	texturesEnabled = !texturesEnabled;
}

void TextureManager::toggleSkins(){
    currentSkin += 1;
    if (currentSkin >= NUM_SKINS) {
        currentSkin = 0;
    }
}

void TextureManager::enableTexture(){
	if(texturesEnabled){
		glEnable(GL_TEXTURE_2D);
	}
}