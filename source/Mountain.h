/* 
 * File:   Mountain.h
 * Author: robert
 *
 * Created on January 21, 2012, 10:43 PM
 */

#ifndef MOUNTAIN_H
#define	MOUNTAIN_H

#include "Model.h"

class Mountain {
public:
    Mountain();
    ~Mountain();
    void draw();
private:
    Model* model;

};

#endif	/* MOUNTAIN_H */

