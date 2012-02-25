/* 
 * File:   Material.h
 * Author: robert
 *
 * Created on February 24, 2012, 5:54 PM
 */

#ifndef MATERIAL_H
#define	MATERIAL_H


#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

class Material {
public:
    Material();    
    virtual void apply();
    
protected:    
    GLfloat refleciton[4];
    GLfloat diffuse[3];    
    GLint   shininess;
    
};

#endif	/* MATERIAL_H */

