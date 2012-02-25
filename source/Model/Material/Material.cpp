/* 
 * File:   Material.cpp
 * Author: robert
 * 
 * Created on February 24, 2012, 5:54 PM
 */

#include "Material.h"



Material::Material() {
    refleciton[0] = 1.0f;
    refleciton[1] = 1.0f;
    refleciton[2] = 1.0f;
    refleciton[3] = 1.0f;
    
    shininess = 128;
}


void Material::apply() {
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //Use color set by glColor
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, refleciton);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}
