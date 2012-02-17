#include <math.h>

#include "GameIncludes.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "TweakAnt/AntTweakBar.h"

// PI
#define GL_PI 3.14159f

// Current size of window.
int width  = 600;
int height = 600;

//	old values for the window (used to come back from fullscreen)
int oldWidth = width;
int oldHeight = height;

// Current position of the window
int winPosX = 0;
int winPosY = 0;

// Bounds of viewing frustum.
double nearPlane =  1.0;
double farPlane  = 100.0;

// Viewing angle.
const static double DEFAULT_FOVY = 60.0;
static double fovy = DEFAULT_FOVY;

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

GLfloat color[] = { 0.0f, 1.0f, 0.0f};

static bool wireframeView;
static bool birdSightView;
static bool mouseLook;

bool keyStates[256];
bool funcKeyStates[256];
int keyModifier = NULL;

static bool isInFullScreenMode;
static bool isDebugMode = true;

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
	GLfloat toAddY = pitch / 128.0f;

	gluLookAt(locX, locY, locZ, locX - sin(yaw * 1.0f / 64), locY - toAddY, locZ + cos(yaw * 1.0f / 64),  
		0.0f, 1.0f, 0.0f);
}

// Respond to window resizing, preserving proportions.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;

	glViewport(0, 0, width, height);
	TwWindowSize(width, height);
}


void funcKeyOperations()
{
	if (funcKeyStates[GLUT_KEY_LEFT])
	{
		if (!mouseLook)
		{
			GLfloat moveVector[] = {sin(rot * 1.0f / 8), cos(rot * 1.0f / 8)};
			locZ += moveVector[0];
			locX -= moveVector[1];
		}
		else
		{	
			GLfloat moveVector[] = {sin(yaw * 1.0f / 64), -cos(yaw * 1.0f / 64)};
			locX -= moveVector[1];
			locZ += moveVector[0];
		}

		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_RIGHT])
	{
		if (!mouseLook)
		{
			GLfloat moveVector[] = {sin(rot * 1.0f / 8), cos(rot * 1.0f / 8)};
			locZ -= moveVector[0];
			locX += moveVector[1];
		}
		else
		{	
			GLfloat moveVector[] = {sin(yaw * 1.0f / 64), -cos(yaw * 1.0f / 64)};
			locX += moveVector[1];
			locZ -= moveVector[0];
		}

		glutPostRedisplay();
	}

	if (funcKeyStates[GLUT_KEY_UP])
	{
		if (!mouseLook)
		{
			GLfloat moveVector[] = {sin(rot * 1.0f / 8), cos(rot * 1.0f / 8)};
			locZ -= moveVector[1];
			locX -= moveVector[0];
		}
		else
		{
			GLfloat moveVector[] = {sin(yaw * 1.0f / 64), -cos(yaw * 1.0f / 64), sin(pitch * 1.0f / 64)};
			locX -= moveVector[0];
			locZ -= moveVector[1];
			locY -= moveVector[2];
		}
		glutPostRedisplay();
	}
	else if (funcKeyStates[GLUT_KEY_DOWN])
	{
		if (!mouseLook)
		{
			GLfloat moveVector[] = {sin(rot * 1.0f / 8), cos(rot * 1.0f / 8)};
			locZ += moveVector[1];
			locX += moveVector[0];
		}
		else
		{
			
			GLfloat moveVector[] = {sin(yaw * 1.0f / 64), -cos(yaw * 1.0f / 64), sin(pitch * 1.0f / 64)};
			locX += moveVector[0];
			locZ += moveVector[1];
			locY += moveVector[2];
		}
		glutPostRedisplay();
	}
	

	if (funcKeyStates[GLUT_KEY_PAGE_UP])
	{
		if (!mouseLook)
		{
			rot++;
			glutPostRedisplay();
		}
	}
	else if (funcKeyStates[GLUT_KEY_PAGE_DOWN])
	{
		if (!mouseLook)
		{
			rot--;
			glutPostRedisplay();
		}
	}
	else if (funcKeyStates[GLUT_KEY_END])
	{
		rot = 0;
	}
}

