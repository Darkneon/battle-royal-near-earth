#include <math.h>
#include "GameIncludes.h"
#include "SpotLight.h"
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
static double fovy = 90.0;

//camera rotation
static GLint rot = 0;
//camera location
static const GLfloat RADIUS = 10.0f;
static const GLfloat LOC_Y_INITIAL = RADIUS * tan(GL_PI / 4);
//static const GLfloat LOC_Y_INITIAL = 0;
static GLfloat locX = 0.0f;
static GLfloat locY = LOC_Y_INITIAL;
static GLfloat locZ = RADIUS;

static bool wireframeView;

//demo purposes only   -jon
static int choice = 0;
static int nbOfChoices = 13;
//===================

bool* keyStates = new bool[256];
bool* funcKeyStates = new bool[256];
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
Robot robot;

//Initialize light objects
SpotLight *spotLight = new SpotLight(0.3f, 0.9f, 0.1f, 0.0f);
LightPost *light0 = new LightPost(locX, 5.0f, locZ-RADIUS, 15.0f, -10.0f, 10.0f);
LightPost *light1 = new LightPost(0.0f, 5.0f, 0.0f, 10.0f, -15.0f, 10.0f);
LightPost *light2 = new LightPost(50.0f, 5.0f, 0.0f, -10.0f, -15.0f, 10.0f);
LightPost *light3 = new LightPost(50.0f, 5.0f, 50.0f, -10.0f, -15.0f, -10.0f);
LightPost *light4 = new LightPost(0.0f, 5.0f, 50.0f, 10.0f, -15.0f, -10.0f);


void renderLights()
{
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);// Allows color to reflect light
        //Set up a new light, namely... light0
        glLightfv(GL_LIGHT0, GL_AMBIENT, spotLight->getAmbient()); //Setup ambient lighting
        glLightfv(GL_LIGHT0, GL_DIFFUSE, spotLight->getDiffuse()); // Setup diffuse lighting
        glLightfv(GL_LIGHT0, GL_SPECULAR, spotLight->getSpecular());
        glLightfv(GL_LIGHT0, GL_POSITION, light0->getPositionArray()); // Setup the lighting 
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0f);
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0->getDirectionArray());
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
        glEnable(GL_LIGHT0);
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

void lightCamera(LightPost* light)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
    gluLookAt(light->getPosX(),light->getPosY(),light->getPosZ(),light->getLookX()+light->getPosX(), light->getLookY()+light->getPosY(), light->getLookZ()+light->getPosZ(),  0, 1, 0);

}
void commanderCamera()
{
        
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
	//gluLookAt(locX + RADIUS * sin(rot * 1.0f / 8), locY, locZ - RADIUS + RADIUS * cos(rot * 1.0f / 8),
	//	locX, 0, locZ - RADIUS, 0, 1, 0);
        //Update the position of the camera light
        lightCamera(light0);
        light0->updatePosition(locX, 2.5, locZ-RADIUS);

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
		GLfloat moveVector[] = { 0 + 1 * sin(rot * 1.0f / 8), 0 + 1 * cos(rot * 1.0f / 8)};
		locZ += moveVector[1];
		locX += moveVector[0];
                glutPostRedisplay();

	}

	if (funcKeyStates[GLUT_KEY_PAGE_UP])
        {
		rot++;
                glutPostRedisplay();
        }
	else if (funcKeyStates[GLUT_KEY_PAGE_DOWN])
        {
		rot--;
                glutPostRedisplay();
        }
	else if (funcKeyStates[GLUT_KEY_END])
        {
		rot = 0;
                glutPostRedisplay();
        }
}

static GLfloat denom = 4.0f;

void keyOperations()
{
	if (keyStates[(int)'q'])
		choice = ++choice % nbOfChoices; 
		
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
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	funcKeyOperations();
	keyOperations();
        renderLights();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch (choice)
	{
	case 3:
		levelRenderer.render();
		break;
	case 1:
		missileLauncher.draw();
		break;
	case 2:
		phaser.draw();
		break;
	case 0:
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
        //lightCamera(light3);
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
	pit2.switchPitType();

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
