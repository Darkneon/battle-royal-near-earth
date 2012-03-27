#include "PlayerUFO.h"

PlayerUFO::PlayerUFO(void)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = 0.0f;
	pos[1] = 0.0f;
	pos[2] = 0.0f;
	box = new BoundingBox(pos[0],pos[1],pos[2],pos[0]+1.0f,pos[1]+1.0f,pos[2]+1.0f);
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
	box = new BoundingBox(pos[0],pos[1],pos[2],pos[0]+1.0f,pos[1]+1.0f,pos[2]+1.0f);
        //LIGHTING
        updateLights(pos[0], pos[1], pos[2]);
        
}
void PlayerUFO::updateLights(GLfloat xPos, GLfloat yPos, GLfloat zPos)
{
        spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);
        light = new LightPost(xPos+0.5f, yPos, zPos+0.5f, 0, -1, 0);
        glLightfv(GL_LIGHT7, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT7, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT7, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT7, GL_POSITION, light->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, light->getDirectionArray());
        glEnable(GL_LIGHT7);
}

PlayerUFO::~PlayerUFO(void)
{
	if (pModel != NULL) {
		delete pModel;
		pModel = NULL;
	}
}

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

void PlayerUFO::incrementHeight(bool positive){
	if(positive){
		if(pos[1]+0.05f <= MAX_PLAYER_HEIGHT){
			pos[1] += 0.5f;
			box->moveBox(0.0f,0.5f,0.0f);
		}
	}
	else{
		if(pos[1]-0.02f >= MIN_PLAYER_HEIGHT){
			pos[1] -= 0.2f;
			box->moveBox(0.0f,-0.2f,0.00f);
		}
	}
        updateLights(pos[0], pos[1], pos[2]);
}

void PlayerUFO::incrementXPos(bool positive){
	if(positive){
		pos[0] += 0.05f;
		box->moveBox(0.05f,0.0f,0.0f);
	}
	else{
		pos[0] -= 0.05f;
		box->moveBox(-0.05f,0.0f,0.0f);
	}
        updateLights(pos[0], pos[1], pos[2]);
}

void PlayerUFO::incrementZPos(bool positive){
	if(positive){
		pos[2] += 0.05f;
		box->moveBox(0.0f,0.0f,0.05f);
	}
	else{
		pos[2] -= 0.05f;
		box->moveBox(0.0f,0.0f,-0.05f);
	}
        updateLights(pos[0], pos[1], pos[2]);
}