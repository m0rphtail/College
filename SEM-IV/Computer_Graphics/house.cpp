#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
void myDisplay(void)
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    
    glBegin(GL_LINE_LOOP);	//shell
	glVertex2i(40, 40);
	glVertex2i(40, 90);
	glVertex2i(70, 120);
	glVertex2i(100, 90);
	glVertex2i(100, 40);
	glEnd();

	glBegin(GL_LINE_STRIP);		//chimney
	glVertex2i(50, 100);
	glVertex2i(50, 120);
	glVertex2i(60, 120);
	glVertex2i(60, 110);
	glEnd(); 
    
	glBegin(GL_LINE_STRIP);		//door
	glVertex2i(55, 40);
	glVertex2i(55, 70);
	glVertex2i(65, 70);
	glVertex2i(65, 40);
	glEnd();
	
	glBegin(GL_LINE_LOOP);		//window
	glVertex2i(80, 65);
	glVertex2i(80, 80);
	glVertex2i(95, 80);
	glVertex2i(95, 65);
	glEnd();
	glFlush(); 
} 

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("MY First Attempt");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

