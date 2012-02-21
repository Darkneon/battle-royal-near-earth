#ifndef ANT_TWEAK_HELPER_H
#define ANT_TWEAK_HELPER_H

#include "TweakAnt/AntTweakBar.h"
#include "Camera.h"
#include "Light/LightPost.h"

// Forward dependencies
class Camera;
class LightPost;

class AntTweakHelper {
public:
    AntTweakHelper();
    void draw();
    void bindCamera(Camera *c);
	void bindLightPosts(LightPost *l1, LightPost *l2, LightPost *l3, LightPost *l4);
private:
    TwBar *bar;
};

#endif
