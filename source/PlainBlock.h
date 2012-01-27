/* 
 * File:   PlainBlock.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:16 PM
 */

#ifndef PLAINBLOCK_H
#define	PLAINBLOCK_H

#include "Model.h"

class PlainBlock {
public:
    PlainBlock();
    ~PlainBlock();
    void draw();
private:
    Model* model;

};

#endif

