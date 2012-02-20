/* 
 * File:   LightPost.h
 * Author: Addison
 *
 * Created on February 19, 2012, 5:03 PM
 */

#ifndef LIGHTPOST_H
#define	LIGHTPOST_H

#include "Model.h"
class LightPost { 
public:
    LightPost(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
    void render();
    GLfloat getPosX();
    GLfloat getPosY();
    GLfloat getPosZ();
    void setPosX(GLfloat);
    void setPosY(GLfloat);
    void setPosZ(GLfloat);
    void updatePosition(GLfloat, GLfloat, GLfloat);
    GLfloat getLookX();
    GLfloat getLookY();
    GLfloat getLookZ();
    GLfloat* getPositionArray(); //NEED HELP GETTING THESE TO WORK
    GLfloat* getDirectionArray();
private:
    GLfloat posX;
    GLfloat posY; 
    GLfloat posZ;
    GLfloat lookX;
    GLfloat lookY;
    GLfloat lookZ;
    GLfloat lightPos[4];
    GLfloat spotDir[3];
};

#endif	/* LIGHTPOST_H */

