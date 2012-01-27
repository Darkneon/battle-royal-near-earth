/* 
 * File:   Phaser.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 3:10 PM
 */

#ifndef PHASER_H
#define	PHASER_H

#include "Model.h"

class Phaser {
public:
    Phaser();
    ~Phaser();
    void draw();
private:
    Model* model;

};

#endif

