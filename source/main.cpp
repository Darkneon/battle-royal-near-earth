#include <math.h>
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
        
#include "Game.h"
#include "SpotLight.h"
#include "Light/LightPost.h"
#include "Model/Texture/TextureManager.h"
#include "Buildings/FlagModel.h"

#include "AntTweakHelper.h"
#include "SoundHelper.h"
#include "EnvMap.h"

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
bool showHelpWindow = false;
bool wasPreviouslyPressed = false;
// Bounds of viewing frustum.
GLfloat nearPlane =  1.0f;
GLfloat farPlane  = 100.0f;

bool keyStates[256];
bool funcKeyStates[256];
int keyModifier = 0;
TextureManager *te;

static bool isDebugMode = false;

bool isGameOver = false;
bool isTwoPlayerGame = false;

int viewStates = 0; //states of the camera views

Game* game;
AntTweakHelper antTweakHelper;

//second window for help menu
int mainWindow = 0;
bool beginMenu = true;
bool mapChoice = false;
bool startGame = false;

FlagModel flag;

        
GLfloat buttonW1;
GLfloat	buttonW2;
GLfloat button1H1;
GLfloat button1H2;

GLfloat button2H1;
GLfloat button2H2;

string loadMap;

EnvMap envMap;
int envMapView = 0;

void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	TwWindowSize(width, height);
}

