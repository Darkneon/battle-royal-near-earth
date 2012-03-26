#include "BoundingBox.h"


BoundingBox::BoundingBox(void)
{
	min.x = 0.0f;
	min.y = 0.0f;
	min.z = 0.0f;
	max.x = 0.0f;
	max.y = 0.0f;
	max.z = 0.0f;
}

BoundingBox::BoundingBox(V3 min, V3 max){
	this->min = min;
	this->max = max;
}

BoundingBox::BoundingBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ){
	min.x = minX;
	min.y = minY;
	min.z = minZ;
	max.x = maxX;
	max.y = maxY;
	max.z = maxZ;
}

BoundingBox::~BoundingBox(void)
{
}
