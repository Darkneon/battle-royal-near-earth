/* 
 * File:   Bipod.h
 * Author: Stefanie Lavoie
 *
 */

#ifndef BIPOD_H
#define	BIPOD_H

#include "Model.h"

class Bipod {
public:
    Bipod();
    ~Bipod();
    void draw();
private:
    Model* model;

};

#endif

