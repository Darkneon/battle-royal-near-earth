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
static const GLfloat DEFAULT_RADIUS = 10.0f;
static const GLfloat BIRD_SIGHT_RADIUS = 45.0f;
static GLfloat currentRadius = DEFAULT_RADIUS;
static GLfloat locX = 25.0f;
static GLfloat locY = 0.0f;
static GLfloat locZ = 25.0f + DEFAULT_RADIUS;

static GLfloat yaw = 0.0f;
static GLfloat pitch = 0.0f;

static bool wireframeView;
static bool birdSightView;
static bool mouseLook;

bool keyStates[256];
bool funcKeyStates[256];

static GLfloat denom = 4.0f; //used for zoom effect

const static int CENTER_X = width / 2;
const static int CENTER_Y = height / 2;

Player player;
LevelRenderer levelRenderer;
Base base;
Robot robot;


void calculate45DegreesForLocY()
{
	locY = currentRadius * tan(GL_PI / 4);
}

void commanderCamera()
{
	gluLookAt(locX + currentRadius * sin(rot * 1.0f / 8), locY, locZ - currentRadius + currentRadius * cos(rot * 1.0f / 8),
		locX, 0, locZ - currentRadius, 0, 1, 0);
}

void freeLookCamera()
{

	gluLookAt(locX, locY, locZ, locX + sin(yaw * 1.0f / 64), locY - sin(pitch * 1.0f / 64), locZ - cos(yaw * 1.0f / 64)/*- 99.0f */,  0.0f, 1.0f, 0.0f);
	//yaw = pitch = 0.0f;
}

void funcKeyOperations()
{
	if (funcKeyStates[GLUT_KEY_LEFT])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ += moveVector[0];
		locX -= moveVector[1];	
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_RIGHT])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ -= moveVector[0];
		locX += moveVector[1];
		glutPostRedisplay();
	}

	if (funcKeyStates[GLUT_KEY_UP])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ -= moveVector[1];
		locX -= moveVector[0];
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_DOWN])
	{
		GLfloat moveVector[] = {1 * sin(rot * 1.0f / 8), 1 * cos(rot * 1.0f / 8)};
		locZ += moveVector[1];
		locX += moveVector[0];
		glutPostRedisplay();
	}

	if (funcKeyStates[GLUT_KEY_PAGE_UP])
	{
		if (!mouseLook)
			rot++;
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_PAGE_DOWN])
	{
		if (!mouseLook)
			rot--;
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_END])
	{
		rot = 0;
		glutPostRedisplay();
	}

}

void keyOperations()
{
	
	if (keyStates[99]) //c
	{
		mouseLook = !mouseLook;
	}

	if (keyStates[122]) //z
	{
		birdSightView = !birdSightView;
		mouseLook = false;
		
		GLfloat zeeDistanze = BIRD_SIGHT_RADIUS - DEFAULT_RADIUS;
		if (birdSightView)
		{
			currentRadius = BIRD_SIGHT_RADIUS;
			locZ += zeeDistanze;
		}
		else
		{
			currentRadius = DEFAULT_RADIUS;
			locZ -= zeeDistanze;
		}
		
		calculate45DegreesForLocY();
	}
		
	if (keyStates[119])//w
	{ 
		wireframeView = !wireframeView;
		if(wireframeView)
		{
			glDisable(GL_DEPTH_TEST);
			glPolygonMode(GL_BACK, GL_LINE);
			glPolygonMode(GL_FRONT, GL_LINE);
			
		}
		else
		{
			glEnable(GL_DEPTH_TEST);
			glPolygonMode(GL_BACK, GL_FILL);
			glPolygonMode(GL_FRONT, GL_FILL);
		}

	}
		
    if (keyStates[116]) //t
	{ 
        robot.changeTop();
		glutPostRedisplay();
    }
  
    if (keyStates[121]) //y
	{ 
        robot.changeMiddle();
		glutPostRedisplay();
    }

      
    if (keyStates[117]) //u
	{ 
        robot.changeBottom();
		glutPostRedisplay();
    }
    
	if (keyStates[45]) //-
	{
		if (denom != 4.0f)
		{
			fovy++;
			denom -= 0.25f;
			locY = currentRadius * tan(GL_PI / denom);
			glutPostRedisplay();
		}
	}
	else if (keyStates[61]) //=
	{
		if (fovy > 10)
		{
			fovy--;
			denom += 0.25f;
			locY = currentRadius * tan(GL_PI / denom);
			glutPostRedisplay();
		}
	}
	else if (keyStates[48]) //0
	{
		fovy = 60.0f;
		calculate45DegreesForLocY();
		denom = 4.0f;
		glutPostRedisplay();
	}	


	if (keyStates[27]) //escape
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
    

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);

	if (!mouseLook)
		commanderCamera();
	else
		freeLookCamera();

	glutSwapBuffers();
}


// Respond to window resizing, preserving proportions.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);
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

	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = false;

	glutPostRedisplay();
}

void keyboardKeys(unsigned char key, int x, int y)
{
	keyStates[key] = true;

	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = true;

	glutPostRedisplay();
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	wireframeView = false;
	birdSightView = false;
	mouseLook = false;

	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
		funcKeyStates[i] = false;
	}

	calculate45DegreesForLocY();
	glutSetCursor(GLUT_CURSOR_NONE);

}

void passiveMotionFunc(int x, int y)
{
	int diffX, diffY;

	diffX = x - CENTER_X;
	diffY = y - CENTER_Y;

	if (diffX != 0 || diffY != 0)
	{
		//SetCursorPos(CENTER_X + glutGet(GLUT_WINDOW_X), CENTER_Y + glutGet(GLUT_WINDOW_Y));
		glutWarpPointer(CENTER_X, CENTER_Y);
		yaw += diffX;
		pitch += diffY;
		glutPostRedisplay();
	}
}


void motionFunc(int x, int y){}


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

	//mouse motion
	glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	
	init();

	glutMainLoop();

	return 0;
}
