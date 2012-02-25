/* 
 * File:   Metal.cpp
 * Author: robert
 * 
 * Created on February 24, 2012, 5:55 PM
 */

#include "MetalMaterial.h"

MetalMaterial::MetalMaterial() {
    refleciton[0] = 1.0f;
    refleciton[1] = 1.0f;
    refleciton[2] = 1.0f;
    refleciton[3] = 1.0f;
    
    shininess = 11;    
}