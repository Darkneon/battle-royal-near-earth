#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "LevelRenderer.h"
#include "GrassModel.h"
#include "HillsModel.h"
#include "FenceModel.h"
#include "HalfHollowBlockModel.h"
#include "HalfPlainBlockModel.h"
#include "HollowBlockModel.h"
#include "MountainModel.h"
#include "PitModel.h"
#include "PlainBlockModel.h"
#include "LightRubbleModel.h"
#include "FactoryModel.h"
#include "BaseModel.h"

//Robot Model includes
#include "AntiGravModel.h"
#include "BipodModel.h"
#include "TracksModel.h"
#include "CannonModel.h"
#include "MissileLauncherModel.h"
#include "PhaserModel.h"
#include "ElectronicsModel.h"
#include "NuclearModel.h"


LevelRenderer::LevelRenderer() {	
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			level[i][j] = 0;
		}
	}
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
	models[19]->removeAllChildren();
	map1();
	//level[0][0] = 16;

	

} 

LevelRenderer::~LevelRenderer() {
    for (int i = 0; i != NUM_MODELS; i++) {
        if (models[i] != NULL) {
            delete models[i];
        }
    }
}

//Todo: will probably change while we get more requirements
void LevelRenderer::render() {
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			glPushMatrix();
				glTranslatef(i, 0, j);
				models[ level[i][j] ]->draw();

			glPopMatrix();
		}
	}
	//Added by Jeff to see axes
	/*glPushMatrix();
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
	glPopMatrix();*/
	//Added by Jeff to put layer of grass under robot models
	for(int i = 1; i != 49; i++) {
		for(int j = 23; j != 48; j++) {	
			glPushMatrix();
				glTranslatef(i, 0, j);
				models[0]->draw();
			glPopMatrix();
		}
	}
}

void LevelRenderer::map1(){
	
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			if(i == 0 || i == 49 || j == 0 || j == 49){
				level[i][j] = 3;
			}
			/*if(i > 1 && i < 18 && j > 1 && j < 18){
				if ((i+j)<25){
					level[i][j] = 1;
				}
			}*/
		}
	}
	level[25][40] = 20;
	for(int model = 1; model < 20; model++){
		for(int i = 5; i < 50; i += 5){
			level[i][model*2] = model;
		}

	}

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
	level[40][15] = 11;*/
}