/* 
 * File:   MountainModel.h
 * Author: robert
 *
 * Created on January 21, 2012, 10:32 PM
 */

#ifndef MOUNTAINMODEL_H
#define	MOUNTAINMODEL_H

#include "Model.h"

class MountainModel : Model {
public:
    MountainModel();
    void render();
private:    
    void drawPeak();
    
};

#endif	/* MOUNTAINMODEL_H */

