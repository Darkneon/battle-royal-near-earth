/* 
 * File:   Factory.h
 * Author: Addisson
 *
 * Created on February 2, 2012, 2:15 PM
 */

#ifndef FACTORY_H
#define	FACTORY_H

#include "Model.h"

class Factory {
public:
    Factory();
    ~Factory();
    void draw();
private:
    Model *model;
};

#endif

