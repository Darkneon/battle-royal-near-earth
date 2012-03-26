/* 
 * File:   PlainBlockModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:13 PM
 */

#ifndef PLAINBLOCKMODEL_H
#define	PLAINBLOCKMODEL_H

#include "Model.h"
#include "StaticModel.h"

class PlainBlockModel : StaticModel {
public:
    PlainBlockModel();        
private:
    void render();
	void drawSquare();
	void drawCube();
};

#endif

