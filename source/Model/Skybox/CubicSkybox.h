#ifndef CUBIC_SKYBOX_H
#define	CUBIC_SKYBOX_H

#include "Model.h"

class CubicSkybox : Model {
public:
    CubicSkybox(int height, int width);
    void render();
	void build(int height, int width);
};

#endif

