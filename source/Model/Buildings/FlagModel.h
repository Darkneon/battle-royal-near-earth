/* 
 * File:   FlagModel.h
 * Author: Addison
 *
 * Created on April 2, 2012, 3:04 PM
 */
#include "Model.h"

#ifndef FLAGMODEL_H
#define	FLAGMODEL_H

class FlagModel {
public:
    FlagModel(GLfloat, GLfloat, GLfloat);
    FlagModel();
    //FlagModel(const FlagModel& orig);
    //virtual ~FlagModel();
    void render();
private:
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    GLfloat y;
    bool inc;
};

#endif	/* FLAGMODEL_H */

