#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "LevelRenderer.h"
#include "Static/GrassModel.h"
#include "Static/HillsModel.h"
#include "Static/FenceModel.h"
#include "Static/HalfHollowBlockModel.h"
#include "Static/HalfPlainBlockModel.h"
#include "Static/HollowBlockModel.h"
#include "Static/MountainModel.h"
#include "Static/PitModel.h"
#include "Static/PlainBlockModel.h"
#include "Static/LightRubbleModel.h"
#include "Buildings/FactoryModel.h"
#include "Buildings/BaseModel.h"

//Robot Model includes
#include "Robot/AntiGravModel.h"
#include "Robot/BipodModel.h"
#include "Robot/TracksModel.h"
#include "Robot/CannonModel.h"
#include "Robot/MissileLauncherModel.h"
#include "Robot/PhaserModel.h"
#include "Robot/ElectronicsModel.h"
#include "Robot/NuclearModel.h"
#include "Robot/HeadlightModel.h"

LevelRenderer::LevelRenderer() {

	//skyboxes
	cubicSkyBox = new CubicSkybox();
	sphericSkyBox = new SphericSkybox();
	isSkySphere = false;

	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			level[i][j] = 0;
		}
	}

	//LIGHT
	//Initialize light objects
	spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);
	light1 = new LightPost(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f);
	light2 = new LightPost(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f);
	light3 = new LightPost(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f);
	light4 = new LightPost(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f);

	ambientLight = true;

	spotLight1 = true;
	spotLight2 = true;
	spotLight3 = true;
	spotLight4 = true;

	//Loading textures
	//DirectoryManipHelper::getDirectoryListing(".");

	//Terrain Models
	GrassModel *grassModel = new GrassModel; //0
        HillsModel *hillsModel = new HillsModel; //1
	MountainModel *mountainModel = new MountainModel; //2
	FenceModel *fenceModel = new FenceModel;
	HalfHollowBlockModel *halfHollowModel = new HalfHollowBlockModel;
	HalfPlainBlockModel *halfPlainModel = new HalfPlainBlockModel;
	HollowBlockModel *hollowModel = new HollowBlockModel;
	PlainBlockModel *plainModel = new PlainBlockModel;
	PitModel *pitTopModel = new PitModel;
	PitModel *pitInsideModel = new PitModel;
	PitModel *pitBottomModel = new PitModel;
	pitInsideModel->switchPitType();
	pitBottomModel->switchPitType();
	pitBottomModel->switchPitType();
	LightRubbleModel *lightRubbleModel = new LightRubbleModel;
	FactoryModel *factoryModel = new FactoryModel;
	HeadlightModel *headlightModel = new HeadlightModel;

	//Robot Models
	AntiGravModel *antiGravModel = new AntiGravModel;
	BipodModel *bipodModel = new BipodModel;
	TracksModel *tracksModel = new TracksModel;
	CannonModel *cannonModel = new CannonModel;
	MissileLauncherModel *missileLauncherModel = new MissileLauncherModel;
	PhaserModel *phaserModel = new PhaserModel;
	ElectronicsModel *electronicsModel = new ElectronicsModel;
	NuclearModel *nuclearModel = new NuclearModel;

	models[0] = (Model*)grassModel;
	models[1] = (Model*)hillsModel;
	models[2] = (Model*)mountainModel;
	models[3] = (Model*)fenceModel;
	models[4] = (Model*)halfHollowModel;
	models[5] = (Model*)halfPlainModel;
	models[6] = (Model*)hollowModel;
	models[7] = (Model*)plainModel;
	models[8] = (Model*)pitTopModel;
	models[9] = (Model*)pitInsideModel;
	models[10] = (Model*)pitBottomModel;
	models[11] = (Model*)lightRubbleModel;
	models[12] = (Model*)antiGravModel;
	models[13] = (Model*)bipodModel;
	models[14] = (Model*)tracksModel;
	models[15] = (Model*)cannonModel;
	models[16] = (Model*)missileLauncherModel;
	models[17] = (Model*)phaserModel;
	models[18] = (Model*)electronicsModel;
	models[19] = (Model*)nuclearModel;
	models[20] = (Model*)factoryModel;
	models[21] = (Model*)headlightModel;
	//Remove children from hierarchy so we can render these models individually
	models[12]->removeAllChildren(); 
	models[13]->removeAllChildren();
	models[14]->removeAllChildren();
	models[15]->removeAllChildren();
	models[16]->removeAllChildren();
	models[17]->removeAllChildren();
	map1();   
	buildMap();
} 

