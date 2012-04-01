#include <math.h>
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
        
#include "Game.h"
#include "SpotLight.h"
#include "Light/LightPost.h"
#include "Model/Texture/TextureManager.h"

#include "AntTweakHelper.h"
#include "SoundHelper.h"

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

// Bounds of viewing frustum.
GLfloat nearPlane =  1.0f;
GLfloat farPlane  = 100.0f;

bool keyStates[256];
bool funcKeyStates[256];
int keyModifier = 0;
TextureManager *te;

static bool isDebugMode = false;

bool isTwoPlayerGame = false;

int viewStates = 0; //states of the camera views

Game* game;
AntTweakHelper antTweakHelper;
SoundHelper soundHelper;

//second window for help menu
int mainWindow = 0;

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
	}
	else
	{
		game->p1->changeCamera(CAMERA_COMMANDER);
		game->p2->changeCamera(CAMERA_COMMANDER);
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

void render()
{
	static time_t lastUpdate = time(NULL);
	static time_t currentTime = time(NULL);
	static GLuint fps = 0;
	static GLuint prevFps = 0;

	//clears the buffer
        //glClearStencil(0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        
        
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

                
        
	if(showHelpWindow){
		help_display();
	}

	if (isTwoPlayerGame)
	{
		game->p1->view();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		game->render();
		glViewport(0, 0, (GLsizei)width, (GLsizei)height / 2);
	
		game->p2->view();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		game->render();
		glViewport(0, (GLint)height / 2, (GLsizei)width, (GLsizei)height / 2);
	}
	else
	{
		game->render();
		game->p1->view();
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	}	

	game->getInput(keyModifier); // Gets user input
	//((HumanPlayer*)(game->p1))->view(); // Camera update (leave as it is for now)
	
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
    glPopMatrix();
    
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
}

void keyboardKeysPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;
	keyModifier = glutGetModifiers();

	//Checks for uppercase
	if (key >= 65 && key <= 90)
		keyStates[key + 32] = true;

	windowKeyOps();
}

void onKey(unsigned char key, int x, int y)  {
	TwEventKeyboardGLUT(key, x, y);		
	keyboardKeysPressed(key, x, y);	
}

void initAntTweak() {
 // antTweakHelper.bindCamera(game->p1->getCurrentCamera());
    antTweakHelper.bindLevelRenderer(game->lr);
}

//http://sites.google.com/site/sdlgamer/beginner/lesson-12
/*void initGameMusic()
{
	// Inilialize SDL_mixer , exit if fail
	if( SDL_Init(SDL_INIT_AUDIO) < 0 ) exit(1);
	// Setup audio mode
	Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);
	Mix_Music *mus; // *mus2 ;  // Background Music
	//Mix_Chunk *wav , *wav2 ;  // For Sounds
	string track01 = "music/Darkness.mid";
	mus = Mix_LoadMUS((TextureManager::getResourcePath() + track01).c_str());
	Mix_PlayMusic(mus,1); //Music loop=1
}*/

void init()
{
	glGenLists(7);

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

        
        
        
	TextureManager::getInstance()->toggleTextures();
	BoundingBox::showBoxes = !BoundingBox::showBoxes;

        
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
    soundHelper.loadWav(TextureManager::getInstance()->getResourcePath() + "music/caja2.wav");
    soundHelper.play();
    
	glutMainLoop();
	return 0;
}
