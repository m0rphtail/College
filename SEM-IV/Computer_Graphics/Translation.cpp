#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 640
#define h 480
using namespace std;


float obj1[3][3];


void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0f,0.0f,0.0f);
glPointSize(8.0f);
glLineWidth(2.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);
}


void plot(float a,float b)
{
	glBegin(GL_POINTS);
	glVertex2i(a,b);

	glEnd();
	glFlush();

}

void pattern()
{
glBegin(GL_LINE_LOOP);
glColor3f(1.0f,0.0f,1.0f);
glPointSize(5.0f);
glLineWidth(2.0f);
	glVertex2i(0,0);
	glVertex2i(100,0);
	glVertex2f(50,86.60);

glEnd();
glFlush();

}
void axis(void)
{

int i=0;
glColor3f(0.0f,0.0f,1.0f);
glPointSize(5.0f);
glLineWidth(1.0f);
  for(i=-w;i<=w;i+=4)
  {
   plot(i,0);
   plot(0,i);
  }

}

void plotp(float obj1[][3])
{
	int i;
	glColor3f(1.0,0.0,0.0);
    glPointSize(5.0f);
    glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<3;i++)
		glVertex2i(obj1[i][0],obj1[i][1]);

	glEnd();
	glFlush();
}

void mul(float m[][3])
{
int obj[3][3];
int i,j,k;

obj[0][0]=0;
obj[1][0]=100;
obj[2][0]=50;
obj[0][1]=0;
obj[1][1]=0;
obj[2][1]=86.60;
obj[0][2]=obj[1][2]=obj[2][2]=1;

 for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			obj1[i][j]=0;
			for(k=0;k<3;k++)
			{
				obj1[i][j] += obj[i][k] * m[k][j];
			}
		}
	}
}
/*void mul1(float m[][3],float n[][3],float f[][3])
{

int i,j,k;
float temp[3][3],b[3][3],obj[3][3];
obj[0][0]=0;
obj[1][0]=100;
obj[2][0]=50;
obj[0][1]=0;
obj[1][1]=0;
obj[2][1]=86.60;
obj[0][2]=obj[1][2]=obj[2][2]=1;

 for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
			for(k=0;k<3;k++)
			{
				temp[i][j] += n[i][k] * m[k][j];
			}
		}
	}
	 for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
			for(k=0;k<3;k++)
			{
				b[i][j] += temp[i][k] * f[k][j];
			}
		}
	}
	 for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
			for(k=0;k<3;k++)
			{
				obj1[i][j] += b[i][k] * obj[k][j];
			}
		}
	}
	
}*/

void trans(int tx,int ty)
{

float t[3][3];

t[0][0]=1;
t[0][1]=0;
t[0][2]=0;
t[1][0]=0;
t[1][1]=1;
t[1][2]=0;
t[2][0]=tx;
t[2][1]=ty;
t[2][2]=1;


mul(t);
 
plotp(obj1);
}

void rotation(int ch,int angle)
{
    glClear(GL_COLOR_BUFFER_BIT);
    float r[3][3];
	angle=(3.14*angle)/180;

	if(ch==1)
	{
		r[0][0]=cos(angle);
		r[0][1]=-sin(angle);
		r[0][2]=0;
		r[1][0]=sin(angle);
		r[1][1]=cos(angle);
		r[1][2]=0;
		r[2][0]=0;
		r[2][1]=0;
		r[2][2]=1;
	}

	else
	{
		r[0][0]=cos(angle);
		r[0][1]=sin(angle);
		r[0][2]=0;
		r[1][0]=-sin(angle);
		r[1][1]=cos(angle);
		r[1][2]=0;
		r[2][0]=0;
		r[2][1]=0;
		r[2][2]=1;
	}

    mul(r);
	plotp(obj1);
}
void scaling(int sx,int sy)
{
glClear(GL_COLOR_BUFFER_BIT);
float s[3][3];

s[0][0]=sx;
s[1][0]=0;
s[2][0]=0;
s[0][1]=0;
s[1][1]=sy;
s[2][1]=0;
s[0][2]=0;
s[1][2]=0;
s[2][2]=1;


mul(s);
plotp(obj1);
}

void reflection(int ch)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int i,j;
	float ref[3][3];

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			ref[i][j]=0;

	if(ch==1)
	{
		ref[0][0]=1;
		ref[1][1]=-1;
		ref[2][2]=1;

		mul(ref);
		plotp(obj1);
	}

	if(ch==2)
	{
		ref[0][0]=-1;
		ref[1][1]=1;
		ref[2][2]=1;

		mul(ref);
		plotp(obj1);
	}

	if(ch==3)
	{
		ref[0][0]=-1;
		ref[1][1]=-1;
		ref[2][2]=1;

		mul(ref);
		plotp(obj1);
	}

	if(ch==4)
	{
		ref[0][1]=1;
		ref[1][0]=1;
		ref[2][2]=1;

		mul(ref);
		plotp(obj1);
	}
}

