#ifndef LEVELRENDERER_H
#define LEVELRENDERER_H

#include "Model.h"
class LevelRenderer {
public:
    LevelRenderer();
    ~LevelRenderer();
    void render();
private:	
    static const int NUM_MODELS = 21;
    int level[50][50];
    Model* models[NUM_MODELS];
	void map1();
};
#endif