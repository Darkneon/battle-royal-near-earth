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
#include "BaseModel.h" //can take out later
#include "ElectronicsModel.h" //can take out later

LevelRenderer::LevelRenderer() {	
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			level[i][j] = 0;
		}
	}

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
	BaseModel *ebModel = new BaseModel;

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
	//models[11] = (Model*)lightRubbleModel;
	models[11] = (Model*)ebModel;
	//map1();
	level[0][0] = 11;

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

void LevelRenderer::map1(){
	
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			if(i == 0 || i == 49 || j == 0 || j == 49){
				level[i][j] = 3;
			}
			if(i > 1 && i < 18 && j > 1 && j < 18){
				if ((i+j)<25){
					level[i][j] = 1;
				}
			}
		}
	}
	level[25][5] = 4;
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
	level[40][15] = 11;
}