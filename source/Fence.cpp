/* 
 * File:   Fence.cpp
 * Author: robert
 * 
 * Created on January 21, 2012, 9:52 PM
 */

#include "Fence.h"
#include "FenceModel.h"

Fence::Fence() {
    model = (Model*)(new FenceModel);
    
}

void Fence::draw() {
    model->draw();
}
