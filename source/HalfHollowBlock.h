/* 
 * File:   HalfHollowBlock.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 6:52 PM
 */

#ifndef HALFHOLLOWBLOCK_H
#define	HALFHOLLOWBLOCK_H

#include "Model.h"

class HalfHollowBlock {
public:
    HalfHollowBlock();
    ~HalfHollowBlock();
    void draw();
private:
    Model* model;

};

#endif

