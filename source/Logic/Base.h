/* 
 * File:   Base.h
 * Author: Addisson
 *
 * Created on February, 2012, 2:15 PM
 */

#ifndef BASE_H
#define	BASE_H

#include "Model.h"

class Base {
public:
    Base();
	Base(GLfloat x, GLfloat z);
    ~Base();
    void draw();
private:
    Model *model;
	GLfloat xPos;
	GLfloat zPos;

};

#endif

