/* 
 * File:   LightPost.h
 * Author: Addison
 *
 * Created on February 19, 2012, 5:03 PM
 */

#ifndef LIGHTPOST_H
#define	LIGHTPOST_H

#include "Model.h"
#include "AntTweakHelper.h"

class LightPost { 
public:
	friend class AntTweakHelper;

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

	GLfloat axis[3];
	GLfloat rot;
};

#endif	/* LIGHTPOST_H */

