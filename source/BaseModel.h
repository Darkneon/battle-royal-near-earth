/* 
 * File:   BaseModel.h
 * Author: Addisson
 *
 * Created on January 31, 2012, 11:14 AM
 */

#ifndef BASEMODEL_H
#define	BASEMODEL_H

#include "Model.h"
#include "TeamNumberModel.h"

class BaseModel : Model {
public:
    BaseModel();
    void render();
    
private:
	void drawBase(GLfloat xPos, GLfloat yPos, GLfloat zPos);
        TeamNumberModel *teamNumber;
        TeamNumberModel *teamNumber2;//Addison
};

#endif

