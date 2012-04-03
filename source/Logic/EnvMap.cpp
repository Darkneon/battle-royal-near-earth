#include "EnvMap.h"



EnvMap::EnvMap(void)
{
	width = 256;
}


EnvMap::~EnvMap(void)
{
}


void EnvMap::RegenerateEnvMap(LevelRenderer *level, GLfloat cameraX, GLfloat cameraZ) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, 1.0f, 1.0f, 125.0f);
	glViewport(0, 0, width, width);

	for(GLenum i = GL_TEXTURE_CUBE_MAP_POSITIVE_X; i < GL_TEXTURE_CUBE_MAP_POSITIVE_X + 6; i++) {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		  switch (i)
        {
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
            // +X
            gluLookAt(cameraX, 1.0f, cameraZ, 
                      1.0f, 0.0f, cameraZ, 0.0f, -1.0f, 0.0f);
            break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
            // -X
            gluLookAt(cameraX, 1.0f, cameraZ, 
                      -1.0f, 0.0f, cameraZ +5, 0.0f, -1.0f, 0.0f);
            break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
            // +Y
            gluLookAt(cameraX, 0.0f, cameraZ, 
                      cameraX, 1.0f, cameraZ, 0.0f, 0.0f, 1.0f);
            break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
            // -Y
            gluLookAt(cameraX, 1.0f, cameraZ, 
                      cameraX, -1.0f, cameraZ, 0.0f, 0.0f, -1.0f);
            break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
            // +Z
            gluLookAt(cameraX, 1.0f, cameraZ, 
                      cameraX, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f);
            break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
            // -Z
            gluLookAt(cameraX, 1.0f, cameraZ, 
                      cameraX, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f);
            break;
        }

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		level->render();
		glCopyTexImage2D(i, 0, GL_RGBA8, 0, 0, width, width, 0);
	}

	

	
}

void EnvMap::tex() {
	glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[4]);
        glDisable(GL_LIGHTING);

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

        GLubyte *texels = (GLubyte *)malloc(width * width * 4);
        

        for (GLenum i = GL_TEXTURE_CUBE_MAP_POSITIVE_X; i < GL_TEXTURE_CUBE_MAP_POSITIVE_X+6; i++)
        {
            // Grab the cubemap face
            glGetTexImage(i, 0, GL_RGBA, GL_UNSIGNED_BYTE, texels);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, width,0, GL_RGBA, GL_UNSIGNED_BYTE, texels);

            glPushMatrix();

            // position the cube face for display
            switch (i)
            {
            case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
                glTranslatef(0.25f, 0.0f, 0.0f);
                break;
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
                glTranslatef(-0.75f, 0.0f, 0.0f);
                break;
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
                glTranslatef(-0.25f, -0.5f, 0.0f);
                break;
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
                glTranslatef(-0.25f, 0.5f, 0.0f);
                break;
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
                glTranslatef(-0.25f, 0.0f, 0.0f);
                break;
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
                glTranslatef(+0.75f, 0.0f, 0.0f);
                break;            
            }

            glScalef(0.25f, 0.25f, 0.25f);

            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex2f(-1.0f, -1.0f);
                glTexCoord2f(1.0f, 0.0f);
                glVertex2f(1.0f, -1.0f);
                glTexCoord2f(1.0f, 1.0f);
                glVertex2f(1.0f, 1.0f);
                glTexCoord2f(0.0f, 1.0f);
                glVertex2f(-1.0f, 1.0f);
            glEnd();

            glPopMatrix();
        }

        free(texels);

        glDisable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
}
void EnvMap::init() {	
	// This texture will be used for displaying the envmap for education purposes
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	 // Set up some more texture state that never changes
    glGenTextures(1, &envMapTextureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, envMapTextureID);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP, 1);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
    glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);

	    // this may change with window size changes
    for (GLenum i = GL_TEXTURE_CUBE_MAP_POSITIVE_X; i < GL_TEXTURE_CUBE_MAP_POSITIVE_X+6; i++)
    {
        glTexImage2D(i, 0, GL_RGBA8, width, width, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    }
}

void EnvMap::cleanup() {
}
