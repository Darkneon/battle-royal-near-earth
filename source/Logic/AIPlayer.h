/* 
 * File:   AIPlayer.h
 * Author: Jeff
 * Created on March 25, 2012
 */

#ifndef AIPLAYER_H
#define	AIPLAYER_H

#include "Model.h"
#include "CommanderCamera.h"
#include "FreeLookCamera.h"
#include "CirclingCamera.h"
#include "RobotCamera.h"
#include "LightCamera.h"
#include "Player.h"

class AIPlayer : public Player
{
public:
    AIPlayer();
	virtual ~AIPlayer(void);

};
#endif	/* AIPLAYER_H */