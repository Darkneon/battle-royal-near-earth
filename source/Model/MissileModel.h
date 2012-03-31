/* 
 * File:   CannonModel.h
 * Author: Jonathan
 *
 * Created on January 26, 2012, 6:57 PM
 */

#ifndef MISSILE_MODEL_H
#define	MISSILE_MODEL_H

#include "Model.h"

class MissileModel : public Model {
public:
    MissileModel();
	void render();
private:
	GLfloat smokeX, smokeY, smokeZ;
};

#endif