#include "NukePowerUp.h"
#include "Material/MetalMaterial.h"
#include "Helper/CollisionTester.h"

NukePowerUp::NukePowerUp(GLfloat locX, GLfloat locZ)
{
	material = (Material*)(new MetalMaterial());
	lastRotation = lastTranslation = currentTime = clock();
	yaw = height = 0.0f;
	goingUp = true;

	this->locX = locX;
	this->locZ = locZ;
}

NukePowerUp::~NukePowerUp(){}

void NukePowerUp::draw()
{
	currentTime = clock();
	if ((currentTime - lastTranslation) >= 100)
	{
		lastTranslation = clock();

		if (goingUp)
			height += 0.10f;
		else
			height -= 0.10f;

		if (height >= 0.60f)
			goingUp = false;
		else if (height <= 0.0f)
			goingUp = true;
	}

	if ((currentTime - lastRotation) >= 100)
	{
		yaw += 30.0f;

		if (yaw == 360.0f)
			yaw = 0.0f;
		lastRotation = clock();
	}
	
	glPushMatrix();
		glTranslatef(locX, height, locZ);
		glRotatef(yaw, 0.0f, 1.0f, 0.0f);
		glScalef(0.8f, 0.8f, 0.8f);
		glPushMatrix();
			glTranslatef(-0.5f, 0.0f, -0.5f);
			NuclearModel::draw();
		glPopMatrix();
	glPopMatrix();
}