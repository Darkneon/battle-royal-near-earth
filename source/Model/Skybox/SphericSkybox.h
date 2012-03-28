#ifndef SPHERIC_SKYBOX_H
#define	SPHERIC_SKYBOX_H

#include "Model.h"

class SphericSkybox : Model {
public:
    SphericSkybox(int height, int width);
    void render();
	void build(int height, int width);
};

#endif

