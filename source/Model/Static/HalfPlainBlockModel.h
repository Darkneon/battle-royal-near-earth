/* 
 * File:   HalfPlainBlockModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:20 PM
 */

#ifndef HALFPLAINBLOCKMODEL_H
#define	HALFPLAINBLOCKMODEL_H

#include "Model.h"
#include "StaticModel.h"

class HalfPlainBlockModel : StaticModel {
public:
    HalfPlainBlockModel();        
private:
    void render();
};

#endif

