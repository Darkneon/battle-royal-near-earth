/* 
 * File:   HalfHollowBlockModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 6:46 PM
 */

#ifndef HALFHOLLOWBLOCKMODEL_H
#define	HALFHOLLOWBLOCKMODEL_H

//#include "Model.h"
#include "HollowBlockModel.h"

class HalfHollowBlockModel : HollowBlockModel {
public:
    HalfHollowBlockModel();        
private:
    void render();
};

#endif