void keyOperations()
{	
	if (keyModifier == GLUT_ACTIVE_ALT && keyStates[13])
	{
		isInFullScreenMode = !isInFullScreenMode;

		if (isInFullScreenMode)
		{
			oldWidth = width;
			oldHeight = height;
			winPosX = glutGet(GLUT_WINDOW_X);
			winPosY = glutGet(GLUT_WINDOW_Y);
			glutFullScreen();
		}
		else
		{
			glutPositionWindow(winPosX, winPosY);
			glutReshapeWindow(oldWidth, oldHeight);
		}
	}

	if (keyStates[99]) //c
	{
		mouseLook = !mouseLook;
		fovy = DEFAULT_FOVY;
		calculate45DegreesForLocY();
		denom = 4.0f;
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
    }
  
    if (keyStates[121]) //y
	{ 
        robot.changeMiddle();
    }

      
    if (keyStates[117]) //u
	{ 
        robot.changeBottom();
    }
    
	if (keyStates[45]) //-
	{
		if (denom != 4.0f && !mouseLook)
		{
			fovy++;
			denom -= 0.25f;
			locY = currentRadius * tan(GL_PI / denom);
			glutPostRedisplay();
		}
	}
	else if (keyStates[61] && !mouseLook) //=
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
		fovy = DEFAULT_FOVY;
		calculate45DegreesForLocY();
		denom = 4.0f;
	}	
	else if (keyStates['d']) 
	{
		isDebugMode = !isDebugMode;
		if (isDebugMode) {
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			TwDefine(" Debugging visible=true "); 
		} else {
			glutSetCursor(GLUT_CURSOR_NONE);
			TwDefine(" Debugging visible=false "); 
		}
		
	}

	if (keyStates[27]) { //escape
		TwTerminate();
		exit(0);
	}
		
	memset(keyStates, 0, sizeof(keyStates));
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

	if (isDebugMode) {
		TwDraw();
	}

	glutSwapBuffers();
    glutPostRedisplay();
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
	keyModifier = NULL;
	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = false;

	glutPostRedisplay();
}

void keyboardKeys(unsigned char key, int x, int y)
{
	keyStates[key] = true;
	keyModifier = glutGetModifiers();
	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = true;

	glutPostRedisplay();
}

void OnKey(unsigned char key, int x, int y)  {
	TwEventKeyboardGLUT(key, x, y);		
	keyboardKeys(key, x, y);	
}



void init()
{
	glEnable(GL_DEPTH_TEST);
	wireframeView = false;
	birdSightView = false;
	mouseLook = false;
	isInFullScreenMode = false;

	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
		funcKeyStates[i] = false;
	}

	calculate45DegreesForLocY();
}


void passiveMotionFunc(int x, int y)
{
	int diffX, diffY;

	diffX = x - CENTER_X;
	diffY = y - CENTER_Y;

	if (diffX != 0 || diffY != 0)
	{
		if (!isDebugMode) {
			//SetCursorPos(CENTER_X + glutGet(GLUT_WINDOW_X), CENTER_Y + glutGet(GLUT_WINDOW_Y));
			glutWarpPointer(CENTER_X, CENTER_Y);
		}

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
       
    TwInit(TW_OPENGL, NULL);	


	//callbacks	
	glutReshapeFunc(reshapeMainWindow);
	glutSpecialFunc(functionKeys);	
	glutKeyboardUpFunc(keyUp);
	glutSpecialUpFunc(functionKeyUp);
	glutDisplayFunc(render);

	
    TwBar *myBar;
    myBar = TwNewBar("Debugging");	
	TwWindowSize(width, height);

	//Camera
	TwAddVarRW(myBar, "Radius", TW_TYPE_FLOAT, &currentRadius, " group=Camera");	
	TwAddVarRW(myBar, "(M)ouseLook", TW_TYPE_BOOLCPP, &mouseLook, "group=Camera true=Yes false=No key=m");	
	//Location
	TwAddVarRW(myBar, "Location (X)", TW_TYPE_FLOAT, &locX, " group=Location step=1 keyIncr=x keyDecr=X");
	TwAddVarRW(myBar, "Location (Y)", TW_TYPE_FLOAT, &locY, " group=Location step=1 keyIncr=y keyDecr=Y");
	TwAddVarRW(myBar, "Location (Z)", TW_TYPE_FLOAT, &locZ, " group=Location step=1 keyIncr=z keyDecr=Z");
	//Rotation
	TwAddVarRW(myBar, "(R)otation", TW_TYPE_INT32, &rot, " group=Rotation step=1 keyIncr=r keyDecr=R min=0 max=360");
	TwAddVarRW(myBar, "Yaw", TW_TYPE_FLOAT, &yaw, " group=Rotation");
	TwAddVarRW(myBar, "Pitch", TW_TYPE_FLOAT, &pitch, " group=Rotation");
    
	TwAddVarRW(myBar, "Color", TW_TYPE_COLOR3F, &color, "");
	
	
	TwDefine(" Debugging/Location group=Camera \n Debugging/Rotation group=Camera ");

    glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
    glutKeyboardFunc((GLUTkeyboardfun)OnKey);	
    

	//mouse motion
	glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	
	init();

	glutMainLoop();

	return 0;
}
