/* 
 * File:   FlagModel.cpp
 * Author: robert
 * 
 * Created on April 2, 2012, 5:10 PM
 */

#include "FlagModel.h"

FlagModel::FlagModel() {
    knots[0] = 0.0f;
    knots[1] = 0.0f;
    knots[2] = 0.0f;
    knots[3] = 0.0f;
    knots[4] = 1.0f;
    knots[5] = 1.0f;
    knots[6] = 1.0f;
    knots[7] = 1.0f;
    
    //To save some typing :)
    GLfloat tempPoints[4][4][3] = {
                        {{  -0.5f, -0.5f, 0.0f},	// u = 0,	v = 0
                        {	-0.5f, -0.25f, 0.0f},	//			v = 1
                        {   -0.5f,  0.25f, 0.0f},	//			v = 2	
                        {   -0.5f,  0.5f, 0.0f}}, //			v = 3

                        {{  -0.25f, -0.5f, 0.0f},	// u = 1	v = 0
                        {   -0.25f, -0.25f, 0.25f},	//			v = 1
                        {   -0.25f,  0.25f, 0.0f},	//			v = 2
                        {   -0.25f,  0.5f, 0.0f}},	//			v = 3

                        {{    0.25f, -0.5f, 0.0f }, // u =2		v = 0
                        {    0.25f, -0.25f, 0.0f }, //			v = 1
                        {    0.25f,  0.25f, 0.25f },	//			v = 2
                        {    0.25f,  0.5f, 0.0f }},//			v = 3

                        {{    0.5f, -0.5f, 0.0f},	// u = 3	v = 0
                        {    0.5f, -0.25f, 0.0f},	//			v = 1
                        {    0.5f,  0.25f, 0.0f},	//			v = 2
                        {    0.5f,  0.5f, 0.25f}}};//			v = 3

    for (int i = 0; i != 4; i++) {
        for (int j = 0; j != 4; j++) {
            for (int k = 0; k != 3; k++) {
                ctrlPoints[i][j][k] = tempPoints[i][j][k];
            }
        }
    }
    
    nurb = NULL;
    
    angle = 0.0f;
    inc = 0.05;
}


FlagModel::~FlagModel() {
}

void FlagModel::render() {
    nurb = gluNewNurbsRenderer();
    gluNurbsProperty(nurb, GLU_SAMPLING_TOLERANCE, 25.0f);
    gluNurbsProperty(nurb, GLU_DISPLAY_MODE, (GLfloat)GLU_FILL);
    
    glPushMatrix();
        glRotatef(90.0f, 0, 1, 0);
        angle += inc;

        if (angle > 0.25 || angle < -0.25) {
            inc = -inc;
        }

        ctrlPoints[3][3][2] = angle;
        ctrlPoints[3][1][1] = angle;
        ctrlPoints[3][0][2] = angle / 2.0f;

        glDisable(GL_CULL_FACE);
        
        gluBeginSurface(nurb);
        gluNurbsSurface(nurb, 8, knots, 8, knots, 4*3, 3, &ctrlPoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
        gluEndSurface(nurb);

        glTranslatef(-0.6f, -1.5f, -0.05);
        glColor3f(0.0f, 1.0f, 1.0);
        GeoHelper::drawCube(0.0f, 0.0f, 0.0f, 0.1f, 2.0f, 0.1f);
        glEnable(GL_CULL_FACE);
     glPopMatrix();
     
     gluDeleteNurbsRenderer(nurb);
}