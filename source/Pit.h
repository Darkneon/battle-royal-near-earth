/* 
 * File:   Pit.h
 * Author: Jeffrey
 *
 * Created on January 26, 2012, 9:15 PM
 */

#ifndef PIT_H
#define	PIT_H

#include "Model.h"

class Pit {
public:
    Pit();
    ~Pit();
    void draw();
	void switchPitType();
private:
    Model* model;

};

#endif

