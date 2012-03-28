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

#include <fstream>
//Robot Model includes
/*#include "Robot/AntiGravModel.h"
#include "Robot/BipodModel.h"
#include "Robot/TracksModel.h"
#include "Robot/CannonModel.h"
#include "Robot/MissileLauncherModel.h"
#include "Robot/PhaserModel.h"
#include "Robot/ElectronicsModel.h"
#include "Robot/NuclearModel.h"
#include "Robot/HeadlightModel.h"*/

LevelRenderer::LevelRenderer() {

	loadmap = "map1.txt";

	//skyboxes
	isSkySphere = false;

	//LIGHT
	//Initialize light objects
	spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);

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
	BaseModel *baseModel = new BaseModel;;

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
	models[12] = (Model*)factoryModel;
	models[13] = (Model*)baseModel;

	map();   
	buildMap();
} 

LevelRenderer::~LevelRenderer() {
    for (int i = 0; i != NUM_MODELS; i++) {
        if (models[i] != NULL) {
            delete models[i];
        }
    }

	glDeleteLists(1, 1);

	for (int i = 0; i < rows; ++i){
        delete[] level[i];
		level[i] = NULL;
	}

    delete[] level;
	level = NULL;
}

void LevelRenderer::buildMap()
{
	//SKIN1
	glNewList(2, GL_COMPILE);
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(i == 35 && j == 40){
				int k = 9;
			}
			glPushMatrix();
				glTranslatef((GLfloat)j, (GLfloat)0, (GLfloat)i);
				models[ level[i][j] ]->draw();

				//also draw a grass tile under models
				if(level[i][j] !=0 && level[i][j] !=3){
					models[0]->draw();
				}
			glPopMatrix();
		}
	}
	glEndList();

	//SKIN2
    glNewList(6, GL_COMPILE);
    TextureManager::getInstance()->toggleSkins();

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {	
			glPushMatrix();
				glTranslatef((GLfloat)j, (GLfloat)0, (GLfloat)i);
				models[ level[i][j] ]->draw();

				//also draw a grass tile under models
				if(level[i][j] !=0 && level[i][j] !=3){
					models[0]->draw();
				}
			glPopMatrix();
		}
	}
	glEndList();
    
	//LIST FOR NO TEXTURES
	BoundingBox* tempBox;
	glNewList(5, GL_COMPILE);

	TextureManager::getInstance()->toggleTextures();

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {	
			glPushMatrix();
				glTranslatef((GLfloat)j, (GLfloat)0, (GLfloat)i);
				models[ level[i][j] ]->draw();

				//also draw a grass tile under models
				if(level[i][j] !=0 && level[i][j] !=3){
					models[0]->draw();
				}
			glPopMatrix();
			switch(level[i][j]){
				case 1: case 6: case 7: //hills, plain and holloy block
					tempBox = new BoundingBox((GLfloat)j, 0.0f, (GLfloat)i, (GLfloat)(j+1), 1.0f, (GLfloat)(i+1));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 4: case 5: //half blocks
					tempBox = new BoundingBox((GLfloat)j, 0.0f, (GLfloat)i, (GLfloat)(j+1),0.5f, (GLfloat)(i+1));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 2: //mountains
					tempBox = new BoundingBox((GLfloat)j, 0.0f, (GLfloat)i, (GLfloat)(j+2),3.75f, (GLfloat)(i+1));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 3: //fence
					tempBox = new BoundingBox((GLfloat)j, 0.0f, (GLfloat)i, (GLfloat)(j+1),2.75f, (GLfloat)(i+1));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
					break;
				case 13://base
					//5.0f,1.25f,4.0f
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)j, (GLfloat)(i+5.0f),1.25f, (GLfloat)(j+2.5f));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
					tempBox = new BoundingBox((GLfloat)(i+1.0f), 0.0f, (GLfloat)(j+2.5f), (GLfloat)(i+4.0f),0.75f, (GLfloat)(j+4.0f));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
				case 12://factory
					//3.0f,1.25f,2.0f
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)j, (GLfloat)(i+3.0f),1.25f, (GLfloat)(j+1.0f));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
					tempBox = new BoundingBox((GLfloat)i, 0.0f, (GLfloat)(j+1.0f), (GLfloat)(i+3.0f),0.75f, (GLfloat)(j+2.0f));
					lrBoxes->staticBoxes.push_back(tempBox);
					tempBox->draw();
				default:
					break;
			}
		}
	}
	glEndList();
	delete tempBox;
    
}

void LevelRenderer::render() {
	
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
	
}

void LevelRenderer::map(){
	
	ifstream openfile;
	openfile.open((TextureManager::getResourcePath() +"/maps/" + loadmap).c_str(), ios::in);
	
	if (openfile.is_open()) {
		openfile >> rows;
		openfile >> columns;

		//skyboxes
		cubicSkyBox = new CubicSkybox(rows, columns);
		sphericSkyBox = new SphericSkybox(rows, columns);
	
		//adjusting the lights with the map
		light1 = new LightPost(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f);
		light2 = new LightPost((GLfloat)columns, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f);
		light3 = new LightPost((GLfloat)columns, 6.0f, (GLfloat)rows, -2.5f, -2.5f, -2.5f);
		light4 = new LightPost(0.0f, 6.0f, (GLfloat)rows, 2.5f, -2.5f, -2.5f);

		//creating the map
		level = new int*[rows];
		for(int i = 0; i<rows; i++){
			level[i] = new int[columns];
		}
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < columns; ++j){
				int temp;
				openfile >> temp;

				level[i][j] = temp;

			}
		}
		openfile.close();
	}

}

bool LevelRenderer::getIsSkySphere(){
	return isSkySphere;
}

void LevelRenderer::toggleSkySphere(){
	isSkySphere = !isSkySphere;
}

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
           glEnable(GL_LIGHT3);
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