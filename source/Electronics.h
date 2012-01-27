/* 
 * File:   Electronics.h
 * Author: Jeffrey
 *
 * Created on January 27, 2012, 1:11 AM
 */

#ifndef ELECTRONICS_H
#define	ELECTRONICS_H

#include "Model.h"

class Electronics {
public:
    Electronics();
    ~Electronics();
    void draw();     
private:
    Model *model;
    
};

#endif

