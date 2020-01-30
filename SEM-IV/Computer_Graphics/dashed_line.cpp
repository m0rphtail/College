#include<iostream>
#include<GL/glut.h>
using namespace std;

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);     glVertex2f((x1),(y1)); glVertex2f((x2),(y2)); glEnd();
void init(void)
{
	glClearColor(0,0,0,0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_LINE_STIPPLE);

	glLineStipple(1, 0x0101); 
	drawOneLine(50.0, 125.0, 150.0, 125.0);
	glLineStipple(2, 0x00FF); 
	drawOneLine(50.0, 100.0, 150.0, 100.0);
//	glLineStipple(3, 0x1C47);  
//	drawOneLine(50.0, 75.0, 150.0, 75.0);

	glDisable(GL_LINE_STIPPLE);
	glFlush();
}

void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(400, 150);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
