/* 
 * File:   MissileLauncher.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:33 PM
 */

#ifndef MISSILELAUNCHER_H
#define	MISSILELAUNCHER_H

#include "Model.h"

class MissileLauncher {
public:
    MissileLauncher();
    ~MissileLauncher();
    void draw();
private:
    Model* model;

};

#endif

