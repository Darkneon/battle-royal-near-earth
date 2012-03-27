/* 
 * File:   HumanPlayer.h
 * Author: Jonathan
 * Created on March 27, 2012
 */

#ifndef JOYSTICK_INPUT_H
#define	JOYSTICK_INPUT_H

#include "HumanPlayer.h"



class JoystickInput
{
public:
	JoystickInput(HumanPlayer* player);
	void joystickOperations(unsigned int button, int x, int y, int z);

	static const int JOYSTICK_SENSITIVITY = 200;

private:
	HumanPlayer* player;

	int x_deadZone;
	int y_deadZone;
	bool deadZoneFound;
	
};

#endif