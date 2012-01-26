#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "LevelRenderer.h"
#include "GrassModel.h"

LevelRenderer::LevelRenderer() {	
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			level[i][j] = 0;
		}
	}

	GrassModel *grassModel = new GrassModel;
	models[0] = (Model*)grassModel;
} 


//Todo: will probably change while we get more requirements
void LevelRenderer::render() {
	for(int i = 0; i != 50; i++) {
		for(int j = 0; j != 50; j++) {	
			glPushMatrix();
				glTranslatef(i, 0, j);
				models[0]->draw();
			glPopMatrix();
		}
	}
}