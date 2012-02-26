/* 
 * File:   PhaserModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 2:51 PM
 */

#ifndef PHASERMODEL_H
#define	PHASERMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"

class PhaserModel : Model {
public:
    PhaserModel();
	//GLfloat height;
private:
	void render();
        TeamNumberModel *teamNumber;
};

#endif