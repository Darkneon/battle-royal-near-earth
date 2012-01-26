#ifndef LEVELRENDERER_H
#define LEVELRENDERER_H

#include "Model.h"
class LevelRenderer {
public:
	LevelRenderer();
	void render();
private:	
	int level[50][50];
	Model* models[1];
};
#endif