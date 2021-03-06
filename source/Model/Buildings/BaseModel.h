/* 
 * File:   BaseModel.h
 * Author: Addisson
 *
 * Created on January 31, 2012, 11:14 AM
 */

#ifndef BASEMODEL_H
#define	BASEMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"
//#include "FlagModel.h"

class BaseModel : Model {
public:
    BaseModel();
    void render();
    
private:
	void drawBase(GLfloat xPos, GLfloat yPos, GLfloat zPos);
	void renderGrass();
        TeamNumberModel *teamNumber;
        TeamNumberModel *teamNumber2;//Addison
        //FlagModel *flag;
};

#endif

