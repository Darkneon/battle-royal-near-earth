/* 
 * File:   HollowBlock.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 6:43 PM
 */

#ifndef HOLLOWBLOCK_H
#define	HOLLOWBLOCK_H

#include "Model.h"

class HollowBlock {
public:
    HollowBlock();
    ~HollowBlock();
    void draw();
private:
    Model* model;

};

#endif

