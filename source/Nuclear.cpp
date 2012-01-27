/* 
 * File:   Nuclear.cpp
 * Author: Jeffrey
 * 
 * Created on January 27, 2012, 1:29 AM
 */

#include "Nuclear.h"
#include "NuclearModel.h"


Nuclear::Nuclear() 
{
      model = (Model*)(new NuclearModel);
}

Nuclear::~Nuclear() 
{
	if (model != NULL) 
	{
		delete model;
		model = NULL;
	}
}

void Nuclear::draw() 
{
    model->draw();
}
