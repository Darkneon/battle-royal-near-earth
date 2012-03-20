#include <math.h>
#include <fstream>
#include <string>
#include <time.h>

#include "Game.h"
#include "LevelRenderer.h"
#include "Base.h"
#include "Robot.h"
#include "SpotLight.h"
#include "Light/LightPost.h"
#include "Model/Texture/TextureManager.h"
#include "Model/Skybox/CubicSkybox.h"
#include "Model/Skybox/SphericSkybox.h"

#include "AntTweakHelper.h"

#ifdef __APPLE__
    #include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif


// PI
#define GL_PI 3.14159f

// Current size of window.
GLint width  = 700;
GLint height = 500;

//	old values for the window (used to come back from fullscreen)
GLint oldWidth = width;
GLint oldHeight = height;

// Current position of the window (used to come back from fullscreen)
int winPosX = 0;
int winPosY = 0;

bool isInFullScreenMode;

bool isSphereSkyBox = false;

// Bounds of viewing frustum.
GLfloat nearPlane =  1.0f;
GLfloat farPlane  = 100.0f;

bool keyStates[256];
bool funcKeyStates[256];
int keyModifier = 0;
TextureManager *te;

static bool isDebugMode = false;

int viewStates = 0; //states of the camera views

Game* game;
LevelRenderer* levelRenderer;
Base base;
Robot robot;
Robot robot2;

CubicSkybox *cubicSkyBox;
SphericSkybox *sphericSkyBox;

bool toggleRobot = false;
AntTweakHelper antTweakHelper;
//GLUquadricObj *quadratic = gluNewQuadric();

//Initialize light objects
SpotLight *spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);
LightPost *light1 = new LightPost(0.0f, 6.0f, 0.0f, 2.5f, -2.5f, 2.5f);
LightPost *light2 = new LightPost(50.0f, 6.0f, 0.0f, -2.5f, -2.5f, 2.5f);
LightPost *light3 = new LightPost(50.0f, 6.0f, 50.0f, -2.5f, -2.5f, -2.5f);
LightPost *light4 = new LightPost(0.0f, 6.0f, 50.0f, 2.5f, -2.5f, -2.5f);

bool ambientLight = true;
bool showHelpWindow = false;
bool spotLight1 = true;
bool spotLight2 = true;
bool spotLight3 = true;
bool spotLight4 = true;

//second window for help menu
int mainWindow = 0;
int helpWindow = 0;

void renderLights()
{		
		//ambient light
		GLfloat ambient_light[4];

		if(ambientLight){
			for(int i = 0; i<3;i++){
				ambient_light[i] = 0.45f;
			}
		}else{
			for(int i = 0; i<3;i++){
				ambient_light[i] = 0.2f;
			}
		}
		ambient_light[3]=1.0f;
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);// Allows color to reflect light
		//Set up a new light, namely... light0
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
        //For enabling / disabling lights
        if(!spotLight1)
        {
                glDisable(GL_LIGHT1);
	} else {
            glEnable(GL_LIGHT1);
        }
        if(!spotLight2)
        {
                glDisable(GL_LIGHT2);
	} else {
            glEnable(GL_LIGHT2);
        }
        if(!spotLight3)
        {
                glDisable(GL_LIGHT3);
	} else {
            glEnable(GL_LIGHT3);
        }
        if(!spotLight4)
        {
                glDisable(GL_LIGHT4);
	} else {
            glEnable(GL_LIGHT4);
        }
        light1->render();
        light2->render();
        light3->render();
        light4->render();
        
}

void reshapeMainWindow (int newWidth, int newHeight)
{
	glutSetWindow(mainWindow);
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	TwWindowSize(width, height);

	glutSetWindow(helpWindow);
	glutPositionWindow(10,10);
	glutReshapeWindow(width-5,height-5);
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
		
	//memset(keyStates, 0, sizeof(keyStates));
}

