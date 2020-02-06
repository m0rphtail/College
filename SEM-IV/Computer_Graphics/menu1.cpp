#include<iostream>
#include<GL/glut.h>
using namespace std;

void dline(float x1,float y1,float x2,float y2);
void DDAdash(float x0, float y0, float x1, float y1);
void plot(float x, float y);
int sign(int );

# define w 640
# define h 480 
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

void menu(int item)
{
	float x1,x2,y1,y2;
	
		
	if(item==1)
	{
		cout<<"\nEnter the First Point";
		cin>>x1>>y1;
		cout<<"\nEnter the Second Point:";
		cin>>x2>>y2;
		glClear(GL_COLOR_BUFFER_BIT);
		dline(x1,y1,x2,y2);
		glFlush();
	}
	
	 	else if(item==2)
		{
		cout<<"\nEnter the First Point";
		cin>>x1>>y1;
		cout<<"\nEnter the Second Point:";
		cin>>x2>>y2;
		glClear(GL_COLOR_BUFFER_BIT);
		DDAdash(x1,y1,x2,y2);
		glFlush();
		}
	else
	{
		cout<<"\nExit";
	}
	 
}

void dline(float x1,float y1,float x2,float y2)
{
	float x,y,dx,dy,lnx,lny,ln;
	lnx=x2-x1;
	lny=y2-y1;
	if(lnx>=lny)
	{
		ln=lnx;
	}
	else 
	{
		ln=lny;
	}
	dx=lnx/ln;
	dy=lny/ln;
	x=x1+(0.5)*sign(dx);
	y=y1+0.5*sign(dy);
	int i=1;
	while(i<=ln)	
	{
		plot(x,y);
		x=x+dx;
		y=y+dy;
		i++;
	}
}


void DDAdash(float x0, float y0, float x1, float y1)
{
	float dx, dy, incx, incy, x, y;
	int steps, i;

	

	dx=x1-x0;
	dy=y1-y0;

	if(abs(dx) > abs(dy))
	{
		steps=dx;
	}
	else
	{
		steps=dy;
	}

	incx=dx/steps;
	incy=dy/steps;
	x=x0+0.5*sign(incx);
	y=y0+0.5*sign(incy);
	for(i=0; i<steps; i++)
	{
	//	if(i%2==0 )	//dotted
		if(i%9>4)				
		plot(x,y);
		x=x+incx;
		y=y+incy;

	}
}


void plot(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

int sign(int i)
{
	if(i<0)
	{
		return -1;
	}
	else if(i==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("my first attempt");
	glutCreateMenu(menu);
	glutAddMenuEntry("1.Line",1);
	glutAddMenuEntry("2.Dash line",2);	
	glutAddMenuEntry("3.Exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myInit();
	glutMainLoop(); 
	
}