LevelRenderer::~LevelRenderer() {
    for (int i = 0; i != NUM_MODELS; i++) {
        if (models[i] != NULL) {
            delete models[i];
        }
    }

	glDeleteLists(1, 1);
}

void LevelRenderer::buildMap()
{
	//SKIN1
	glNewList(2, GL_COMPILE);
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {
			glPushMatrix();
				glTranslatef((GLfloat)i, (GLfloat)0, (GLfloat)j);
				models[ level[i][j] ]->draw();
			glPopMatrix();
		}
	}
	glEndList();

	//SKIN2
    glNewList(6, GL_COMPILE);
    TextureManager::getInstance()->toggleSkins();

	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			glPushMatrix();
				glTranslatef((GLfloat)i, (GLfloat)0, (GLfloat)j);
				models[ level[i][j] ]->draw();
			glPopMatrix();
		}
	}
	glEndList();
    
	//LIST FOR NO TEXTURES
	BoundingBox* tempBox;
	glNewList(5, GL_COMPILE);

	TextureManager::getInstance()->toggleTextures();

	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			glPushMatrix();
				glTranslatef((GLfloat)i, (GLfloat)0, (GLfloat)j);
				models[ level[i][j] ]->draw();
			glPopMatrix();
			switch(level[i][j]){
				case 1: case 6: case 7: //hills, plain and holloy block
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)j, (GLfloat)(i+1), 1.0f, (GLfloat)(j+1));
					lrBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 4: case 5: //half blocks
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)j, (GLfloat)(i+1),0.5f, (GLfloat)(j+1));
					lrBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 2: //mountains
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)j, (GLfloat)(i+2),3.75f, (GLfloat)(j+1));
					lrBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 3: //fence
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)j, (GLfloat)(i+1),2.75f, (GLfloat)(j+1));
					lrBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				default:
					break;
			}
		}
	}
	glEndList();
	delete tempBox;
    
}

//Todo: will probably change while we get more requirements
void LevelRenderer::render() {

	
//	for(int i = 0; i != 50; i++) {
//		for(int j = 0; j != 50; j++) {	
//			glPushMatrix();
//				glTranslatef((GLfloat)i, (GLfloat)0, (GLfloat)j);
//				models[ level[i][j] ]->draw();
//
//			glPopMatrix();
//		}
//	}
	
	if (!isSkySphere)
		cubicSkyBox->render();
	else
		sphericSkyBox->render();

	renderLights();

	if (TextureManager::getInstance()->texturesEnabled)
		 if (TextureManager::getInstance()->getCurrentSkin() == 0) {
            glCallList(2);
        }
        else {
            glCallList(6);
        }
	else {
          glCallList(5);
    }
		
		

	//Added by Jeff to see axes
	glPushMatrix();
		glBegin(GL_LINES);
			glColor3f(1,0,0);
			glVertex3f(0,0,0);
			glVertex3f(1,0,0);

			glColor3f(0,1,1);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);

			glColor3f(0,0,1);
			glVertex3f(0,0,0);
			glVertex3f(0,0,1);
		glEnd();
	glPopMatrix();
	
	//TO UNCOMMENT
	/*for(int i = 1; i != 49; i++) {
		for(int j = 23; j != 48; j++) {	
			glPushMatrix();
				glTranslatef((GLfloat)i, 0.0f, (GLfloat)j);
				models[0]->draw();
			glPopMatrix();
		}
	}*/
}

