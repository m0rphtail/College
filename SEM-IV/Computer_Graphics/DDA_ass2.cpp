//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

#include<iostream>
#include<math.h>
#include<cmath>
#include<GL/glut.h>
#define h 500
#define w 500
using namespace std;


void myInit(void)
{
	glClearColor(0.0, .0, 0.0, 0.0);
	glColor3f(0.0f ,0.0f, 1.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}



int Sign(float value)
{
   if(value<0)
   return -1;

   if(value==0)
   return 0;

   if(value>0)
   return 1;
}

void Plot(int x,int y)
{
   glBegin(GL_POINTS);
   glVertex2i(x,y);
   glEnd();
   glFlush();
}

void myDisplay()
{
	int i;
	//glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,1.0f);
    glPointSize(4.0);

	for(i=-w;i<=w;i+=2)
	{
       Plot(i,0);
	   Plot(0,i);
	}
}

void line()
{
  glClear(GL_COLOR_BUFFER_BIT);
  myDisplay();
  glColor3f(1.0f, 0.0f, 0.0f);
  float x1,y1,x2,y2;
  cout<<"\n\tEnter the x co-ordinates:";
  cin>>x1>>x2;
  cout<<"\n\tEnter the y co-ordinates:";
  cin>>y1>>y2;
  int length;
  if(abs(x2-x1)>=abs(y2-y1))
 {
    length=abs(x2-x1);
 }
  else
  {
    length=abs(y2-y1);
  }
float Dx,Dy;
Dx=(x2-x1)/length;
Dy=(y2-y1)/length;

float x,y;
x=x1+0.5*Sign(Dx);
y=y1+0.5*Sign(Dy);

int i=1;

 while(i<=length)
 {

    Plot(round(x),round(y));
    x=x+Dx;
    y=y+Dy;
    i=i+1;
  }
 //glFlush();
}

void dashline()
{

  glClear(GL_COLOR_BUFFER_BIT);
  myDisplay();
  float x1,y1,x2,y2;
  cout<<"\n\tEnter the x co-ordinates:";
  cin>>x1>>x2;
  cout<<"\n\tEnter the y co-ordinates:";
  cin>>y1>>y2;
  int length;
  if(abs(x2-x1)>=abs(y2-y1))
 {
    length=abs(x2-x1);
 }
  else
  {
    length=abs(y2-y1);
  }
float Dx,Dy;
Dx=(x2-x1)/length;
Dy=(y2-y1)/length;

float x,y;
x=x1+0.5*Sign(Dx);
y=y1+0.5*Sign(Dy);

int i=1;

 while(i<=length)
 {
if((i/10)%2==0){

    Plot(round(x),round(y));
}
 else
{i++;}
    x  = x+Dx;
    y = y+Dy;
    i = i+1;
  }
 glFlush();
}

void dotline()
{

  glClear(GL_COLOR_BUFFER_BIT);
  myDisplay();
  float x1,y1,x2,y2;
  cout<<"\n\tEnter the x co-ordinates:";
  cin>>x1>>x2;
  cout<<"\n\tEnter the y co-ordinates:";
  cin>>y1>>y2;
  int length;
  if(abs(x2-x1)>=abs(y2-y1))
 {
    length=abs(x2-x1);
 }
  else
  {
    length=abs(y2-y1);
  }
float Dx,Dy;
Dx=(x2-x1)/length;
Dy=(y2-y1)/length;

float x,y;
x=x1+0.5*Sign(Dx);
y=y1+0.5*Sign(Dy);

int i=1;

 while(i<=length)
 {
if((i/2)%2==0){

    Plot(round(x),round(y));
}
 else
{i++;}
    x  = x+Dx;
    y = y+Dy;
    i = i+1;
  }
 glFlush();
}

void boatd(float x1,float y1,float x2,float y2)
{
	float dx,dy,length,x,y;
	int i=1;

	if( abs(x2-x1) >= abs(y2-y1))
            length = abs(x2-x1);
        else
            length = abs(y2-y1);


	dx=(x2-x1)/length;
	dy=(y2-y1)/length;


    x=x1+0.5*Sign(dx);
	y=y1+0.5*Sign(dy);

	while(i<=length)
	{
	  Plot(x,y);
          x=x+dx;
	  y=y+dy;
	  i=i+1;
	}
}

void boat(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	myDisplay();
	glColor3f(0.3f,1.0f,0.5f);
	boatd(-100,0,110,0);
	boatd(-100,0,-70,-50);
	boatd(70,-50,110,0);
	boatd(70,-50,-70,-50);
	boatd(76,-40,-76,-40);
	boatd(110,125,110,0);
	boatd(110,125,65,0);
        glEnd();
        glFlush();
}
void menu(int item)
{
  if(item==1)
  {
     line();
  }

  if(item==2)
  {
     dashline();
  }


  if(item==3)
  {
     dotline();
  }

  if(item==4)
  {
     boat();
  }

  if(item==5)
  {
     exit(0);
  }
}




int main(int argc,char **argv)
{
	glutInit(&argc, argv);glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  	glutInitWindowSize(640,480);
  	glutInitWindowPosition(100, 150);
        glutCreateWindow("Menu");
        glutCreateMenu(menu);
        glutAddMenuEntry("simple line",1);
        glutAddMenuEntry("dashed line",2);
        glutAddMenuEntry("dotted line",3);
        glutAddMenuEntry("boat",4);
        glutAddMenuEntry("Exit",5);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutDisplayFunc(myDisplay);
        myInit();
        glutMainLoop();
        return 0;
}
