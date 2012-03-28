#include "CollisionTester.h"

vector<BoundingBox *> CollisionTester::staticBoxes;

CollisionTester::CollisionTester(void){}

CollisionTester::~CollisionTester(void){}

bool CollisionTester::collisionTest(GLfloat x, GLfloat y, GLfloat z, GLuint id){
	for(int i = 0; (i < (int)staticBoxes.size()); i++){
		if(collision(staticBoxes.at(i),x,y,z,id)){
			return true;
		}
	}
	return false;
}

bool CollisionTester::collision(BoundingBox* b, GLfloat x, GLfloat y, GLfloat z, GLuint id){
	if(x <= b->max.x && x >= b->min.x &&
		y <= b->max.y && y >= b->min.y &&
		z <= b->max.z && z >= b->min.z &&
		id != b->movingBoxId){
		return true;
	}
	return false;
}