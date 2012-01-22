

#include <math.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL\glut.h>
#endif

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

static int choice = 0;

void drawRectangle()
{
	//phaser base
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-1.0f, -0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f, -0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
		glVertex3f(1.0f,  0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f,  1.0f);
		glVertex3f(1.0f, -0.5f, -1.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f,  0.5f, -1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
		glVertex3f(-1.0f,  0.5f,  1.0f);
		glVertex3f(-1.0f, -0.5f,  1.0f);
		glVertex3f(-1.0f, -0.5f, -1.0f);
	glEnd();
}

void drawCylinder(GLint degrees)
{
	const GLfloat PI_TO_DEGREE_RATIO = 3.14159265 / 180;

	GLfloat radius = 1.0f;
	GLfloat height = 1.5f;
	GLint increment = 10;
	
	glPushMatrix();

		glTranslatef(-radius/2, -height/2, -radius/2);

		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.0f, 0.0f);
			for (int i = 0; i <= degrees; i += increment)
			{
				GLfloat angle = i;
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
			}
		glEnd();
		
		glBegin(GL_POLYGON);
			glVertex3f(0.0f, height, 0.0f);
			for (int i = 0; i <= degrees; i += increment)
			{
				GLfloat angle = i;
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, height, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
			}
		glEnd();
	
		glBegin(GL_TRIANGLES); // 2 triangles on the Z axis
			glVertex3f(0.0f, 0.0f, radius);
			glVertex3f(0.0f, height, -radius);
			glVertex3f(0.0f, 0.0f, -radius);
			glVertex3f(0.0f, 0.0f, radius);
			glVertex3f(0.0f, height, radius);
			glVertex3f(0.0f, height, -radius);
			glVertex3f(0.0f, height, radius);
		glEnd();

		/*
		glBegin(GL_TRIANGLES); // 2 triangles on X
			glVertex3f(radius, 0.0f, 0.0f);
			glVertex3f(0.0f, height, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(radius, 0.0f, 0.0f);
			glVertex3f(radius, height, 0.0f);
			glVertex3f(0.0f, height, 0.0f);
			glVertex3f(radius, height, 0.0f);
		glEnd();
		*/

		for (int i = 0; i < degrees; i += increment) //all the triangles along the perimeter
		{
			GLint angleNext = i + increment;
			GLfloat angle = i;

			glBegin(GL_POLYGON);
				glVertex3f(0.0f + sin(angleNext * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f + cos(angleNext * PI_TO_DEGREE_RATIO) * radius);
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, height, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
				glVertex3f(0.0f + sin(angleNext * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f + cos(angleNext * PI_TO_DEGREE_RATIO) * radius);
				glVertex3f(0.0f + sin(angleNext * PI_TO_DEGREE_RATIO) * radius, height, 0.0f + cos(angleNext * PI_TO_DEGREE_RATIO) * radius);
				glVertex3f(0.0f + sin(angle * PI_TO_DEGREE_RATIO) * radius, height, 0.0f + cos(angle * PI_TO_DEGREE_RATIO) * radius);
				glVertex3f(0.0f + sin(angleNext * PI_TO_DEGREE_RATIO) * radius, 0.0f, 0.0f + cos(angleNext * PI_TO_DEGREE_RATIO) * radius);
			glEnd();
		}

	glPopMatrix();
}


void drawPhaserCannon()
{
	glEnable(GL_DEPTH_TEST);
	//back panel
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(1.0f, 0.0f, 0.0f);
		glScalef(1.2f, 1.0f, 1.2f);
		drawCylinder(180);
	glPopMatrix();

	//cannon barrel
	glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(-0.1f, 0.0f, -0.55f);
		glScalef(0.5f, 1.1f, 0.4f);
		drawRectangle();
	glPopMatrix();

	//cannon base
	glPushMatrix();
		glColor3f(0,1,0);
		glTranslatef(1.1f, -1.1f, -0.1f);
		glScalef(0.9f, 0.5f, 0.9f);
		drawCylinder(360);
	glPopMatrix();
}

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
	
	if (choice == 1) //draw a cylinder	
		drawRectangle();
	else if (choice == 0) //draw half a cylinder
		drawPhaserCannon();
	
	glutSwapBuffers();
	
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
	glutPostRedisplay();
}

void keyboardKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		choice = ++choice % 2; 
		break;

	case 27:
		exit(0);
	}

	glutPostRedisplay();
}

int main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("Robot mids");

	//callbacks	
	glutReshapeFunc(reshapeMainWindow);
	glutDisplayFunc(render);
	glutSpecialFunc(functionKeys);
	glutKeyboardFunc(keyboardKeys);

	glutMainLoop();

	return 0;
}