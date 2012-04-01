#ifndef ANT_TWEAK_HELPER_H
#define ANT_TWEAK_HELPER_H

#include "TweakAnt/AntTweakBar.h"
#include "Camera.h"
#include "LevelRenderer.h"

// Forward dependencies
class Camera;
class LevelRenderer;

class AntTweakHelper {
public:
    AntTweakHelper();
    void draw();
    void bindCamera(Camera *c);
	void bindLevelRenderer(LevelRenderer *l);
private:
    TwBar *bar;
};

#endif