void rasterText(GLfloat x, GLfloat y, void *font, char *c, int cWidth){

	glDisable(GL_TEXTURE_2D);
	
	glPushMatrix();
		glLoadIdentity();	
		glRasterPos2f(x, y);

		for (int i = 0; i < cWidth; i++)
		{
			glutBitmapCharacter(font, c[i]);
		}

	glPopMatrix();
}

void render()
{
	
	static time_t lastUpdate = time(NULL);
	static time_t currentTime = time(NULL);
	static GLuint fps = 0;
	static GLuint prevFps = 0;

	glutSetWindow(mainWindow);
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	levelRenderer->render();
	renderLights();

	//Drawing robot models on map
	glPushMatrix();
		glTranslatef(15,0,40);
		//base.draw();
        glTranslatef(-5,0,5);
        game->p1->draw();
	glPopMatrix();
	
	glPushMatrix();
		//robot.translateTo(25.0f,45.0f);
		//robot.draw();
	glPopMatrix();

	glPushMatrix();
		//robot2.translateTo(30.0f,45.0f);
		//robot2.draw();
	glPopMatrix();

	if (!isSphereSkyBox)
		cubicSkyBox->render();
	else
		sphericSkyBox->render();
	
	
	game->getInput(keyModifier); // Gets user input
	game->p1->view(); // Camera update (leave as it is for now)

	if (isDebugMode) {
		antTweakHelper.draw();
	}

	
	fps++;
	currentTime = time(NULL);
	
	if ((currentTime - lastUpdate) >= 1.0f)
	{
		lastUpdate = currentTime;

		prevFps = fps;
		fps = 0;
	}
	
	char *sFps = new char[4];
	_itoa_s(prevFps, sFps, 4, 10);

	char *sFpsPrefix = "FPS: ";

	char *prefixAndFps;
	int len = strlen(sFps) + 1 + strlen(sFpsPrefix);

	prefixAndFps = (char*)malloc(len);

	strcpy_s(prefixAndFps, sizeof(char) * len, sFpsPrefix);
	strcat_s(prefixAndFps, sizeof(char) * len, sFps);
	
	glColor3f(1.0f, 1.0f, 1.0f);
	rasterText(-1.0f, 0.8f, GLUT_BITMAP_HELVETICA_18, prefixAndFps, 10);

	delete [] prefixAndFps;
	delete [] sFps;

	glutSwapBuffers();
    glutPostRedisplay();
}


