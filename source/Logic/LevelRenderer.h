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

class LevelRenderer {
public:
    LevelRenderer();
    ~LevelRenderer();
    void render();
    bool getIsSkySphere();
	void toggleSkySphere();
	vector<BoundingBox *> lrBoxes;

private:	
    static const int NUM_MODELS = 22;
    Model* models[NUM_MODELS];
    int **level;
	int rows;
	int columns;

	CubicSkybox *cubicSkyBox;
	SphericSkybox *sphericSkyBox;
    bool isSkySphere;

	void buildMap();
	void map();
	void renderLights();

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

	string loadmap;
};
#endif