/* 
 * File:   ElectronicsModel.h
 * Author: Jeffrey
 *
 * Created on January 27, 2012, 1:06 AM
 */

#ifndef ELECTRONICSMODEL_H
#define	ELECTRONICSMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"

class ElectronicsModel : Model {
public:
    ElectronicsModel();

private:
	void build();
	void render();
	TeamNumberModel *teamNumber;
};

#endif