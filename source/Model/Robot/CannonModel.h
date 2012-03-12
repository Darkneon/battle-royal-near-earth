/* 
 * File:   CannonModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 6:57 PM
 */

#ifndef CANNONMODEL_H
#define	CANNONMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"

class CannonModel : public Model {
public:
    CannonModel();

private:
	void render();
	void drawBarrel(GLUquadricObj*);
	TeamNumberModel *teamNumber;
};

#endif