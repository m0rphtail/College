#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

# define h 500
# define w 500 

void dline(float x1,float y1,float x2,float y2);
void plot(float x, float y);
int sign(int);

GLfloat a[30][2];
GLint k=0;

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(5.0);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
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
	
	else if(i>0)
	{
	   return 1;
	}
}


void plot(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
void dline(float x1,float y1,float x2,float y2)
{
	float x,y,dx,dy,lnx,lny,ln;

	if(abs(x2-x1)>=abs(y2-y1))
	{
	   ln=abs(x2-x1);
	}
	
	else 
	{
	   ln=abs(y2-y1);
	}
	dx=(x2-x1)/ln;
	dy=(y2-y1)/ln;
	x=x1 + 0.5*sign(dx);
	y=y1 + 0.5*sign(dy);
	int i=1;
	
	while(i<=ln)	
	{
	   plot(round(x),round(y));
	   x=x+dx;
	   y=y+dy;
	   i++;
	}
}

void myMouse(GLint button,GLint state,GLint x,GLint y)		
{
	if(state==GLUT_DOWN)
	{
	   if(button==GLUT_LEFT_BUTTON)		//for points plotting
	   {
		a[k][0]=float(x);
		a[k][1]=float(492-y);
		glBegin(GL_POINTS);
		glVertex2f(a[k][0],a[k][1]);
		glEnd();
		k++;
		glFlush();
	   }

	   if(button==GLUT_RIGHT_BUTTON)		//for line drawing
	   {
		for(int i=0;i<(k-1);i++)
		{
		   dline(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);	//DDA to draw line
		}
		dline(a[k-1][0],a[k-1][1],a[0][0],a[0][1]);
		glEnd();
		k=0;
		glFlush();
	   }
	}
}

void menu(int item)
{
	if(item==1)
	{
	   glColor3f(1.0,0.0,0.0);	
	   glutMouseFunc(myMouse);
	}
	
	if(item==2)
	{
	   glColor3f(0.0,1.0,0.0);	
	   glutMouseFunc(myMouse);
	}
	
	if(item==3)
	{
	   glColor3f(0.0,0.0,1.0);	
	   glutMouseFunc(myMouse);
	}
	
	if(item==4)
	{
	   exit(0);
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("MOUSE INTERFACING");
	myInit();
	glutCreateMenu(menu);
	glutAddMenuEntry("1.RED", 1);
	glutAddMenuEntry("2.GREEN", 2);
	glutAddMenuEntry("3.BLUE", 3);
	glutAddMenuEntry("EXIT", 4);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();	
	
	return 0;
}


