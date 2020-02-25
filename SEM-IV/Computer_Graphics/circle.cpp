#include<iostream>
#include<GL/glut.h>
#define w 500
#define ht 500
using namespace std;

void setpixel(GLint x,GLint y)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();

}
void plot(GLfloat x,GLfloat y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();

}
void put_pixel(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

int sign(float x)
{
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
}

void DDA(float x1, float y1, float x2, float y2)
{
	float length;
	float Dx,Dy,x,y;

	if (abs(x2-x1)>=abs(y2-y1))
			length=abs(x2-x1);
	else
		length=abs(y2-y1);
    Dx=(x2-x1)/length;
    Dy=(y2-y1)/length;
    x=x1+0.5*sign(Dx);
    y=y1+0.5*sign(Dy);
    int i=1;
    while(i<=length)
    {
    	setpixel(x,y);
    			x=x+Dx;
    			y=y+Dy;
    			i=i+1;
    }

}
void simplecircle(float r,float h,int k)
{
	int d;
	d=3-2*r;
	int x=0;
	int y=r;
	put_pixel(h,k);
	while(x<=y)
	{
		if(d<0)
		{
			d=d+4*x+6;
			x=x+1;
		}
		else
		{
			d=d+4*(x-y)+10;
			x=x+1;
			y=y-1;
		}
		put_pixel(x+h,y+k);
		put_pixel(y+h,x+k);
		put_pixel(-y+h,x+k);
		put_pixel(-x+h,y+k);
		put_pixel(-x+h,-y+k);
		put_pixel(-y+h,-x+k);
		put_pixel(y+h,-x+k);
		put_pixel(x+h,-y+k);
	}
}

void olympic(float r,float h,int k)
{
	int i;
	float x;
	for(i=0;i<3;i++)
	{
		simplecircle(r,h,k);
		x=1.5*r;
		h=h+x;
	}
	h=h-(1.5*x);
	k=k-x;
	for(i=0;i<2;i++)
	{
		simplecircle(r,h,k);
		float x=1.5*r;
		h=h-x;
	}
}

void audi(float r,float h,int k)
{
	int i;
	float x;
	for(i=0;i<4;i++)
	{
		simplecircle(r,h,k);
		x=1.5*r;
		h=h+x;
	}
	h=h-(1.5*x);
	k=k-x;
}

void concentric(float r,float h,int k)
{
	int n;
	cout<<"\nEnter the number of circles:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		simplecircle(r,h,k);
		r=r+25;
	}

}

void pattern(int r,int h, int k)
{
	simplecircle(r,h,k);
           glColor3f(0.0f,1.0f,0.0f);
	DDA(h,k+r,h-(0.866*r),k-(r*0.5));
	DDA(h-(0.866*r),k-(r*0.5),h+(0.866*r),k-(r*0.5));
	DDA(h+(0.866*r),k-(r*0.5),h,k+r);

	simplecircle(r/2,h,k);

}

void spiral(int h,int k)
{
 	int x,y,r,d;
 	put_pixel(h,k);
	for(r=0;r<=200;r+=25)
	{
		x=0;
		y=r;
		d=3-(2*r);
		while(x<=y)
		{
			if( d<0 )
			{
				d=d+(4*x)+6;
				x++;
			}
			else
			{
				d=d+ 4*(x-y) +10;
				x++;
				y--;
			}
			if(r%10==0)
			{
				put_pixel(x+h,y+k);
				put_pixel(y+h,x+k);
				put_pixel(-y+h,x+k);
				put_pixel(-x+h,y+k);
			}
			else
			{
				h+=25;
				put_pixel(-x+h,-y+k);
				put_pixel(-y+h,-x+k);
				put_pixel(y+h,-x+k);
				put_pixel(x+h,-y+k);
				h-=25;
			}
		}
	}
}

void myDisplay(void)
{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.90f,1.0f,0.40f);
		glPointSize(4.0);
		for(int i=-w;i<=w;i+=2)
		{
			setpixel(i,0);
			setpixel(0,i);
		}

		glFlush();
}
void menu(int item)
{
	cout<<"Menu:You clicked item:"<<item;
	if(item==1)
	{
		int r,h,k;
		cout<<"\nEnter the radius: ";
		cin>>r;
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		simplecircle(r,h,k);

	}
	if(item==2)
	{
		int r,h,k;
		cout<<"\nEnter the radius: ";
		cin>>r;
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		olympic(r,h,k);

	}
	if(item==3)
	{
		int r,h,k;
		cout<<"\nEnter the radius: ";
		cin>>r;
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		concentric(r,h,k);
	}
	if(item==4)
	{
		int h,k;
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		spiral(h,k);

	}
	if(item==5)
	{
		int r,h,k;
		cout<<"\nEnter the radius: ";
		cin>>r;
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		pattern(r,h,k);
	}
	if(item==7)
	{
		int r,h,k;
		cout<<"\nEnter the radius: ";
		cin>>r;
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		audi(r,h,k);

	}
	if(item==6)
	{
		exit(0);
	}
}
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-ht/2,ht/2);
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(350,90);
	glutCreateWindow("Bresenham Circle");
	myInit();
	glutDisplayFunc(myDisplay);
		glutCreateMenu(menu);
		glutAddMenuEntry("Simple Circle",1);
		glutAddMenuEntry("Olympic Rings",2);
		glutAddMenuEntry("Audi Logo",7);		
		glutAddMenuEntry("Concentric Circles",3);
		glutAddMenuEntry("Spiral",4);
		glutAddMenuEntry("Pattern",5);
		glutAddMenuEntry("Exit",6);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

