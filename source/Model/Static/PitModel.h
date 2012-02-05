/* 
 * File:   PitModel.h
 * Author: Jeffrey
 *
 * Created on January 26, 2012, 8:57 PM
 */

#ifndef PITMODEL_H
#define	PITMODEL_H

#include "Model.h"

class PitModel : Model {
public:
    PitModel();
	PitModel(bool isEndingPit);
    void render();
	void switchPitType();

private:
	int pitType;
    void drawPitTop();
	void drawPitIn();
	void drawPitBottom();
	void drawSquare();
	void drawColoredCube(GLfloat* tColor, GLfloat* bColor, GLfloat* lColor, GLfloat* rColor, GLfloat* nColor, GLfloat* fColor);
	
};

#endif

