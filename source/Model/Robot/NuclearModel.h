/* 
 * File:   NuclearModel.h
 * Author: Jeffrey
 *
 * Created on January 27, 2012, 1:22 AM
 */

#ifndef NUCLEARMODEL_H
#define	NUCLEARMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"

class NuclearModel : public Model {
public:
    NuclearModel();
	//GLfloat height;
private:
	void render();
	TeamNumberModel *teamNumber;
};

#endif