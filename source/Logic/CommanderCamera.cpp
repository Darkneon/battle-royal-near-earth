#include "CommanderCamera.h"

CommanderCamera::CommanderCamera(GLint viewWidth, GLint viewHeight, GLfloat viewNearPlane, GLfloat viewFarPlane)
{
	Camera::initialize(viewWidth, viewHeight, viewNearPlane, viewFarPlane);
	//camera rotation
	yaw = 0.0f;
	pitch = 0.0f;

	//camera location
	currentRadius = DEFAULT_RADIUS;
	locX = 25.0f;
	locY = 0.0f;
	locZ = 25.0f + currentRadius;

	heightDenom = DEFAULT_HEIGHT_DENOM;
	fovy = DEFAULT_FOVY;
	calculate45DegreesForLocY();
       // updateFog();
}

void CommanderCamera::view()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, viewWidth / viewHeight, viewNearPlane, viewFarPlane);
	
	gluLookAt(locX + currentRadius * sin(yaw * 1.0f / 8), locY, locZ - currentRadius + currentRadius * cos(yaw * 1.0f / 8),
		locX, 0, locZ - currentRadius, 0, 1, 0);
       // updateFog();
}


void CommanderCamera::moveCameraForwards(bool negateTheValue)
{
	GLdouble moveVector[] = {sin(yaw * 1.0 / 8), cos(yaw * 1.0 / 8)};

	if (negateTheValue)
	{
		moveVector[0] *= -1.0;
		moveVector[1] *= -1.0;
	}

	locX -= (GLfloat)moveVector[0];
	locZ -= (GLfloat)moveVector[1];
       // updateFog();
}

void CommanderCamera::updateFog()
{
        GLfloat flowLight[] = {0.5, 0.5, 0.5, 1};
        glEnable(GL_FOG);
        glFogfv(GL_FOG_COLOR, flowLight);
        glFogf(GL_FOG_START, locZ);
        glFogf(GL_FOG_END, locZ+30);
        glFogf(GL_FOG_DENSITY, 0.2f);
        glFogi(GL_FOG_MODE, GL_LINEAR);
}
void CommanderCamera::moveCameraStrafe(bool negateTheValue)
{
	GLdouble moveVector[] = {sin(yaw / 8.0), cos(yaw / 8.0)};

	if (negateTheValue)
	{
		moveVector[0] *= -1.0;
		moveVector[1] *= -1.0;
	}

	locX += (GLfloat)moveVector[1];
	locZ -= (GLfloat)moveVector[0];
        //updateFog();
}

void CommanderCamera::zoom(bool zoomIn)
{
	GLfloat sum;
	if(zoomIn){
		sum = fovy-1;
	}
	else{
		sum = fovy+1;
	}
	if (sum > 10 && sum < DEFAULT_FOVY + 1.0f)
	{
		if (zoomIn)
		{
			fovy--;
			heightDenom += 0.25f;
		}
		else
		{
			fovy++;
			heightDenom -= 0.25f;
		}

		locY = currentRadius * tan(GL_PI / heightDenom);
	}
        
}

void CommanderCamera::resetZoom()
{
	fovy = DEFAULT_FOVY;
	calculate45DegreesForLocY();
	heightDenom = DEFAULT_HEIGHT_DENOM;
}

void CommanderCamera::calculate45DegreesForLocY()
{
	locY = currentRadius * tan(GL_PI / 4);
}

void CommanderCamera::modifyYaw(bool negateTheValue, int x, int y)
{
	if (!negateTheValue)
		yaw++;
	else
		yaw--;
}