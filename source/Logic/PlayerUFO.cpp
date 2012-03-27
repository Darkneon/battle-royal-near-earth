#include "PlayerUFO.h"

PlayerUFO::PlayerUFO(void)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
}

PlayerUFO::PlayerUFO(GLfloat x, GLfloat z)
{
	PlayerModel* p = new PlayerModel;
	pModel = (Model*)p;
	pos = new GLfloat[3];
	pos[0] = x;
	pos[1] = 0;
	pos[2] = z;
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
		glTranslatef(pos[0],pos[1],pos[2]);
		pModel->draw();
	glPopMatrix();
                updateLights(pos[0], pos[1], pos[2]);

        
}

void PlayerUFO::incrementHeight(bool positive){
	if(positive){
		if(pos[1]+0.5f <= MAX_PLAYER_HEIGHT){
			pos[1] += 0.5f;
		}
	}
	else{
		if(pos[1]-0.2f >= MIN_PLAYER_HEIGHT){
			pos[1] -= 0.2f;
		}
	}
        updateLights(pos[0], pos[1], pos[2]);
}