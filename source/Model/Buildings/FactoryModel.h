/* 
 * File:   BaseModel.h
 * Author: Addisson
 *
 * Created on February 2, 2012, 11:14 AM
 */
#ifndef FACTORYMODEL_H
#define	FACTORYMODEL_H

#include "Model.h"

class FactoryModel:Model
{
public:
	FactoryModel(void);
	//~FactoryModel(void);
	void render();
private:
	void drawFactory(GLfloat xPos, GLfloat yPos, GLfloat zPos);
};
#endif
