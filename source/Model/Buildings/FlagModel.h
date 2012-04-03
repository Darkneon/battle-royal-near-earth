/* 
 * File:   FlagModel.h
 * Author: robert
 *
 * Created on April 2, 2012, 5:10 PM
 */

#ifndef FLAGMODEL_H
#define	FLAGMODEL_H

#include "Model.h"

class FlagModel : public Model {
public:
    FlagModel();
    ~FlagModel();
    void render();
private:
    GLUnurbsObj *nurb;
    GLfloat knots[8];
    GLfloat ctrlPoints[4][4][3];
    GLfloat angle;
    GLfloat inc;

       
};

#endif	/* FLAGMODEL_H */