void toggleTwoPlayerSplitscreen()
{
	isTwoPlayerGame = !isTwoPlayerGame;

	if (isTwoPlayerGame)
	{
		game->p1->controlRobotAt(0);
		game->p2->controlRobotAt(0);
		game->twoPlayerIsOn = true;
	}
	else
	{
		game->p1->changeCamera(CAMERA_COMMANDER);
		game->p2->changeCamera(CAMERA_COMMANDER);
		game->twoPlayerIsOn = false;
	}
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

//function to draw the help menu
void help_display(){
    glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//creating ortho view since text is only 2D
		glOrtho(0, width-5, 0, height-5, 0.0, 0.1);
		glMatrixMode(GL_MODELVIEW);
		glDisable(GL_LIGHTING);

		int lineSpace = 15;
		int lineHeight = height-20;
		
		ifstream openfile;
		string fileLoad = "keyInput.txt";
		openfile.open((TextureManager::getResourcePath() + fileLoad).c_str(), ios::in);
		glColor3f(1.0f, 1.0f, 1.0f);
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
		
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
		glBegin(GL_QUADS);
			glVertex2f(0.0f, 0.0f);
			glVertex2f((GLfloat)width, 0.0f);
			glVertex2f((GLfloat)width, (GLfloat)height);
			glVertex2f(0.0f, (GLfloat)height);
		glEnd();

		glEnable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

//render the menu at the beginning of the game
void renderMenu(){
    glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//creating ortho view since text is only 2D
		glOrtho(0, width, 0, height, 0.0, 0.1);
		glMatrixMode(GL_MODELVIEW);
		glDisable(GL_LIGHTING);

		
		glColor3f(1.0f, 1.0f, 1.0f);
		string s = "Open Robot Battle Near Earth";
		rasterText((GLfloat)width/2-110,(GLfloat)height-40,GLUT_BITMAP_HELVETICA_18, (char *)s.c_str(), s.size());

		if(!mapChoice){
			s = "Please choose one of the following modes:";
		}else{
			s = "Please choose one of the following maps:";
		}
		rasterText((GLfloat)width/2-105,(GLfloat)height-140,GLUT_BITMAP_HELVETICA_12, (char *)s.c_str(), s.size());

		GLfloat size;
		if(!mapChoice){
			s = "Classic Nether Earth";
			size = (GLfloat)width/2-80;
		}else{
			s = "Map1";
			size = (GLfloat)width/2-20;
		}
		rasterText(size,(GLfloat)height-220,GLUT_BITMAP_HELVETICA_18, (char *)s.c_str(), s.size());

		if(!mapChoice){
			s = "DeathMatch";
			size = (GLfloat)width/2-50;
		}else{
			s = "Map2";
			size = (GLfloat)width/2-20;
		}
		rasterText(size,(GLfloat)height-300,GLUT_BITMAP_HELVETICA_18, (char *)s.c_str(), s.size());

		buttonW1 = (GLfloat)width/2-95;
		buttonW2 = (GLfloat)width/2+105;
		button1H1 = (GLfloat)height-230;
		button1H2 = (GLfloat)height-195;

		button2H1 = (GLfloat)height-310;
		button2H2 = (GLfloat)height-275;

		glBegin(GL_QUADS);
			glColor3f(0.0f, 0.5f, 0.0f);
			glVertex2f(buttonW1, button1H1);
			glVertex2f(buttonW2, button1H1);
			glVertex2f(buttonW2, button1H2);
			glVertex2f(buttonW1, button1H2);

			glVertex2f(buttonW1, button2H1);
			glVertex2f(buttonW2, button2H1);
			glVertex2f(buttonW2, button2H2);
			glVertex2f(buttonW1, button2H2);

			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(0.0f, 0.0f);
			glVertex2f((GLfloat)width, 0.0f);
			glVertex2f((GLfloat)width, (GLfloat)height);
			glVertex2f(0.0f, (GLfloat)height);
		glEnd();

		glEnable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}


//render the game itself
void renderGame(){
	static time_t lastUpdate = time(NULL);
	static time_t currentTime = time(NULL);
	static GLuint fps = 0;
	static GLuint prevFps = 0;


	if(isGameOver)
	{
		game->p1->changeCamera(CAMERA_CIRCULAR);
		glutPostRedisplay();
	}
			
	
	if (isTwoPlayerGame && !isGameOver)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		game->p1->view();
		glViewport(0, (GLint)height / 2, (GLsizei)width, (GLsizei)height / 2);
        game->render();

		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		game->p2->view();
		glViewport(0, 0, (GLsizei)width, (GLsizei)height / 2);
        game->render();

	}
	else
	{		
        
        if (envMapView > 0 ) { 
            envMap.RegenerateEnvMap(game->lr, 
                                    game->p1->getUFO()->pos[0], 
                                    game->p1->getUFO()->pos[2]);
        }
        
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		game->p1->view();
        glViewport(0, 0, (GLsizei)width, (GLsizei)height);
     
        if (envMapView == 0) {
            game->p1->setEnvMap(false);
            game->render();
            
        }
        else if (envMapView == 1) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            game->p1->setEnvMap(true);   
            game->render();
        }
        else {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            envMap.tex();
        }
        
        glPushMatrix();
            glTranslatef(25.0f, 2.0f, 10.0f);
            flag.render();
        glPopMatrix();
        
	}	

	game->getInput(keyModifier); // Gets user input
	
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
	
    stringstream sFps;
    sFps << prevFps;    	
    
	string prefixAndFps = "FPS: " + sFps.str();
    
	 glPushMatrix();        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, 0, height, 0.0f, 0.1f);

        glMatrixMode(GL_MODELVIEW); 
        glDisable(GL_LIGHTING);

        glColor3f(1.0f, 1.0f, 1.0f);
        rasterText(20.0f, 20.0f, GLUT_BITMAP_HELVETICA_18, (char *)prefixAndFps.c_str(), prefixAndFps.size());
        
		if (isTwoPlayerGame)
		{
			stringstream score1;
			stringstream score2;

			score1 << game->player1Score;
			score2 << game->player2Score;
			string stringScore1 = "Player 1: " + score1.str();
			string stringScore2 = "Player 2: " + score2.str();

			glColor3f(1.0f, 0.0f, 0.0f);
			rasterText( width / 3.0f, 20.0f, GLUT_BITMAP_HELVETICA_18, (char *)stringScore1.c_str(), stringScore1.size());
			glColor3f(0.0f, 0.0f, 1.0f);
			rasterText( 2 * width / 3.0f, 20.0f, GLUT_BITMAP_HELVETICA_18, (char *)stringScore2.c_str(), stringScore2.size());
		}

        glEnable(GL_LIGHTING);
        
        glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, (float)width / height, 1, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
        
    glPopMatrix();
}


