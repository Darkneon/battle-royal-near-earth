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
    static const int NUM_SKINS = 2;
    
    void addTexturesFromFolder(string folder, map<string, GLuint> &textureList, GLuint* textureIDs);
    void addTexturesFromFolder(string folder, map<string, GLuint> &textureList, GLuint* textureIDs, int skinNum);
    
	TextureManager();
	static TextureManager* instance;
	map<string, GLuint> textures;
	vector<string> directoryListing;
    map<string, GLuint> skinTextures[NUM_SKINS];
    
    static string resourcePath;
    static int currentSkin;
    static int maxSkins;
};

#endif