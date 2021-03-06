#include "PlayerUFO.h"

//---------------------------------------------------------------
//						CONSTRUCTORS & DESTRUCTOR
//---------------------------------------------------------------
PlayerUFO::PlayerUFO(void)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = 0.0f;
	pos[1] = 0.0f;
	pos[2] = 0.0f;
	box = new BoundingBox(pos[0],pos[1],pos[2],pos[0]+1.0f,pos[1]+1.0f,pos[2]+1.0f, true);
	ct = new CollisionTester;
	ct->staticBoxes.push_back(box);
        updateLights(pos[0], pos[1], pos[2]);
}

PlayerUFO::PlayerUFO(GLfloat x, GLfloat z)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = x;
	pos[1] = 0;
	pos[2] = z;
	box = new BoundingBox(pos[0],pos[1],pos[2],pos[0]+1.0f,pos[1]+1.0f,pos[2]+1.0f, true);
	ct = new CollisionTester;
	ct->staticBoxes.push_back(box);

        //LIGHTING
        updateLights(pos[0], pos[1], pos[2]);
}

PlayerUFO::~PlayerUFO(void)
{
	if (pModel != NULL) {
		delete pModel;
		pModel = NULL;
	}
}

//---------------------------------------------------------------
//						LIGHTS
//---------------------------------------------------------------
void PlayerUFO::updateLights(GLfloat xPos, GLfloat yPos, GLfloat zPos)
{
        spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);
        light = new LightPost(xPos+0.5f, yPos, zPos+0.5f, 0, -1, 0);
        glLightfv(GL_LIGHT7, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT7, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT7, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT7, GL_POSITION, light->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 20.0f);
        glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 150.0f);
        glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, light->getDirectionArray());
        glEnable(GL_LIGHT7);
}


//---------------------------------------------------------------
//						DRAW
//---------------------------------------------------------------
void PlayerUFO::draw(){
	incrementHeight(false);
	glPushMatrix();
		box->draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(pos[0],pos[1],pos[2]);
		pModel->draw();
	glPopMatrix();
        updateLights(pos[0], pos[1], pos[2]);
}

//---------------------------------------------------------------
//			TRANSLATE UFO (AND BOUNDING BOX)
//---------------------------------------------------------------
void PlayerUFO::incrementHeight(bool positive){
	if(positive){
		//if upstep is less than max height -> upstep
		if(pos[1]+UP_STEP <= MAX_PLAYER_HEIGHT){
			pos[1] += UP_STEP;
			box->lockBox(pos[0],pos[1],pos[2]);
		}		
		else{
			pos[1] = MAX_PLAYER_HEIGHT;
			box->lockBox(pos[0],pos[1],pos[2]);
		}
	}
	else{
		if(pos[1]-DOWN_STEP >= MIN_PLAYER_HEIGHT){
			if(ufoCollisionTest(pos[0],pos[1]-DOWN_STEP,pos[2]) < 0){
				//if downstep is not too far and there is no collision
				pos[1] -= DOWN_STEP;
				box->lockBox(pos[0],pos[1],pos[2]);
			}
		}
		else{
			//if downstep is too far
			pos[1] = MIN_PLAYER_HEIGHT;
			box->lockBox(pos[0],pos[1],pos[2]);
		}
	}
        updateLights(pos[0], pos[1], pos[2]);
}

void PlayerUFO::incrementXPos(bool positive){
	if(positive){
		if(ufoCollisionTest(pos[0]+SIDE_STEP,pos[1],pos[2])<0){
			pos[0] += SIDE_STEP;
			box->lockBox(pos[0],pos[1],pos[2]);
		}
	}
	else{
		if(ufoCollisionTest(pos[0]-SIDE_STEP,pos[1],pos[2])<0){
			pos[0] -= SIDE_STEP;
			box->lockBox(pos[0],pos[1],pos[2]);
		}
	}
        updateLights(pos[0], pos[1], pos[2]);
}

void PlayerUFO::incrementZPos(bool positive){
	if(positive){
		if(ufoCollisionTest(pos[0],pos[1],pos[2]+SIDE_STEP) < 0){
			pos[2] += SIDE_STEP;
			box->lockBox(pos[0],pos[1],pos[2]);
		}
	}
	else{
		if(ufoCollisionTest(pos[0],pos[1],pos[2]-SIDE_STEP) < 0){
			pos[2] -= SIDE_STEP;
			box->lockBox(pos[0],pos[1],pos[2]);
		}
	}
        updateLights(pos[0], pos[1], pos[2]);
}

void PlayerUFO::setPosition(GLfloat x, GLfloat y, GLfloat z){
	if(y <= MAX_PLAYER_HEIGHT){// && ufoCollisionTest(x,y,z) != 0){
		pos[0] = x;
		pos[1] = y;
		pos[2] = z;
		box->lockBox(pos[0],pos[1],pos[2]);
	}
    updateLights(pos[0], pos[1], pos[2]);
}

//---------------------------------------------------------------
//					COLLISION DETECTION
//---------------------------------------------------------------
int PlayerUFO::ufoCollisionTest(GLfloat x, GLfloat y, GLfloat z){
	//if one of bottom ufo vertices collide with robot return robot id
	if(ct->ufoCollTest(x,y,z,box->movingBoxId) > 0){
		return ct->ufoCollTest(x,y,z,box->movingBoxId);
	}
	if(ct->ufoCollTest(x+box->size.x, y, z,box->movingBoxId) > 0){
		return ct->ufoCollTest(x+box->size.x, y, z,box->movingBoxId);
	}
	if(ct->ufoCollTest(x,	y,	z+box->size.z,box->movingBoxId) > 0){
		return ct->ufoCollTest(x,	y,	z+box->size.z,box->movingBoxId);
	}
	if(ct->ufoCollTest(x+box->size.x,	y,	z+box->size.z,box->movingBoxId)> 0){
		return ct->ufoCollTest(x+box->size.x,	y,	z+box->size.z,box->movingBoxId);
	}

	//if bottom didn't collide with robot, still may collide with something else
	if(ct->ufoCollTest(x,y,z,box->movingBoxId) == 0){
		return 0;
	}
	if(ct->ufoCollTest(x+box->size.x, y, z,box->movingBoxId) == 0){
		return 0;
	}
	if(ct->ufoCollTest(x,	y,	z+box->size.z,box->movingBoxId) == 0){
		return 0;
	}
	if(ct->ufoCollTest(x+box->size.x,	y,	z+box->size.z,box->movingBoxId)== 0){
		return 0;
	}

	//test top for collision
	if(ct->ufoCollTest(x,	y+box->size.y,	z,box->movingBoxId)>= 0){
		return 0;
	}
	if(ct->ufoCollTest(x+box->size.x,	y+box->size.y,	z,box->movingBoxId)>= 0){
		return 0;
	}
	if(ct->ufoCollTest(x,	y+box->size.y,	z+box->size.z,box->movingBoxId)>= 0){
		return 0;
	}
	if(ct->ufoCollTest(x+box->size.x,	y+box->size.y,	z+box->size.z,box->movingBoxId)>= 0){
		return 0;
	}
	//no collision
	return -1;	
	/*if(ct->collisionTest(x,y,z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x, y, z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x,	y,	z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x,	y,	z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x,	y+box->size.y,	z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x,	y+box->size.y,	z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x,	y+box->size.y,	z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x,	y+box->size.y,	z+box->size.z,box->movingBoxId)){
			return true;
		}

		return false;*/
}

V3 PlayerUFO::getPosition(){
	V3 v = {pos[0],pos[1],pos[2]};
	return v;
}