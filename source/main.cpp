#include <math.h>
#include "Game.h"
#include "LevelRenderer.h"
#include "Base.h"
#include "Robot.h"
#include "Logic\SpotLight.h"
#include "Model\Light\LightPost.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include "AntTweakHelper.h"
#include <cstring>

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

static bool isDebugMode = true;

int viewStates = 0; //states of the camera views

Game* game;
LevelRenderer levelRenderer;
Base base;
Robot robot;
AntTweakHelper antTweakHelper;

//Initialize light objects
SpotLight *spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);
//LightPost *light0 = new LightPost(locX, 5.0f, locZ-RADIUS, 15.0f, -10.0f, 10.0f);
LightPost *light1 = new LightPost(0.0f, 5.0f, 0.0f, 10.0f, -15.0f, 10.0f);
LightPost *light2 = new LightPost(50.0f, 5.0f, 0.0f, -10.0f, -15.0f, 10.0f);
LightPost *light3 = new LightPost(50.0f, 5.0f, 50.0f, -10.0f, -15.0f, -10.0f);
LightPost *light4 = new LightPost(0.0f, 5.0f, 50.0f, 10.0f, -15.0f, -10.0f);


void renderLights()
{		
		GLfloat ambient_light[ ] = {0.4, 0.4, 0.4, 1.0};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);// Allows color to reflect light

		//Set up a new light, namely... light0
        /*glLightfv(GL_LIGHT0, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT0, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT0, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT0, GL_POSITION, light0->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0->getDirectionArray());*/
        //New light... Light1
        glLightfv(GL_LIGHT1, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT1, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT1, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT1, GL_POSITION, light1->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1->getDirectionArray());
        //New light... Light2
        glLightfv(GL_LIGHT2, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT2, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT2, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT2, GL_POSITION, light2->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2->getDirectionArray());
        //New light... Light3
        glLightfv(GL_LIGHT3, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT3, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT3, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT3, GL_POSITION, light3->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 1);
        glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3->getDirectionArray());
        //New light... Light4
        glLightfv(GL_LIGHT4, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT4, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT4, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT4, GL_POSITION, light4->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4->getDirectionArray());
        //TURN ON LIGHTING
        //glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glEnable(GL_LIGHT2);
        glEnable(GL_LIGHT3);
        glEnable(GL_LIGHT4);
        //Don't need reflection now
        //glMaterialfv(GL_FRONT, GL_SPECULAR, spotLight->getSpecular()); //Applys the reflection
        //glMateriali(GL_FRONT, GL_SHININESS, 20); // Sets up the specular component of lighting
        //light0->render();
        light1->render();
        light2->render();
        light3->render();
        light4->render();
}

/*void lightCamera(LightPost* light)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
    gluLookAt(light->getPosX(),light->getPosY(),light->getPosZ(),light->getLookX()+light->getPosX(), light->getLookY()+light->getPosY(), light->getLookZ()+light->getPosZ(),  0, 1, 0);

}*/

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

	if (keyStates[27]) { //escape
		exit(0);
	}
		
	memset(keyStates, 0, sizeof(keyStates));
}



void render()
{
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        renderLights();
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

	if (isDebugMode) {
		antTweakHelper.draw();
	}

	glutSwapBuffers();
  glutPostRedisplay();
}


void functionKeyUp(int key, int x, int y)
{
	funcKeyStates[key] = false;
	glutPostRedisplay();
}

void toggleDifferentView(){
	++viewStates;

	//normal settings
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_BACK, GL_FILL);
	glPolygonMode(GL_FRONT, GL_FILL);

	if(viewStates==1){ //wireFrame
		glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_BACK, GL_LINE);
		glPolygonMode(GL_FRONT, GL_LINE);
	}

	else if(viewStates==2){ //smoothShading
		glShadeModel(GL_SMOOTH);
	}

	else{//back to normal
		viewStates=0;
	}
}

void windowFuncKeyOps(){
	if (funcKeyStates[GLUT_KEY_F1])
	{
		toggleDifferentView();
	}
}

void functionKeysPressed(int key, int x, int y)
{
	funcKeyStates[key] = true;
	windowFuncKeyOps();
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
	keyModifier = 0;
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
	keyboardKeysPressed(key, x, y);	
}

void initAntTweak() {
  antTweakHelper.bindCamera(game->p1->getCurrentCamera());
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

  initAntTweak();
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
       
	//callbacks	
	glutReshapeFunc(reshapeMainWindow);
	glutSpecialFunc(functionKeysPressed);
	glutSpecialUpFunc(functionKeyUp);
	glutKeyboardFunc(keyboardKeysPressed);
	glutKeyboardUpFunc(keyboardKeysUp);
	glutDisplayFunc(render);

	
  glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
  glutKeyboardFunc((GLUTkeyboardfun)OnKey);	
    

	//mouse motion
	//glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	
	init();
	glutMainLoop();
	return 0;
}
