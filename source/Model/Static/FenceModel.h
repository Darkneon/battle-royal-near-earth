/* 
 * File:   FenceModel.h
 * Author: robert
 *
 * Created on January 21, 2012, 9:45 PM
 */

#ifndef FENCEMODEL_H
#define	FENCEMODEL_H

#include "Model.h"
#include "StaticModel.h"

class FenceModel : public StaticModel {
public:
    FenceModel();        
private:
    void render();
    void drawBottom();
    void drawSection();
};

#endif	/* FENCEMODEL_H */

