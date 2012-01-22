

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "Player.h"
#include "Fence.h"

// Initial size of graphics window.
const int WIDTH  = 600;
const int HEIGHT = 400;

// Current size of window.
int width  = WIDTH;
int height = HEIGHT;

// Bounds of viewing frustum.
double nearPlane =  1.0;
double farPlane  = 85.0;

// Viewing angle.
double fovy = 45.0;

static GLint rotX = 0;
static GLint rotY = 0;

Player player;
Fence fence;
//the vertices
//==============================================================================
GLfloat vPhasersBase[] = { -1.0f,  0.5f,  1.0f, //v1
					        1.0f,  0.5f,  1.0f, //v2
					        1.0f, -0.5f,  1.0f, //v3
					       -1.0f, -0.5f,  1.0f, //v4
					       -1.0f, -0.5f, -1.0f, //v5
					        1.0f, -0.5f, -1.0f, //v6
						    1.0f,  0.5f, -1.0f, //v7
					       -1.0f,  0.5f, -1.0f}; //v8

//==============================================================================


//sets up rendering context
void render()
{
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//preps the 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rotX * 10, 1, 0, 0);
	glRotatef(rotY * 10, 0, 1, 0);
	

    player.draw();
    fence.draw();

	glutSwapBuffers();
	glutPostRedisplay();
}

// Respond to window resizing, preserving proportions.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

	glEnable(GL_DEPTH_TEST);
}

void functionKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		rotY++;
		break;
	
	case GLUT_KEY_RIGHT:
		rotY--;
		break;

	case GLUT_KEY_UP:
		rotX++;
		break;

	case GLUT_KEY_DOWN:
		rotX--;
		break;
	}
}

int main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Robots mid and top");

	//callbacks
	glutReshapeFunc(reshapeMainWindow);
	glutDisplayFunc(render);
	glutSpecialFunc(functionKeys);
	
	glutMainLoop();

	return 0;
}
