/* 
 * File:   Fence.h
 * Author: robert
 *
 * Created on January 21, 2012, 9:52 PM
 */

#ifndef FENCE_H
#define	FENCE_H

#include "Model.h"

class Fence {
public:
    Fence();
    ~Fence();
    void draw();
private:
    Model *model;
};

#endif	/* FENCE_H */

