/* 
 * File:   DefaultMaterial.cpp
 * Author: robert
 * 
 * Created on February 24, 2012, 9:10 PM
 */

#include "DefaultMaterial.h"

DefaultMaterial::DefaultMaterial() {
    refleciton[0] = 1.0f;
    refleciton[1] = 1.0f;
    refleciton[2] = 1.0f;
    refleciton[3] = 1.0f;
    
    shininess = 128;    
}