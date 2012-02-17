#include "Game.h"
#include "LevelRenderer.h"
#include "Base.h"
#include "Robot.h"

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
GLint width  = 600;
GLint height = 400;

//	old values for the window (used to come back from fullscreen)
GLint oldWidth = width;
GLint oldHeight = height;

// Current position of the window (used to come back from fullscreen)
int winPosX = 0;
int winPosY = 0;

bool isInFullScreenMode;

// Bounds of viewing frustum.
GLfloat nearPlane =  1.0f;
GLfloat farPlane  = 100.0f;

bool keyStates[256];
bool funcKeyStates[256];
int keyModifier = 0;

Game* game;
LevelRenderer levelRenderer;
Base base;
Robot robot;

// Respond to window resizing, preserving proportions.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	TwWindowSize(width, height);
}

void toggleFullScreen()
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

void render()
{
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	levelRenderer.render();
	//Drawing robot models on map
	glPushMatrix();
		glTranslatef(15,0,40);
		game->p1->draw();
		glTranslatef(1,0,0);
		base.draw();
		glTranslatef(7,0,5);	
		robot.draw();
	glPopMatrix();

	game->p1->view(); // Camera update (leave as it is for now)
	game->getInput(keyModifier); // Gets user input

//	if (isDebugMode) {
//		TwDraw();
//	}

	glutSwapBuffers();
    glutPostRedisplay();
}


void functionKeyUp(int key, int x, int y)
{
	funcKeyStates[key] = false;
	glutPostRedisplay();
}

void functionKeysPressed(int key, int x, int y)
{
	funcKeyStates[key] = true;
	glutPostRedisplay();
}


void windowKeyOps()
{
	if (keyModifier == GLUT_ACTIVE_ALT && keyStates[13]) //alt + enter
	{
		toggleFullScreen();
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

}



void keyboardKeysUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
	keyModifier = NULL;

	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = false;

	glutPostRedisplay();
}

void keyboardKeysPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;
	keyModifier = glutGetModifiers();

	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = true;

	windowKeyOps();

	glutPostRedisplay();
}

void OnKey(unsigned char key, int x, int y)  {
	TwEventKeyboardGLUT(key, x, y);		
//	keyboardKeys(key, x, y);	
}

void init()
{
	game = new Game(width, height, nearPlane, farPlane, keyStates, funcKeyStates);
	glEnable(GL_DEPTH_TEST);
	isInFullScreenMode = false;

	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
		funcKeyStates[i] = false;
	}

	glutSetCursor(GLUT_CURSOR_NONE);
}


void passiveMotionFunc(int x, int y)
{
	game->playerInput1->mousePassiveOperations(x, y);
}


//void motionFunc(int x, int y){}


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
	glutSpecialFunc(functionKeysPressed);
	glutSpecialUpFunc(functionKeyUp);
	glutKeyboardFunc(keyboardKeysPressed);
	glutKeyboardUpFunc(keyboardKeysUp);
	glutDisplayFunc(render);

	
    TwBar *myBar;
    myBar = TwNewBar("Debugging");	
	TwWindowSize(width, height);
    TwDefine(" Debugging size='250 500' alpha=150 ");
    
	/*
	//Camera
	TwAddVarRW(myBar, "Radius", TW_TYPE_FLOAT, &currentRadius, " group=Camera");	
	TwAddVarRW(myBar, "MouseLook (C)", TW_TYPE_BOOLCPP, &mouseLook, "group=Camera true=Yes false=No key=c key=C");	
	//Location
	TwAddVarRW(myBar, "Location X (B)", TW_TYPE_FLOAT, &locX, " group=Location step=1 keyIncr=b keyDecr=B");
	TwAddVarRW(myBar, "Location Y (N)", TW_TYPE_FLOAT, &locY, " group=Location step=1 keyIncr=n keyDecr=N");
	TwAddVarRW(myBar, "Location Z (M)", TW_TYPE_FLOAT, &locZ, " group=Location step=1 keyIncr=m keyDecr=M");
	//Rotation
	TwAddVarRW(myBar, "(R)otation", TW_TYPE_INT32, &rot, " group=Rotation step=1 keyIncr=r keyDecr=R min=0 max=360");
	TwAddVarRW(myBar, "Yaw", TW_TYPE_FLOAT, &yaw, " group=Rotation");
	TwAddVarRW(myBar, "Pitch", TW_TYPE_FLOAT, &pitch, " group=Rotation");
    
	TwAddVarRW(myBar, "Color", TW_TYPE_COLOR3F, &color, "");
	
	
	TwDefine(" Debugging/Location group=Camera \n Debugging/Rotation group=Camera ");
	*/
    glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
    //glutKeyboardFunc((GLUTkeyboardfun)OnKey);	
    

	//mouse motion
	//glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	
	init();
	glutMainLoop();
	return 0;
}
