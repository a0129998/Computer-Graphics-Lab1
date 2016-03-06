// CS3241Lab1.cpp : Defines the entry point for the console application.
#include <cmath>
#include <iostream>

/* Include header files depending on platform */
#ifdef _WIN32
	#include "glut.h"
	#define M_PI 3.14159
#elif __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/GLUT.h>
#endif

using namespace std;

float alpha = 0.0, k=1;
float tx = 0.0, ty=0.0;

void circle(float radius, int startDeg, int endDeg, GLenum mode);
void shiftCircle(float xTrans, float yTrans, float radius, int startDeg, int endDeg, GLenum mode);
void drawEllipse(float radiusX, float radiusY, int startDeg, int endDeg);
void shiftEllipse(float radiusX, float radiusY, int startDeg, int endDeg, float xPos, float yPos);
void mouseClickEvent(int button, int state, int x, int y);

void drawCatface();
void drawRightEar();
void drawCatEye(float radius, float xPos, float yPos);
void drawCatMouth(float radius, float x, float y, float mouthLen, float mouthBre);
void drawCatWiskers();
void drawHighLights();
void drawFlower(float x, float y, float radius, float rHori, float rVert, float r, float g, float b, int petalN);
void allDisplay();
void drawBackgroundFlowers();



void allDisplay() {
	drawCatface();
	drawCatMouth(1.0, 0.0, -1.8, 1.5, 1.0);
	drawCatEye(1.3, 2.73, 1.23);
	drawCatEye(1.3, -2.73, 1.23);
	drawCatWiskers();
	glScalef(-1.0, 1.0, 1.0);
	drawCatWiskers();
	glScalef(-1.0, 1.0, 1.0);

}

void drawCatface() {
	glColor3f(1.0, 0.651, 0.302);
	circle(6.0, 0, 360, GL_POLYGON);

	drawRightEar();
	glScalef(-1.0, 1.0, 1.0);
	drawRightEar();
	glScalef(-1.0, 1.0, 1.0);

	drawHighLights();
	glScalef(-1.0, 1.0, 1.0);
	drawHighLights();
	glScalef(-1.0, 1.0, 1.0);
}

void drawHighLights() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-1.67, 5.73);
	glColor3f(1.0, 1.0, 0.302);
	glVertex2f(-1.0, 4.6);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-0.76, 5.9);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-0.76, 5.9);
	glColor3f(1.0, 1.0, 0.302);
	glVertex2f(0.0, 4.23);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(0.02, 5.9);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-5.9, -0.7);
	glColor3f(1.0, 1.0, 0.302);
	glVertex2f(-4.33, -1.13);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-5.7, -1.7);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-5.7, -1.7);
	glColor3f(1.0, 1.0, 0.302);
	glVertex2f(-4.5, -2.03);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(-5.33, -2.63);
	glEnd();
}

void drawRightEar() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(2.0, 5.67);
	glColor3f(0.6, 0.239, 0.0);
	glVertex2f(6.3, 7.0);
	glColor3f(1.0, 0.651, 0.302);
	glVertex2f(5.63, 1.8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 1.0);
	glVertex2f(2.8, 5.37);
	glColor3f(1.0, 0.9, 1.0);
	glVertex2f(5.27, 5.87);
	glColor3f(1.0, 0.7, 1.0);
	glVertex2f(5.3, 2.63);
	glEnd();
}

void drawCatEye(float radius, float xPos, float yPos) {
	glColor3f(0.0, 1.0, 0.6);
	shiftCircle(xPos, yPos, radius, 0, 360, GL_POLYGON);
	glColor3f(0.0, 0.2, 0.12);
	float radius2 = sqrt(radius * radius * 2);
	shiftCircle(xPos + radius, yPos, radius2, 134, 226, GL_POLYGON);
	shiftCircle(xPos - radius, yPos, radius2, -46, 46, GL_POLYGON);
}

