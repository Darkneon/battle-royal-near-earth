#define FREEGLUT_STATIC
#include <GL\glut.h>

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
double fovy = 45.0;

static GLint rotX = 0;
static GLint rotY = 0;

//the vertices
//==============================================================================
GLfloat vPhasersBase[] = { -1.0f,  0.5f,  1.0f, //v1
					        1.0f,  0.5f,  1.0f, //v2
					        1.0f, -0.5f,  1.0f, //v3
					       -1.0f, -0.5f,  1.0f, //v4
					       -1.0f, -0.5f, -1.0f, //v5
					        1.0f, -0.5f, -1.0f, //v6
						    1.0f,  0.5f, -1.0f, //v7
					       -1.0f,  0.5f, -1.0f}; //v8

//==============================================================================


//sets up rendering context
void render()
{
	//clears the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//preps the 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(rotX * 10, 1, 0, 0);
	glRotatef(rotY * 10, 0, 1, 0);

	//phaser base
	glBegin(GL_QUAD_STRIP);
		glColor3f(1, 0, 0);
		glVertex3f(vPhasersBase[9], vPhasersBase[10], vPhasersBase[11]); //v4
		glVertex3f(vPhasersBase[6], vPhasersBase[7], vPhasersBase[8]); //v3
		glVertex3f(vPhasersBase[0], vPhasersBase[1], vPhasersBase[2]); //v1
		glVertex3f(vPhasersBase[3], vPhasersBase[4], vPhasersBase[5]); //v2
		glVertex3f(vPhasersBase[21], vPhasersBase[22], vPhasersBase[23]); //v8
		glVertex3f(vPhasersBase[18], vPhasersBase[19], vPhasersBase[20]); //v7
		glVertex3f(vPhasersBase[12], vPhasersBase[13], vPhasersBase[14]); //v5
		glVertex3f(vPhasersBase[15], vPhasersBase[16], vPhasersBase[17]); //v6
		glVertex3f(vPhasersBase[9], vPhasersBase[10], vPhasersBase[11]); //v4
		glVertex3f(vPhasersBase[6], vPhasersBase[7], vPhasersBase[8]); //v3
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(vPhasersBase[3], vPhasersBase[4], vPhasersBase[5]); //v2
		glVertex3f(vPhasersBase[18], vPhasersBase[19], vPhasersBase[20]); //v7
		glVertex3f(vPhasersBase[15], vPhasersBase[16], vPhasersBase[17]); //v6
		glVertex3f(vPhasersBase[6], vPhasersBase[7], vPhasersBase[8]); //v3
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(vPhasersBase[0], vPhasersBase[1], vPhasersBase[2]); //v1
		glVertex3f(vPhasersBase[9], vPhasersBase[10], vPhasersBase[11]); //v4
		glVertex3f(vPhasersBase[12], vPhasersBase[13], vPhasersBase[14]); //v5
		glVertex3f(vPhasersBase[21], vPhasersBase[22], vPhasersBase[23]); //v8
	glEnd();

	

	glutSwapBuffers();
	glutPostRedisplay();
}

// Respond to window resizing, preserving proportions.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void functionKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		rotY++;
		break;
	
	case GLUT_KEY_RIGHT:
		rotY--;
		break;

	case GLUT_KEY_UP:
		rotX++;
		break;

	case GLUT_KEY_DOWN:
		rotX--;
		break;
	}
}

int main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("Robots mid and top");

	//callbacks
	glutReshapeFunc(reshapeMainWindow);
	glutDisplayFunc(render);
	glutSpecialFunc(functionKeys);
	
	glutMainLoop();

	return 0;
}