void render()
{
	//clears the buffer
        //glClearStencil(0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        
        
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    //showing the help menu if needed
	if(showHelpWindow){
		help_display();
	}

	//showing the menu at the beginning of the game
	if(beginMenu){
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		renderMenu();
     
	}else{
		if(startGame){
			glutSetCursor(GLUT_CURSOR_NONE);
			game->setMap(loadMap);
			BoundingBox::showBoxes = false;
			TextureManager::getInstance()->toggleTextures();
			antTweakHelper.bindLevelRenderer(game->lr);
			
			startGame = false;
		}
        
		game->update(&isGameOver);
		//rendering the game itself
		renderGame();
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
	glPolygonMode(GL_FRONT, GL_FILL);

	if (game->lr->getIsSkySphere())
		glPolygonMode(GL_BACK, GL_FILL);

	if(viewStates==1){ //wireFrame
		glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT, GL_LINE);

		if (game->lr->getIsSkySphere())
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	else if(viewStates==2){ //smoothShading
		glShadeModel(GL_SMOOTH);

		glPolygonMode(GL_FRONT, GL_FILL);

		if (game->lr->getIsSkySphere())
			glPolygonMode(GL_BACK, GL_FILL);
	}

	else{//back to normal
		viewStates=0;
	}
}

void windowFuncKeyOps(){
	if (funcKeyStates[GLUT_KEY_F1]) {
		toggleDifferentView();
    } 
    else if (funcKeyStates[GLUT_KEY_F6]) {
        TextureManager::getInstance()->toggleSkins();
    }

	if (funcKeyStates[GLUT_KEY_F8])
		toggleTwoPlayerSplitscreen();
}

void functionKeysPressed(int key, int x, int y)
{
	funcKeyStates[key] = true;
	windowFuncKeyOps();
}

void windowKeyOps()
{
	if (keyModifier == GLUT_ACTIVE_ALT && keyStates[13]) //alt + enter
		toggleFullScreen();
	
	if (keyStates[98]) //b
	{
		isDebugMode = !isDebugMode;
		if (isDebugMode)
			glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
		else
			glutSetCursor(GLUT_CURSOR_NONE);
	} 

	if(keyStates[104]){//h
		showHelpWindow = !showHelpWindow;
	}

	
	if (keyStates['z'])
	{
		game->lr->toggleSkySphere();
	}

	if (keyStates['5'])
	{
		game->lr->toggleLights(1);
	}

	if (keyStates['6'])
	{
		game->lr->toggleLights(2);
	}

	if (keyStates['7'])
	{
		game->lr->toggleLights(3);
	}

	if (keyStates['8'])
	{
		game->lr->toggleLights(4);
	}

	if (keyStates['9'])
	{
		game->lr->toggleLights(5);
	}

	if (keyStates['p'])
	{
		game->lr->toggleLights(6);
	}
    
    if (keyStates['k'])
	{
        envMapView += 1;
        if (envMapView > 2) {
            envMapView = 0;
        }
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
	//wasPreviouslyPressed = false;
}

void keyboardKeysPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;
	keyModifier = glutGetModifiers();

	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = true;

	windowKeyOps();
	//wasPreviouslyPressed = true;
}

void onKey(unsigned char key, int x, int y)  {
	TwEventKeyboardGLUT(key, x, y);		
	keyboardKeysPressed(key, x, y);
}

void initAntTweak() {
 // antTweakHelper.bindCamera(game->p1->getCurrentCamera());
 // antTweakHelper.bindLevelRenderer(game->lr);
}


void init()
{
	glGenLists(10);
	
	//toggleFullScreen();

	te = TextureManager::getInstance();
	srand ( (unsigned int)time(NULL) );

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

    envMap.init();


        
//	initGameMusic();
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

void joystickFunc(unsigned int button, int xaxis, int yaxis, int zaxis)
{
	game->playerInput2->joystickOperations(button, xaxis, yaxis, zaxis);
}



void onMouseFunc(int button, int state, int x, int y)
{
	TwEventMouseButtonGLUT(button, state, x, y);
	game->playerInput1->mouseButtons(button, state);
	game->playerInput1->mousePassiveOperations(x, y);

	if(beginMenu){
		y = (int)height - y; 
		//check if clicked button1
		if (button == 0 && state == 0 && x>buttonW1 && x<buttonW2 && y>button1H1 && y<button1H2){
			if(mapChoice){
				loadMap = "map1.txt";
				beginMenu = false;
				startGame = true;
			}else{
				mapChoice = !mapChoice;
			}
		}
		//check if clicked button2
		else if (button == 0 && state == 0 && x>buttonW1 && x<buttonW2 && y>button2H1 && y<button2H2){
		    if(mapChoice){
				loadMap = "map2.txt";
			}else{
				loadMap = "dm-vinelynth.txt";
                SoundHelper::getInstance()->play("deathmatch.wav", 0, true);
				toggleTwoPlayerSplitscreen();
			}
			beginMenu = false;
			startGame = true;
		}
	}
}


int main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(width, height);
	mainWindow = glutCreateWindow("Battle Royale Near Earth");
       
	//callbacks	
	glutReshapeFunc(reshapeMainWindow);
	glutSpecialFunc(functionKeysPressed);
	glutSpecialUpFunc(functionKeyUp);
	glutKeyboardFunc(keyboardKeysPressed);
	glutKeyboardUpFunc(keyboardKeysUp);
	glutDisplayFunc(render);

    // Initialize stencilling.
    glClearStencil(0);
        glClear(GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_STENCIL_TEST);
        
	//mouse motion
	glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
	glutJoystickFunc(joystickFunc, 5);

	glutMouseFunc((GLUTmousebuttonfun)onMouseFunc);
	glutKeyboardFunc((GLUTkeyboardfun)onKey);	
    
	init();
    
    SoundHelper::getInstance()->play("menu.wav", true);
	glutMainLoop();
	return 0;
}
