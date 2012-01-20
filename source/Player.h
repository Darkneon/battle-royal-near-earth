/* 
 * File:   player.h
 * Author: robert
 *
 * Created on January 19, 2012, 3:18 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Model.h"

class Player {
public:
    Player();
    ~Player();
    void draw();        
private:
        Model *model;
    
};

#endif	/* PLAYER_H */

