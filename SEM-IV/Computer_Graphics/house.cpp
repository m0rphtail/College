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

