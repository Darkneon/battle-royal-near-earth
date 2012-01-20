/* 
 * File:   PlayerModel.h
 * Author: robert
 *
 * Created on January 19, 2012, 3:47 PM
 */

#ifndef PLAYERMODEL_H
#define	PLAYERMODEL_H

#include "Model.h"

class PlayerModel : Model {
public:
    PlayerModel();
    void render();
private:
    void renderOneSide();
    void renderPlane();
};

#endif	/* PLAYERMODEL_H */

