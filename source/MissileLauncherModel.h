/* 
 * File:   MissileLauncherModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 7:29 PM
 */

#ifndef MISSILELAUNCHERMODEL_H
#define	MISSILELAUNCHERMODEL_H

#include "Model.h"
#include "TeamNumberModel.h"

class MissileLauncherModel : Model {
public:
    MissileLauncherModel();
private:
	void render();
        TeamNumberModel *teamNumber; //Addison
};

#endif