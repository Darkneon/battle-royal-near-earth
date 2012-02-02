/* 
 * File:   PhaserModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 2:51 PM
 */

#ifndef PHASERMODEL_H
#define	PHASERMODEL_H

#include "Model.h"
#include "TeamNumberModel.h"

class PhaserModel : Model {
public:
    PhaserModel();
private:
	void render();
        TeamNumberModel *teamNumber; //Addison
};

#endif