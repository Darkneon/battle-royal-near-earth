/* 
 * File:   Cannon.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:08 PM
 */

#ifndef CANNON_H
#define	CANNON_H

#include "Model.h"

class Cannon {
public:
    Cannon();
    ~Cannon();
    void draw();
private:
    Model* model;

};

#endif

