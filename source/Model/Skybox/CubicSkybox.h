#ifndef CUBIC_SKYBOX_H
#define	CUBIC_SKYBOX_H

#include "Model.h"

class CubicSkybox : Model {
public:
    CubicSkybox();
    void render();
	void build();
};

#endif

