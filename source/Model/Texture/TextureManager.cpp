#include "TextureManager.h"

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

TextureManager::TextureManager(void)
{
        
    //Calculate the total number of textures we will need
    int nbTextures = 0;
    DirectoryManipHelper::getDirectoryListing(getResourcePath(), &directoryListing);
    nbTextures += directoryListing.size();
    
    DirectoryManipHelper::getDirectoryListing(getResourcePath() + "skins/0/", &directoryListing);
    nbTextures += directoryListing.size();
    
    DirectoryManipHelper::getDirectoryListing(getResourcePath() + "skins/1/", &directoryListing);
    nbTextures += directoryListing.size();
    
    //use total number of textures to create an empty array of GLuints for opengl
	GLuint* textureID = new GLuint[nbTextures];
	glGenTextures(nbTextures, textureID);
    
    //Load images and assign texture IDs
    addTexturesFromFolder(getResourcePath(), textures, textureID);
    
    addTexturesFromFolder(getResourcePath() + "skins/1/", skinTextures[1], textureID);
    addTexturesFromFolder(getResourcePath() + "skins/0/", skinTextures[0], textureID);
    
    
    delete[] textureID;
  
}

TextureManager::~TextureManager() {
    map<string, GLuint>::iterator iter;
    for(iter = textures.begin(); iter != textures.end(); iter++) {                
        glDeleteTextures(1, &iter->second);
    }
    
    for (int i = 0; i != NUM_SKINS; i++) {
        for(iter = skinTextures[i].begin(); iter != skinTextures[i].end(); iter++) {                
            glDeleteTextures(1, &iter->second);
        }
    }
}

void TextureManager::addTexturesFromFolder(string folder, map<string,GLuint>& textureList, GLuint* textureIDs) {
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		
	DirectoryManipHelper::getDirectoryListing(folder, &directoryListing);	
	Image* image = NULL;

    int start = getLoadedTexturesCount();
    int end = start + directoryListing.size();
    
	for(int i = start; i < end; i++){		
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

        textureList.insert(texturePair(bmpToLoad, textureIDs[i]));
	}        

	delete image;  
}

int TextureManager::getLoadedTexturesCount() {
    int result = textures.size();   
    
    for (int s = 0; s != NUM_SKINS; s++) {
        result += skinTextures[s].size();
    }
    
    return result;
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
    
    bool containsFilename = (textures.end() != textures.find(fileName));
    if (containsFilename) {
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