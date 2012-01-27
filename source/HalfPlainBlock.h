/* 
 * File:   HalfPlainBlock.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:23 PM
 */

#ifndef HALFPLAINBLOCK_H
#define	HALFPLAINBLOCK_H

#include "Model.h"

class HalfPlainBlock {
public:
    HalfPlainBlock();
    ~HalfPlainBlock();
    void draw();
private:
    Model* model;

};

#endif

