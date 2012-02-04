#include <math.h>
#include "GameIncludes.h"

#ifdef __APPLE__
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
double farPlane  = 100.0;

// Viewing angle.
static double fovy = 60.0;

//camera rotation
static GLint rot = 0;
//camera location
static const GLfloat RADIUS = 20.0f;
static const GLfloat LOC_Y_INITIAL = RADIUS * tan(GL_PI / 4);
//static const GLfloat LOC_Y_INITIAL = 0;
static GLfloat locX = 25.0f;
static GLfloat locY = LOC_Y_INITIAL;
static GLfloat locZ = 25.0f + RADIUS;

static bool wireframeView;

bool* keyStates = new bool[256];
bool* funcKeyStates = new bool[256];

Player player;
LevelRenderer levelRenderer;
Base base;
Robot robot;

void commanderCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);

	gluLookAt(locX + RADIUS * sin(rot * 1.0f / 8), locY, locZ - RADIUS + RADIUS * cos(rot * 1.0f / 8),
		locX, 0, locZ - RADIUS, 0, 1, 0);
}


void funcKeyOperations()
{
	if (funcKeyStates[GLUT_KEY_LEFT])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ += moveVector[0];
		locX -= moveVector[1];	
	}
	else if (funcKeyStates[GLUT_KEY_RIGHT])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ -= moveVector[0];
		locX += moveVector[1];
	}

	if (funcKeyStates[GLUT_KEY_UP])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ -= moveVector[1];
		locX -= moveVector[0];
	}
	else if (funcKeyStates[GLUT_KEY_DOWN])
	{
		GLfloat moveVector[] = { 0 + 1 * sin(rot * 1.0f / 8), 0 + 1 * cos(rot * 1.0f / 8)};
		locZ += moveVector[1];
		locX += moveVector[0];
	}

	if (funcKeyStates[GLUT_KEY_PAGE_UP])
		rot++;
	else if (funcKeyStates[GLUT_KEY_PAGE_DOWN])
		rot--;
	else if (funcKeyStates[GLUT_KEY_END])
		rot = 0;
}

static GLfloat denom = 4.0f;

void keyOperations()
{
	if (keyStates[(int)'z'])
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);

		GLfloat newRadius = 65.0f;
		gluLookAt(newRadius, newRadius/2 * tan(GL_PI / 4), newRadius,
			25, 0, 25, 0, 1, 0);
	}
		
	if (keyStates[(int)'w']){
		wireframeView = !wireframeView;
		if(wireframeView){
			glPolygonMode(GL_BACK, GL_LINE);
			glPolygonMode(GL_FRONT, GL_LINE);
		}else{
			glPolygonMode(GL_BACK, GL_FILL);
			glPolygonMode(GL_FRONT, GL_FILL);
		}

	}
		
    if (keyStates[(int)'t']) {
        robot.changeTop();
    }
  
    if (keyStates[(int)'y']) {
        robot.changeMiddle();
    }

      
    if (keyStates[(int)'u']) {
        robot.changeBottom();
    }
    
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

	funcKeyOperations();
	keyOperations();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	levelRenderer.render();
	//Drawing robot models on map
	glPushMatrix();
		glTranslatef(15,0,40);
		player.draw();
		glTranslatef(1,0,0);
		base.draw();
		glTranslatef(7,0,5);
		robot.draw();

	glPopMatrix();
    
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
	funcKeyStates[key] = false;
	glutPostRedisplay();
}

void functionKeys(int key, int x, int y)
{
	funcKeyStates[key] = true;
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

	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
		funcKeyStates[i] = false;
	}
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

	delete keyStates;
	delete funcKeyStates;

	return 0;
}
