#include <math.h>
#include "GameIncludes.h"

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

// PI
#define GL_PI 3.14159f

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
static double fovy = 60.0;

//camera rotation
static GLint rot = 0;
//camera location
static const GLfloat RADIUS = 10.0f;
static const GLfloat LOC_Y_INITIAL = RADIUS * tan(GL_PI / 4);

static GLfloat locX = 0.0f;
static GLfloat locY = LOC_Y_INITIAL;
static GLfloat locZ = RADIUS;

static bool wireframeView;

//demo purposes only   -jon
static int choice = 0;
static int nbOfChoices = 13;
//===================

bool* keyStates = new bool[256];

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
Base base;


void commanderCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
	
	gluLookAt(locX + RADIUS * sin(rot * 1.0f / 8), locY, locZ - RADIUS + RADIUS * cos(rot * 1.0f / 8), locX, 0, locZ - RADIUS, 0, 1, 0);
	//gluLookAt(locX + radius, locY, locZ, locX, 0, locZ - radius, 0, 1, 0);
}

static GLfloat denom = 4.0f;

void keyOperations()
{
	if (keyStates[GLUT_KEY_LEFT])
		--locX;
	else if (keyStates[GLUT_KEY_RIGHT])
		++locX;

	if (keyStates[GLUT_KEY_UP])
		--locZ;
	else if (keyStates[GLUT_KEY_DOWN])
		++locZ;

	if (keyStates[GLUT_KEY_PAGE_UP])
		rot++;
	else if (keyStates[GLUT_KEY_PAGE_DOWN])
		rot--;
	else if (keyStates[GLUT_KEY_END])
		rot = 0;

	if (keyStates[(int)'q'])
		choice = ++choice % nbOfChoices; 
		
	if (keyStates[(int)'w'])
		wireframeView = !wireframeView;
		
	if (keyStates[(int)'-'])
	{
		if (denom != 4.0f)
		{
			fovy++;
			denom -= 0.25f;
			locY = RADIUS * tan(GL_PI / denom);
		}
	}
	else if (keyStates[(int)'='])
	{
		fovy--;
		denom += 0.25f;
		locY = RADIUS * tan(GL_PI / denom);
	}
	else if (keyStates[(int)'0'])
	{
		fovy = 60.0f;
		locY = LOC_Y_INITIAL;
		denom = 4.0f;
	}	
	if (keyStates[27])
		exit(0);
	
}

void render()
{
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	keyOperations();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch (choice)
	{
	case 3:
		cannon.draw();
		break;
	case 1:
		missileLauncher.draw();
		break;
	case 2:
		phaser.draw();
		break;
	case 0:
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
	case 12:
		base.draw();
		break;
	}

	commanderCamera();

	glutSwapBuffers();
}


// Respond to window resizing, preserving proportions.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);

	commanderCamera();
}

void functionKeyUp(int key, int x, int y)
{
	keyStates[key] = false;
	glutPostRedisplay();
}

void functionKeys(int key, int x, int y)
{
	keyStates[key] = true;
	glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
	glutPostRedisplay();
}

void keyboardKeys(unsigned char key, int x, int y)
{
	keyStates[key] = true;	
	glutPostRedisplay();
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	wireframeView = false;
	pit2.switchPitType();


	for (int i = 0; i < 256; i++)
		keyStates[i] = false;
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
	glutSpecialFunc(functionKeys);
	glutKeyboardFunc(keyboardKeys);
	glutKeyboardUpFunc(keyUp);
	glutSpecialUpFunc(functionKeyUp);
	glutDisplayFunc(render);

	init();

	glutMainLoop();

	return 0;
}
