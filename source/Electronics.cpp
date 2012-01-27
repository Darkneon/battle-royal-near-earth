/* 
 * File:   Electronics.cpp
 * Author: Jeffrey
 * 
 * Created on January 27, 2012, 1:12 AM
 */

#include "Electronics.h"
#include "ElectronicsModel.h"


Electronics::Electronics() 
{
      model = (Model*)(new ElectronicsModel);
}

Electronics::~Electronics() 
{
	if (model != NULL) 
	{
		delete model;
		model = NULL;
	}
}

void Electronics::draw() 
{
    model->draw();
}
