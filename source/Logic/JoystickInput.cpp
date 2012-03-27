#include "JoystickInput.h"

#include <iostream>
#include <math.h>

JoystickInput::JoystickInput(HumanPlayer* player)
{
	this->player = player;

	deadZoneFound = false;
}

void JoystickInput::joystickOperations(unsigned int button, int x, int y, int z)
{
	if (button == GLUT_JOYSTICK_BUTTON_A)
	{
		std::cout << "button a pressed" << endl;
	}
	if (button == GLUT_JOYSTICK_BUTTON_B)
	{
		std::cout << "button b pressed" << endl;
	}
	if (button == GLUT_JOYSTICK_BUTTON_C)
	{
		std::cout << "button x pressed" << endl;
	}
	if (button == GLUT_JOYSTICK_BUTTON_D)
	{
		std::cout << "button y pressed" << endl;
	}

	if (button == 16) //left trigger
	{
		std::cout << "button left trigger pressed" << endl;
	}
	if (button == 32) //right trigger
	{
		std::cout << "button right trigger pressed" << endl;
	}

	if (button != 0)
		std::cout << "button " << button << " pressed" << endl;

	if (abs(x - deadZoneFound) > JOYSTICK_SENSITIVITY)
	{
		if (x < x_deadZone)
		{
			std::cout << "Move to the left : " << x << endl;
		}
		else if (x > x_deadZone)
		{
			std::cout << "Move to the right : " << x << endl;
		}

		if (y < y_deadZone)
		{
			std::cout << "Move upwards : " << y << endl;
		}
		else if (y > y_deadZone)
		{
			std::cout << "Move downwards : " << y << endl;
		}
	}

	if (!deadZoneFound)
	{
		deadZoneFound = true;
		x_deadZone = x;
		y_deadZone = y;
	}
}