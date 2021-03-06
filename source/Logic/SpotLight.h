/* 
 * File:   SpotLight.h
 * Author: Addison
 *
 * Created on February 19, 2012, 6:15 PM
 */

#ifndef SPOTLIGHT_H
#define	SPOTLIGHT_H
#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

class SpotLight {
public:
    SpotLight(GLfloat, GLfloat, GLfloat, GLfloat);
    GLfloat* getAmbient();
    GLfloat* getDiffuse();
    GLfloat* getSpecular();
    GLfloat* getSpecref();
private:
    GLfloat ambientLight[4];
    GLfloat diffuseLight[4];
    GLfloat specular[4];
    GLfloat specref[4];       
};

#endif	/* SPOTLIGHT_H */

