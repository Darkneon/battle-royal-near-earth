#ifndef ANT_TWEAK_HELPER_H
#define ANT_TWEAK_HELPER_H

#include "TweakAnt/AntTweakBar.h"
#include "Camera.h"

// Forward dependencies
class Camera;

class AntTweakHelper {
public:
    AntTweakHelper();
    void draw();
    void bindCamera(Camera *c);
private:
    TwBar *bar;
};

#endif