void drawCatMouth(float radius, float x, float y, float mouthLen, float mouthBre) {
	glColor3f(1.0, 0.3, 0.3);
	shiftEllipse(mouthBre, mouthLen, 180, 360, x, y);
	glColor3f(1.0, 0.651, 0.302);
	shiftCircle(x + radius, y , radius, 0, 360, GL_POLYGON);
	shiftCircle(x - radius, y, radius, 0, 360, GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	shiftCircle(x + radius, y, radius, 180, 360, GL_LINE_STRIP);
	shiftCircle(x - radius, y, radius, 180, 360, GL_LINE_STRIP);
	glColor3f(0.8, 0.4, 0.0);
	shiftEllipse(0.3, 0.2, 0, 360, x, y + 0.1);
}

void drawCatWiskers() {
	glBegin(GL_LINES);
	glColor3f(0.3, 0.15, 0);
	glVertex2f(3.6, -1.4);
	glVertex2f(8.6, -2.2);
	glVertex2f(3.87, -2.43);
	glVertex2f(8.43, -3.97);
	glEnd();
}

void drawFlower(float x, float y, float radius, float rHori, float rVert,
	float r, float g, float b, int petalN) {
	glPushMatrix();
	for (int i = 0; i < petalN; i++) {
		glColor3f(r, g, b);
		shiftEllipse(rHori, rVert, 0, 360, x + radius, y);
		glRotatef(360 / petalN * (i+1) , 0.0, 0.0, 1.0);
	}
	glPopMatrix();
	
}

void drawBackgroundFlowers() {
	drawFlower(-6.87, -7.7, 2.0, 1.0, 0.5, 1.0, 0.0, 0.5, 8);
	drawFlower(5.96, -7.27, 2.0, 1.5, 1.0, 0.5, 0.8, 0.0, 8);
	drawFlower(5.83, 6.5, 4, 1.5, 0.9, 0.0, 1.0, 0.5, 8);
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel (GL_SMOOTH);
}



void keyboard (unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {

		case 'a':
			alpha+=10;
			glutPostRedisplay();
		break;

		case 'd':
			alpha-=10;
			glutPostRedisplay();
		break;

		case 'q':
			k+=0.1;
			glutPostRedisplay();
		break;

		case 'e':
			if(k>0.1)
				k-=0.1;
			glutPostRedisplay();
		break;

		case 'z':
			tx-=0.1;
			glutPostRedisplay();
		break;

		case 'c':
			tx+=0.1;
			glutPostRedisplay();
		break;

		case 's':
			ty-=0.1;
			glutPostRedisplay();
		break;

		case 'w':
			ty+=0.1;
			glutPostRedisplay();
		break;
			
		case 27:
			exit(0);
		break;

		default:
		break;
	}
}


void shiftEllipse(float radiusX, float radiusY, int startDeg,
	int endDeg, float xPos, float yPos) {
	glPushMatrix();
	glTranslatef(xPos, yPos, 0);
	drawEllipse(radiusX, radiusY, startDeg, endDeg);
	glPopMatrix();
}

void drawEllipse(float radiusX, float radiusY, int startDeg, int endDeg) {
	int i;

	const float DEG2RAD = 3.14159 / 180.0;

	glBegin(GL_POLYGON);

	for (i = startDeg; i<endDeg; i++)
	{
		float rad = i*DEG2RAD;
		glVertex2f(cos(rad)*radiusX,
			sin(rad)*radiusY);
	}

	glEnd();
}

void shiftCircle(float xTrans, float yTrans, float radius,
	int startDeg, int endDeg, GLenum mode) {
	glPushMatrix();
	glTranslatef(xTrans, yTrans, 0);
	circle(radius, startDeg, endDeg, mode);
	glPopMatrix();
}

void circle(float radius, int startDeg, int endDeg, GLenum mode) {
	glBegin(mode);
	for (float i = startDeg; i < endDeg; i++) {
		float theta = i * 3.14159 / 180;
		float y = radius * sin(theta);
		float x = radius * cos(theta);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void mouseClickEvent(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		float coordinateX = (float)x / 30 - 10;
		float coordinateY = (float)y / 30 * (-1) + 10;
		printf("x = %6.4lf, y = %6.4lf\n", coordinateX, coordinateY);
	}
}

void display(void)
{
	glClearColor(1.0, 1.0, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	//controls transformation
	glScalef(k, k, k);
	glTranslatef(tx, ty, 0);
	glRotatef(alpha, 0, 0, 1);

	//draw your stuff here
	drawBackgroundFlowers();
	allDisplay();


	glPopMatrix();
	glFlush();
}



int main(int argc, char **argv)
{
	cout<<"CS3241 Lab 1\n\n";
	cout<<"+++++CONTROL BUTTONS+++++++\n\n";
	cout<<"Scale Up/Down: Q/E\n";
	cout<<"Rotate Clockwise/Counter-clockwise: A/D\n";
	cout<<"Move Up/Down: W/S\n";
	cout<<"Move Left/Right: Z/C\n";
	cout <<"ESC: Quit\n";

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClickEvent);
	//glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
