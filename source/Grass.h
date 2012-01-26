/* 
 * File:   Grass.h
 * Author: robert
 *
 * Created on January 26, 2012, 1:34 PM
 */

#ifndef GRASS_H
#define	GRASS_H

#include "Model.h"
class Grass {
public:
    Grass();
    void draw();
    virtual ~Grass();
private:
    Model* model;

};

#endif	/* GRASS_H */

