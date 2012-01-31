#include <math.h>

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif
#include "GameIncludes.h"


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
double fovy = 60.0;

static GLint rotX = 0;
static GLint rotY = 0;

static int choice = 0;
static int nbOfChoices = 12;

Player player;
Fence fence;
Mountain mountain;
Phaser phaser;
Cannon cannon;
HollowBlock hollowBlock;
HalfHollowBlock halfHollowBlock;
PlainBlock plainBlock;
HalfPlainBlock halfPlainBlock;
MissileLauncher missileLauncher;
Pit pit;
Pit pit2;
Electronics electronics;
Nuclear nuclear;
Grass grass;
LevelRenderer levelRenderer;



void render()
{
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rotX * 10, 1, 0, 0);
	glRotatef(rotY * 10, 0, 1, 0);

	switch (choice)
	{
	case 0:
		cannon.draw();
		break;
	case 1:
		missileLauncher.draw();
		break;
	case 2:
		phaser.draw();
		break;
	case 3:
	 //   player.draw();
		//fence.draw();
		//mountain.draw();
  //      grass.draw();
		levelRenderer.render();
		break;
	case 4:
		plainBlock.draw();
		break;
	case 5:
		halfPlainBlock.draw();
		break;
	case 6:
		hollowBlock.draw();
		break;
	case 7:
		halfHollowBlock.draw();
		break;
	case 8:
		pit.draw();
		break;
	case 9:
		pit2.draw();
		break;
	case 10:
		electronics.draw();
		break;
	case 11:
		nuclear.draw();
		break;
	}

	glutSwapBuffers();
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
	glutPostRedisplay();
}

void keyboardKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		choice = ++choice % nbOfChoices; 
		break;

	case 27:
		exit(0);
	}

	glutPostRedisplay();
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	pit2.switchPitType();
}

int main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Battle Royale Near Earth");

	//callbacks	
	glutReshapeFunc(reshapeMainWindow);
	glutDisplayFunc(render);
	glutSpecialFunc(functionKeys);
	glutKeyboardFunc(keyboardKeys);

	init();

	glutMainLoop();

	return 0;
}
