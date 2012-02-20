#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "SpotLight.h"



SpotLight::SpotLight(GLfloat ambient, GLfloat diffuse, GLfloat specu, GLfloat specr)
{
        ambientLight[0] = ambient;
        ambientLight[1] = ambient;
        ambientLight[2] = ambient;
        ambientLight[3] = 1.0f;
        diffuseLight[0] = diffuse;
        diffuseLight[1] = diffuse;
        diffuseLight[2] = diffuse;
        diffuseLight[3] = 1.0f;
        specular[0] = specu;
        specular[1] = specu;
        specular[2] = specu;
        specular[3] = 1.0f;
        specref[0] = specr;
        specref[1] = specr;
        specref[2] = specr;
        specref[1] = 1.0f;
}
GLfloat* SpotLight::getAmbient()
{
    return ambientLight;
}
GLfloat* SpotLight::getDiffuse()
{
    return diffuseLight;
}
GLfloat* SpotLight::getSpecular()
{
    return specular;
}
GLfloat* SpotLight::getSpecref()
{
    return specref;
}