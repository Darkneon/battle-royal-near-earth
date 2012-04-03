#ifndef LEVELRENDERER_H
#define LEVELRENDERER_H

#include "Model.h"

#include "../Model/Skybox/CubicSkybox.h"
#include "../Model/Skybox/SphericSkybox.h"
#include "DirectoryManipHelper.h"
#include "SpotLight.h"
#include "../Model/Light/LightPost.h"
#include "../Model/Helper/BoundingBox.h"
#include <string>
#include "../Model/Helper/CollisionTester.h"
#include "BulletManager.h"

#include "AntTweakHelper.h"

//Forward dependency required by AntTweak
class LightPost;

class LevelRenderer {
public:
    friend class AntTweakHelper;
    
    LevelRenderer(string mapName);
    ~LevelRenderer();
    void plane();
    void render();
    bool getIsSkySphere();
	void toggleSkySphere();
	CollisionTester* lrBoxes;
	BulletManager* bm;
	void toggleTeamNumber();
	void toggleLights(int light);
	int rows;
	int columns;
private:	
    static const int NUM_MODELS = 15;
    Model* models[NUM_MODELS];
    int **level;
	CubicSkybox *cubicSkyBox;
	SphericSkybox *sphericSkyBox;
    bool isSkySphere;

	void buildMap();
	void map();
	void renderLights();
        void shadowMatrix(GLfloat lightX, GLfloat lightY, GLfloat lightZ, GLfloat lightW);
        GLfloat calculateAlpha(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	//Initialize light objects
	SpotLight *spotLight;
	LightPost *light1;
	LightPost *light2;
	LightPost *light3;
	LightPost *light4;
	bool ambientLight;
	bool spotLight1;
	bool spotLight2;
	bool spotLight3;
	bool spotLight4;
	bool allLightToggle;
	bool showTeamNumbers;
        GLfloat groundplane[4];
        GLfloat shadowMat[16];
	string loadmap;
};
#endif