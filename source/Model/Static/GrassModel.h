/* 
 * File:   GrassModel.h
 * Author: robert
 *
 * Created on January 26, 2012, 1:35 PM
 */

#ifndef GRASSMODEL_H
#define	GRASSMODEL_H

#include "Model.h"
#include "StaticModel.h"

class GrassModel : public StaticModel {
public:
    GrassModel();
    void render();
private:
	void build();
};

#endif	/* GRASSMODEL_H */

