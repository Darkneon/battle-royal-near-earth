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
	bool isEndingPit;
    void drawPitOut();
	void drawPitIn();
	
};

#endif