void LevelRenderer::map1(){

	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			if(i == 0 || i == 49 || j == 0 || j == 49){
				level[i][j] = 3;
			}
		}
	}
	level[35][40] = 20;
	for(int model = 1; model < 12; model++){
		for(int i = 5; i < 50; i += 5){
			level[i][model*2] = model;
		}

	}

    level[45][45] = 14;
    level[46][46] = 3;
    
	/*level[25][5] = 4;
	level[25][10] = 5;
	level[25][15] = 6;
	level[30][5] = 7;
	level[30][10] = 3;
	level[30][15] = 1;

	level[35][5] = 8;
	level[35][6] = 9;
	level[35][7] = 9;
	level[35][8] = 10;

	level[40][10] = 2;
	*/
}

bool LevelRenderer::getIsSkySphere(){
	return isSkySphere;
}

void LevelRenderer::toggleSkySphere(){
	isSkySphere = !isSkySphere;
}

/*void LevelRenderer::shadowMatrix(GLfloat shadowMat[4][4], GLfloat groundplane[4], GLfloat lightpos[4])
{
    GLfloat dot;
    //Find dot product between light position vector and ground plane normal
    dot =   groundplane[X]*lightpos[X] +
            groundplane[Z]*lightpos[Z] +
            groundplane[Y]*lightpos[Y] +
            groundplane[W]*lightpos[W];
    shadowMat[0][0] = dot-lightpos[X]*groundplane[X];
    shadowMat[1][0] = 0f-lightpos[X]*groundplane[Y];
    shadowMat[2][0] = 0f-lightpos[X]*groundplane[Z];
    shadowMat[3][0] = 0f-lightpos[X]*groundplane[X];
    shadowMat[X][1] = 0f-lightpos[Y]*groundplane[X];
    shadowMat[1][1] = dot - lightpos[Y]*groundplane[Y]; 
    shadowMat[2][1] = 0f - lightpos[Y]*groundplane[Z];
    shadowMat[3][1] = 0f - lightpos[Y]*groundplane[W];
    shadowMat[X][2] = 0f - lightpos[Z]*groundplane[X];
    shadowMat[1][2] = 0f - lightpos[Z]*groundplane[Y];
    shadowMat[2][2] = dot - lightpos[Z]*groundplane[Z];
    shadowMat[3][2] = 0f - lightpos[Z]*groundplane[W];
    shadowMat[X][3] = 0f - lightpos[W]*groundplane[X];
    shadowMat[1][3] = 0f - lightpos[W]*groundplane[Y];
    shadowMat[2][3] = 0f - lightpos[W]*groundplane[Z];
    shadowMat[3][3] = dot - lightpos[W]*groundplane[W];
    
}*/
void LevelRenderer::renderLights()
{		
		//ambient light
		GLfloat ambient_light[4];

		if(ambientLight){
			for(int i = 0; i<3;i++){
				ambient_light[i] = 0.45f;
			}
		}else{
			for(int i = 0; i<3;i++){
				ambient_light[i] = 0.2f;
			}
		}
		ambient_light[3]=1.0f;
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);// Allows color to reflect light
		//Set up a new light, namely... light0
        //New light... Light1
        glLightfv(GL_LIGHT1, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT1, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT1, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT1, GL_POSITION, light1->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1->getDirectionArray());
        //New light... Light2
        glLightfv(GL_LIGHT2, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT2, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT2, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT2, GL_POSITION, light2->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2->getDirectionArray());
        //New light... Light3
        glLightfv(GL_LIGHT3, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT3, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT3, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT3, GL_POSITION, light3->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 1);
        glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3->getDirectionArray());
        //New light... Light4
        glLightfv(GL_LIGHT4, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT4, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT4, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT4, GL_POSITION, light4->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4->getDirectionArray());
        //For enabling / disabling lights
        if(!spotLight1)
        {
                glDisable(GL_LIGHT1);
	} else {
            glEnable(GL_LIGHT1);
        }
        if(!spotLight2)
        {
                glDisable(GL_LIGHT2);
	} else {
            glEnable(GL_LIGHT2);
        }
        if(!spotLight3)
        {
                glDisable(GL_LIGHT3);
	} else {
       //     glEnable(GL_LIGHT3);
        }
        if(!spotLight4)
        {
                glDisable(GL_LIGHT4);
	} else {
            glEnable(GL_LIGHT4);
        }
        light1->render();
        light2->render();
        light3->render();
        light4->render();
        
}