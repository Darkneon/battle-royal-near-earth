/* 
 * File:   Base.h
 * Author: Addisson
 *
 * Created on January 31, 2012, 11:37 AM
 */

#ifndef BASE_H
#define	BASE_H

#include "Model.h"

class Base {
public:
    Base();
    ~Base();
    void draw();
private:
    Model *model;
};

#endif