void shear(int ch,int shx,int shy)
{
float sh[3][3];
if(ch==1)
	{
		sh[0][0]=1;
		sh[1][0]=shx;
		sh[1][1]=1;
		sh[2][2]=1;

		mul(sh);
		plotp(obj1);
	}
	if(ch==2)
	{
		sh[0][0]=1;
		sh[0][1]=shy;
		sh[1][1]=1;
		sh[2][2]=1;

		mul(sh);
		plotp(obj1);
	}
}
void scaling_fx(int sx,int sy,int tx,int ty)
{
float n[3][3];
n[0][0]=sx;
n[1][1]=sy;
n[2][0]=tx*(1-sx);
n[2][1]=ty*(1-sy);
n[2][2]=1;

mul(n);
plotp(obj1);
}
void rotation_arbi(int mx,int my,int angle)
{

float m[3][3];
angle=(3.14*angle)/180;
m[0][0]=cos(angle);
m[0][1]=sin(angle);
m[1][0]=-sin(angle);
m[1][1]=cos(angle);
m[2][0]=-mx*cos(angle)+my*sin(angle)+mx;
m[2][1]=-mx*sin(angle)-my*cos(angle)+my;
m[2][2]=1;

 mul(m);
plotp(obj1);
}

void menu(int item)
{

if (item==1)
  {
  pattern();
  int tx,ty;
  cout<<"Enter the value of Tx"<<endl;
  cin>>tx;
  cout<<"Enter the value of Ty"<<endl;
  cin>>ty;

  trans(tx,ty);
  }
if (item==2)
  {
  pattern();
    int ch,angle;
	cout<<"1.Clockwise Rotation \n2.AntiClockwise Rotation : \n";
	cin>>ch;

	cout<<"\nEnter Angle of Rotation : ";
	cin>>angle;

   rotation(ch,angle);
  }
if (item==3)
  {
  pattern();
    int sx,sy;
    cout<<"Enter the value of Sx"<<endl;
    cin>>sx;
    cout<<"Enter the value of Sy"<<endl;
    cin>>sy;
    scaling(sx,sy);
  }
if (item==4)
  {
  pattern();
    int ch;
   	cout<<"\n1.Reflection about X axis\n2.Reflection about Y axis\n3.Reflection about Origin\n4.Reflection about line x=y";
	cout<<"\nEnter your choice:";
	cin>>ch;
    reflection(ch);
  }
if (item==5)
  {
  pattern();
   int ch,shx,shy;
   cout<<"\n1.X-Shear\n2.Y-Shear";
   cout<<"\nEnter your choice : ";
   cin>>ch;
   if(ch==1)
	{
		cout<<"\nEnter X shear factor : ";
		cin>>shx;
	}
	if(ch==2)
	{
		cout<<"Enter Y shear factor : ";
		cin>>shy;
	}
   shear(ch,shx,shy);
  }
if (item==6)
  {
    trans(50,50);
    int sx,sy;
    cout<<"Enter the value of Sx"<<endl;
    cin>>sx;
    cout<<"Enter the value of Sy"<<endl;
    cin>>sy;  
    
    scaling_fx(sx,sy,-50,-50);
  }
if (item==7)
  {
  int mx,my,angle;
  cout<<"Enter the value x"<<endl;
  cin>>mx;
  cout<<"Enter the value y"<<endl;
  cin>>my;
  cout<<"\nEnter Angle of Rotation : ";
  cin>>angle;
  rotation_arbi(mx,my,angle);
  }
if (item==8)
  {
  exit(0);
  }
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(700,700);
glutInitWindowPosition(350,90);
glutCreateWindow("TRANSFORMATION");
glutDisplayFunc(axis);
glutCreateMenu(menu);
glutAddMenuEntry("TRANSLATION",1);
glutAddMenuEntry("ROTATION",2);
glutAddMenuEntry("SCALING",3);
glutAddMenuEntry("REFLECTION",4);
glutAddMenuEntry("SHEAR",5);
glutAddMenuEntry("SCALING FIXED",6);
glutAddMenuEntry("ROTATION ARBITARY",7);
glutAddMenuEntry("EXIT",8);
glutAttachMenu(GLUT_RIGHT_BUTTON);

myInit();
glutMainLoop();
}
