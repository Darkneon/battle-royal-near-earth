/* 
 * File:   HollowBlockModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 6:37 PM
 */

#ifndef HOLLOWBLOCKMODEL_H
#define	HOLLOWBLOCKMODEL_H

#include "Model.h"
#include "StaticModel.h"

class HollowBlockModel : StaticModel {
public:
    HollowBlockModel();        
protected:
    void render();
};

#endif

