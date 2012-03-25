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
#include <string>
#include <map>
#include "DirectoryManipHelper.h"

using namespace std;

typedef std::pair<string, GLuint> texturePair; 

struct StringComparerForMap
{
public:
    bool operator()(string x, string y)
    {
		return x.compare(y) == 0;
    }
};

class TextureManager
{
public:
	static TextureManager* getInstance();
	GLuint getTextures(string fileName);
	void toggleTextures();
    void toggleSkins();
	void enableTexture();
    int getCurrentSkin() { return currentSkin; };

    static string getResourcePath();
	static bool texturesEnabled;
private:
	TextureManager();
    ~TextureManager();

    void addTexturesFromFolder(string folder, map<string, GLuint> &textureList, GLuint* textureIDs);
    int getLoadedTexturesCount();
    
    static const int NUM_SKINS = 2;
	static TextureManager* instance;
	static string resourcePath;
    static int currentSkin;   

	vector<string> directoryListing;
	map<string, GLuint> textures;
    map<string, GLuint> skinTextures[NUM_SKINS];
    
     
};

#endif