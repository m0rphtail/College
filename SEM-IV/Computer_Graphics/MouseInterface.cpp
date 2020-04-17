//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

//Mouse Interface

#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
#define h 480                                 //declaring hight and width
#define w 640

	float a[32][2];                          //declaring array for storing points
	int k=0;

void myInit(void)                            //myint function
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0f,1.0f,1.0f);
	glPointSize(4.0);                       //Decides the point size of pixel
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
	glClear(GL_COLOR_BUFFER_BIT);
}



int Sign(float value)                        //Sign function for DDA
{
   if(value<0)
   return -1;

   if(value==0)
   return 0;

   if(value>0)
   return 1;
}

void Plot(int x,int y)                      //Plot function for ploting the points
{
   glBegin(GL_POINTS);
   glVertex2i(x,y);
   glEnd();

}



void DDA(float x1,float y1,float x2,float y2) // DDA function
{


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

}

void ddaMouse(int button, int state, int x, int y)
{                                                 //Function for mouseinterfacing
		if(state == GLUT_DOWN){
		if(button == GLUT_LEFT_BUTTON){        //Plotting points using left button

			a[k][0] = float(x-320);
			a[k][1] = float(240-y);

			glBegin(GL_POINTS);
			glVertex2f(a[k][0],a[k][1]);
			cout<<a[k][0]<<"   "<<a[k][1];
			glEnd();
			k++;
			glFlush();
		}

		if(button == GLUT_RIGHT_BUTTON){
			glBegin(GL_LINE_LOOP);                 //for drawing the polygon

			for(int i =0; i<k;i++)
			{

			glVertex2f(a[i][0],a[i][1]);

			}

			glEnd();
			k=0;
			glFlush();
		}
	}

}

void myDisplay()                       //Function for axis
{
   int i;

   glPointSize(2.0);

   for (i=-w; i<=w; i+=2)
   {
   	Plot(i,0);
   	Plot(0,i);
   }

}

void Menu(GLint i)                      //Function for menu
{
    if(i==1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    	glColor3f(1.0f,0.0f,0.0f);
    	myDisplay();
    	glutMouseFunc(ddaMouse);

    }

   if(i==2)
    {
         glClear(GL_COLOR_BUFFER_BIT);
    	 glColor3f(0.0f,0.0f,1.0f);
    	 myDisplay();
    	 glutMouseFunc(ddaMouse);

    }

    if(i==3)
    {
         glClear(GL_COLOR_BUFFER_BIT);
    	 glColor3f(0.0f,1.0f,0.0f);
    	 myDisplay();
    	 glutMouseFunc(ddaMouse);

    }

    if(i==4)
    {
    	exit(0);
    }
 glFlush();
}

int main(int argc,char **argv)           //Main funcion
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(100, 150);

  glutCreateWindow("Mouse Interfacing");

  glutCreateMenu(Menu);

  glutAddMenuEntry("Red",1);


  glutAddMenuEntry("Blue",2);


  glutAddMenuEntry("Green",3);


  glutAddMenuEntry("Exit",4);

  glutAttachMenu(GLUT_MIDDLE_BUTTON);  //for ataching menu on middle buttion
  	glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
  return 0;
}
