/* 
 * File:   NuclearModel.h
 * Author: Jeffrey
 *
 * Created on January 27, 2012, 1:22 AM
 */

#ifndef NUCLEARMODEL_H
#define	NUCLEARMODEL_H

#include "Model.h"

class NuclearModel : Model {
public:
    NuclearModel();
private:
	void render();
    static GeoHelper geoHelper;
};

#endif