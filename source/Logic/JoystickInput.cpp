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
	if (button >= 32) //right trigger
	{
		player->robots.at(0)->moveStrafe(true);
		button -= 32;
	}
	if (button >= 16) //left trigger
	{
		player->robots.at(0)->moveStrafe(false);
		button -= 16;
	}
	if (button >= GLUT_JOYSTICK_BUTTON_D)
	{
		std::cout << "button y pressed" << endl;
		button -= GLUT_JOYSTICK_BUTTON_D;
	}
	if (button >= GLUT_JOYSTICK_BUTTON_C)
	{
		std::cout << "button x pressed" << endl;
		button -= GLUT_JOYSTICK_BUTTON_C;
	}
	if (button >= GLUT_JOYSTICK_BUTTON_B)
	{
		std::cout << "button b pressed" << endl;
		button -= GLUT_JOYSTICK_BUTTON_B;
	}
	if (button >= GLUT_JOYSTICK_BUTTON_A)
	{
		//std::cout << "button a pressed" << endl;
		if (player->getCurrentCameraType() == CAMERA_ROBOT)
			player->robots.at(0)->shootBullet();

		button -= GLUT_JOYSTICK_BUTTON_A;
	}

	if (button != 0)
		std::cout << "some value at: " << button << endl;

	if (abs(x - deadZoneFound) > JOYSTICK_SENSITIVITY)
	{
		if (x < x_deadZone)
		{
			player->robots.at(0)->incrementSpinDegrees(true, 8.0f);
			std::cout << "Move to the left" << endl;
		}
		else
		{
			player->robots.at(0)->incrementSpinDegrees(false, 8.0f);
			std::cout << "Move to the right" << endl;
		}

	}

	if (abs(y - deadZoneFound) > JOYSTICK_SENSITIVITY)
	
		if (y > y_deadZone)
		{
			player->robots.at(0)->moveForward(false);
		}
		else
		{
			player->robots.at(0)->moveForward(true);
		}
	

	if (!deadZoneFound)
	{
		deadZoneFound = true;
		x_deadZone = x;
		y_deadZone = y;
	}
}