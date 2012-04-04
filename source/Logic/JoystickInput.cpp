#include "JoystickInput.h"

#include <iostream>
#include <math.h>

JoystickInput::JoystickInput(HumanPlayer* player)
{
	this->player = player;
	deadZoneFound = false;
}

static int lastButtonPressed = 0;
static bool buttonWasPressed = false;

void JoystickInput::joystickOperations(unsigned int button, int x, int y, int z)
{
	if (button >= 32) //right trigger
	{	
		player->robots.at(0)->incrementSpinDegrees(false, 4.0f);
		button -= 32;
	}
	if (button >= 16) //left trigger
	{
		player->robots.at(0)->incrementSpinDegrees(true, 4.0f);
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
		if (lastButtonPressed == GLUT_JOYSTICK_BUTTON_A)
			return;

		//std::cout << "button a pressed" << endl;
		if (player->getCurrentCameraType() == CAMERA_ROBOT)
			if (player->robots.at(0)->isAlive)
				player->robots.at(0)->shootBullet();
			else
				player->respawn();

		lastButtonPressed = GLUT_JOYSTICK_BUTTON_A;
		buttonWasPressed = true;
		button -= GLUT_JOYSTICK_BUTTON_A;
	}

	if (button != 0)
		std::cout << "some value at: " << button << endl;

	if (!buttonWasPressed)
	{
		lastButtonPressed = 0;
	}

	if (abs(x - deadZoneFound) > JOYSTICK_SENSITIVITY)
	{
		if (x < x_deadZone)
		{
			player->robots.at(0)->moveStrafe(false);
		}
		else
		{
			player->robots.at(0)->moveStrafe(true);
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
	
	buttonWasPressed = false;

	if (!deadZoneFound)
	{
		deadZoneFound = true;
		x_deadZone = x;
		y_deadZone = y;
	}
}