void help_display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
		glLoadIdentity();
		//creating ortho view since text is only 2D
		glOrtho(0, width-5, 0, height-5, 0.0, 0.1);
		glMatrixMode(GL_MODELVIEW);

		int lineSpace = 15;
		int lineHeight = height-20;
		
		ifstream openfile;
		string fileLoad = "keyInput.txt";
		openfile.open((TextureManager::getResourcePath() + fileLoad).c_str(), ios::in);
		if (openfile.is_open()) {
			string s;
			getline(openfile, s);
			char *title = (char*)s.c_str();
			rasterText((GLfloat)width/2-35,(GLfloat)lineHeight,GLUT_BITMAP_HELVETICA_12, title,s.size());
			lineHeight -= 5;

			while(!openfile.eof())
			{
				getline(openfile, s);
				char *readLine = (char*)s.c_str();
				lineHeight -= lineSpace;
				rasterText(15.0f,(GLfloat)lineHeight,GLUT_BITMAP_HELVETICA_10, readLine,s.size());
			}
			openfile.close();
		}

		glMatrixMode(GL_PROJECTION);
    glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
     
    glutSwapBuffers();
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
	glPolygonMode(GL_FRONT, GL_FILL);

	if (isSphereSkyBox)
		glPolygonMode(GL_BACK, GL_FILL);

	if(viewStates==1){ //wireFrame
		glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT, GL_LINE);

		if (isSphereSkyBox)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	else if(viewStates==2){ //smoothShading
		glShadeModel(GL_SMOOTH);

		glPolygonMode(GL_FRONT, GL_FILL);

		if (isSphereSkyBox)
			glPolygonMode(GL_BACK, GL_FILL);
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
		if(!toggleRobot){
			game->p1->selectRobot(&robot);
			toggleRobot = true;
		}
		else {
			game->p1->selectRobot(&robot2);
			toggleRobot = false;
		}
		//glutPostRedisplay();
    }
  
    if (keyStates[121]) //y
	{ 
		if(toggleRobot){
			robot.cycleIndex();
			glutPostRedisplay();
		}
		else {
			robot2.cycleIndex();
			glutPostRedisplay();
		}
    }
      
    if (keyStates[117]) //u
	{ 
		if(toggleRobot){
			robot.turnSelectedOn();
			glutPostRedisplay();
		}
		else{
			robot2.turnSelectedOn();
			glutPostRedisplay();
		}
    }

	if (keyStates[98]) //b
	{
		isDebugMode = !isDebugMode;
		if (isDebugMode)
			glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
		else
			glutSetCursor(GLUT_CURSOR_NONE);
	}

	if(keyStates[97]){ //a
		ambientLight = !ambientLight;
	}
        if(keyStates[53]) //5
    {
        spotLight1 = !spotLight1;
    }
        if(keyStates[54]) // 6
    {
        spotLight2 = !spotLight2;
    }    
        if(keyStates[55]) // 7
    {
        spotLight3 = !spotLight3;
    }
         if(keyStates[56]) // 8
    {
        spotLight4 = !spotLight4;
    }
         if(keyStates[57]) // 9
    {
        spotLight1 = false;
        spotLight2 = false;
        spotLight3 = false;
        spotLight4 = false;
    }
        

	if(keyStates[104]){//h
		showHelpWindow = !showHelpWindow;
		if(showHelpWindow){
			glutSetWindow(helpWindow); 
			glutShowWindow();
			glutSetWindow(mainWindow);
		}else{
			glutSetWindow(helpWindow); 
			glutHideWindow();
			glutSetWindow(mainWindow);
		}
	}

	if (keyStates[115])//s
	{
		isSphereSkyBox = !isSphereSkyBox;
	}

	if (keyStates[27]) //ESC
	{
		if (game != NULL)
		{
			delete game;
		}
		exit(0);
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

	//glutPostRedisplay();
}

void OnKey(unsigned char key, int x, int y)  {
	TwEventKeyboardGLUT(key, x, y);		
	keyboardKeysPressed(key, x, y);	
}

void initAntTweak() {
  antTweakHelper.bindCamera(game->p1->getCurrentCamera());
  antTweakHelper.bindLightPosts(light1, light2, light3, light4);
}

void init()
{
	glGenLists(5);

	te = TextureManager::getInstance();

	levelRenderer = new LevelRenderer();
	cubicSkyBox = new CubicSkybox();
	sphericSkyBox = new SphericSkybox();

	
	game = new Game(width, height, nearPlane, farPlane, keyStates, funcKeyStates);
	glEnable(GL_DEPTH_TEST);
	isInFullScreenMode = false;

	glCullFace( GL_BACK );
	glEnable( GL_CULL_FACE );
	
	for (int i = 0; i < 256; i++)
	{
		keyStates[i] = false;
		funcKeyStates[i] = false;
	}

	glutSetCursor(GLUT_CURSOR_NONE);
	
  initAntTweak();
  glEnable(GL_NORMALIZE);
  
  
}

//mouse movement functions, primarily used to modify the view
void passiveMotionFunc(int x, int y)
{
	game->playerInput1->mousePassiveOperations(x, y);
}

void motionFunc(int x, int y)
{
	game->playerInput1->mousePassiveOperations(x, y);
}

int main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	mainWindow = glutCreateWindow("Battle Royale Near Earth");
       
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
	glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	init();

	//helpWindow
	helpWindow = glutCreateSubWindow(mainWindow, 10, 10,width-5,height-5);
	glutDisplayFunc(help_display);

	//hiding the subwindow for now
	glutSetWindow(helpWindow); 
	glutHideWindow();
	glutSetWindow(mainWindow);

	glutMainLoop();
	return 0;
}
