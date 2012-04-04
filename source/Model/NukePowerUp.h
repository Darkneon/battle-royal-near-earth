#ifndef NUKE_POWERUP_H
#define NUKE_POWERUP_H

#include "Robot/NuclearModel.h"
#include "../Model/Helper/BoundingBox.h"
#include <time.h>

class NukePowerUp : public NuclearModel
{
public:
	NukePowerUp(GLfloat locX, GLfloat locZ);
	~NukePowerUp();
	void draw();

private:

	double lastRotation;
	double lastTranslation;
	double currentTime;

	bool goingUp;

	GLfloat yaw;
	GLfloat height;
	GLfloat locX;
	GLfloat locZ;

	//BoundingBox* tempBox;
};


#endif