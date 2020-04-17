//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

//Animation
                           
#include<iostream>
#include<GL/glut.h>
#include <math.h>
using namespace std;

int frame1=0;

void Init()
{
	glClearColor(0.6,0.9,1,0);
	gluOrtho2D(0,640,0,480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}
void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.0);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+20*cos(th),y+20*sin(th));
   }

   glEnd();

}

void arc(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);
   for(int i=0;i<180;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+25*cos(th),y+25*sin(th));
   }

   glEnd();

}
void car()
{
	
	glScaled(0.5,0.5,0.5);
	glColor3f(1.0,1.0,0.0);
  
  glBegin(GL_POLYGON);  //Car

glVertex2f(0, 200);
glVertex2f(0, 250);
glVertex2f(0, 250);
glVertex2f(70, 290);
glVertex2f(70, 290);
glVertex2f(150, 290);
glVertex2f(150, 290);
glVertex2f(220, 250);
glVertex2f(220, 250);
glVertex2f(260, 250);
glVertex2f(260, 250);
glVertex2f(260, 200);
glVertex2f(260, 200);
glVertex2f(220, 200);
glVertex2f(170, 200);
glVertex2f(80, 200);
glVertex2f(0, 200);
glVertex2f(30, 200);
glEnd();

//1st Window
glBegin(GL_LINE_LOOP);
glColor3f(0.0,0.0,0.0);
glVertex2f(120, 280);
glVertex2f(145, 280);
glVertex2f(145, 280);
glVertex2f(200, 250);
glVertex2f(200, 250);
glVertex2f(120, 250);
glVertex2f(120, 250);
glVertex2f(120, 280);

glEnd();

//2nd window
glBegin(GL_LINE_LOOP);

glVertex2f(70, 280);
glVertex2f(105, 280);
glVertex2f(105, 280);
glVertex2f(105, 250);
glVertex2f(105, 250);
glVertex2f(20, 250);
glVertex2f(20, 250);
glVertex2f(70, 280);

glEnd();

  arc(55,200);
  arc(195,200);
    
  wheel(55,200);
  wheel(195,200);
glEnd();

}
	


void doframe(int v)
{
	frame1++;
	glutPostRedisplay();
	glutTimerFunc(20,doframe,0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0,0.75,0);
	glBegin(GL_TRIANGLES);	//mountains
	glVertex2d(0,300);
	glVertex2d(75,350);
	glVertex2d(150,300);

	glVertex2d(140,300);
	glVertex2d(230,350);
	glVertex2d(300,300);

	glVertex2d(340,300);
	glVertex2d(415,350);
	glVertex2d(490,300);

	glVertex2d(480,300);
	glVertex2d(570,350);
	glVertex2d(640,300);
	glEnd();

	glColor3f(0.5,1,0.5);	//surface
	glBegin(GL_POLYGON);
	glVertex2d(0,0);
	glVertex2d(0,300);
	glVertex2d(640,300);
	glVertex2d(640,0);
	glEnd();

	glColor3f(0,1,1);		//river
	glBegin(GL_POLYGON);
	glVertex2d(220,0);
	glVertex2d(300,300);
	glVertex2d(340,300);
	glVertex2d(400,0);
	glEnd();

	glColor3f(0.5,0.5,0.5);	//road
	glBegin(GL_POLYGON);
	glVertex2d(0,120);
	glVertex2d(0,160);
	glVertex2d(640,160);
	glVertex2d(640,120);
	glEnd();

	glColor3f(1,0,0.5);		//Building
	glBegin(GL_POLYGON);
	glVertex2d(10,160);
	glVertex2d(10,260);
	glVertex2d(45,300);
	glVertex2d(80,260);
	glVertex2d(80,160);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2d(45,220);
	glVertex2d(45,240);
	glEnd();

	glPushMatrix();    //Move car from left to right
	glTranslated((frame1 % 640),50,0);
	car();
	glPopMatrix();
	glFlush();

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);

	glutCreateWindow("Moving Car");
	Init();
	glutDisplayFunc(Display);
	glutTimerFunc(100,doframe,0);
	glutMainLoop();
}
