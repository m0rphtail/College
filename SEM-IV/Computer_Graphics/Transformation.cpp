//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

//Transformation

#include<iostream>
#include<math.h>
#include <GL/glut.h>
using namespace std;
#define width 600
#define height 600

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width/2,width/2,-height/2,height/2);
}

void Triangle()
{
    glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(30,30);
	glVertex2i(120,30);
	glVertex2i(75,108);
	glEnd();

	glFlush();
}

void plot(int x,int y)      //Plot Function
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);

    glEnd();
    glFlush();
}

void plotTriangle(int tri[3][3])      //Plot Function
{
    int i=0;
	glColor3f(0.0f,1.0f,1.0f);
	glBegin(GL_LINE_LOOP);
	 for(i=0;i<3;i++)
                glVertex2i(tri[i][0],tri[i][1]);
	glEnd();
	glFlush();
}

void plotTriangleDouble(double tri[3][3])      //Plot Function
{
    int i=0;
	glColor3f(0.0f,1.0f,1.0f);
	glBegin(GL_LINE_LOOP);
	 for(i=0;i<3;i++)
                glVertex2i(tri[i][0],tri[i][1]);
	glEnd();
	glFlush();
}

void axis()
{
    int i;

    glColor3f(1.0f, 0.0f, 0.0f);
	for(i=-width;i<=width;i++)
	{
		plot(i,0);
		plot(0,i);
	}

	Triangle();
}

void Translation()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int tx,ty,triangle[3][3],translation[3][3],finalM[3][3],i,j,k;
    cout << "\n\tEnter value of tx and ty : ";
    cin >> tx >> ty;
    triangle[0][0]=30;triangle[0][1]=30;triangle[0][2]=1;
    triangle[1][0]=120;triangle[1][1]=30;triangle[1][2]=1;
    triangle[2][0]=75;triangle[2][1]=108;triangle[2][2]=1;
    translation[0][0]=translation[1][1]=translation[2][2]=1;
    translation[0][1]=translation[0][2]=translation[1][0]=translation[1][2]=0;
    translation[2][0]=tx;translation[2][1]=ty;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j] = finalM[i][j] + triangle[i][k] * translation[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void Scaling()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],i,j,k;
    double Sx,Sy,scaling[3][3],finalM[3][3];
    cout << "\n\tEnter value of Sx and Sy : ";
    cin >> Sx >> Sy;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scaling[i][j]=0;
    scaling[0][0]=Sx;scaling[1][1]=Sy;scaling[2][2]=0;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=0;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j] = finalM[i][j] + triangle[i][k] * scaling[k][j];
            }
        }
    }
    plotTriangleDouble(finalM);

}

void ScaleVertex()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int translation[3][3],result1[3][3],i,j,k;
    double Sx,Sy,triangle[3][3],scaling[3][3],finalM[3][3];
    triangle[0][0]=30;triangle[0][1]=30;triangle[0][2]=1;
    triangle[1][0]=120;triangle[1][1]=30;triangle[1][2]=1;
    triangle[2][0]=75;triangle[2][1]=108;triangle[2][2]=1;
    translation[0][0]=translation[1][1]=translation[2][2]=1;
    translation[0][1]=translation[0][2]=translation[1][0]=translation[1][2]=0;
    translation[2][0]=-30;translation[2][1]=-30;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            result1[i][j]=0;
            for(k=0;k<3;k++)
            {
                result1[i][j] = result1[i][j] + triangle[i][k] * translation[k][j];
            }
        }
    }
    cout << "\n\tEnter vale of Sx and Sy : ";
    cin >> Sx >> Sy;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scaling[i][j]=0;
    scaling[0][0]=Sx;scaling[1][1]=Sy;scaling[2][2]=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j] = finalM[i][j] + result1[i][k] * scaling[k][j];
            }
        }
    }
    translation[2][0]=30;translation[2][1]=30;
    finalM[0][2]=finalM[1][2]=finalM[2][2]=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            triangle[i][j]=0;
            for(k=0;k<3;k++)
            {
                triangle[i][j] = triangle[i][j] + finalM[i][k] * translation[k][j];
            }
        }
    }
    plotTriangleDouble(triangle);
}

void RotationPlot(int triangle[3][3],double rotation[3][3])
{
    int i,j,k;
    double finalM[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j] = finalM[i][j] + triangle[i][k] * rotation[k][j];
            }
        }
    }
    plotTriangleDouble(finalM);
}

void RotationClock()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    double theta,rotation[3][3],finalM[3][3];
    int triangle[3][3],i,j,k;
    cout << "\n\tEnter angle of rotation in clockwise direction : ";
    cin >> theta;
    theta = (theta * 3.142)/180;
    cout << "\n\tAngle on radian : " << theta;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            rotation[i][j]=0;
    rotation[0][0]=cos(theta);rotation[0][1]=-sin(theta);rotation[1][0]=sin(theta);rotation[1][1]=cos(theta);
    triangle[0][2]=triangle[1][2]=triangle[2][2]=0;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    RotationPlot(triangle,rotation);
}

void RotationAnticlock()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    double theta,rotation[3][3],finalM[3][3];
    int triangle[3][3],i,j,k;
    cout << "\n\tEnter angle of rotation in Anticlockwise direction : ";
    cin >> theta;
    theta = (theta * 3.142)/180;
    cout << "\n\tAngle in radian : " << theta;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            rotation[i][j]=0;
    rotation[0][0]=cos(theta);rotation[0][1]=sin(theta);rotation[1][0]=-sin(theta);rotation[1][1]=cos(theta);
    triangle[0][2]=triangle[1][2]=triangle[2][2]=0;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    RotationPlot(triangle,rotation);
}

void ReflectionX()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],reflection[3][3],finalM[3][3],i,j,k;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            reflection[i][j]=0;
    reflection[0][0]=reflection[2][2]=1;
    reflection[1][1]=-1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j]=finalM[i][j]+triangle[i][k]*reflection[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void Reflection()
{
   glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],reflection[3][3],finalM[3][3],i,j,k;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            reflection[i][j]=0;
    reflection[0][1]=1;reflection[1][0]=1;reflection[2][2]=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j]=finalM[i][j]+triangle[i][k]*reflection[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void xShear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],shear[3][3],finalM[3][3],i,j,k,shearX;
    cout << "\n\tEnter X shear factor : ";
    cin >> shearX;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            shear[i][j]=0;
    shear[0][0]=1;shear[1][1]=1;shear[2][2]=1;shear[1][0]=shearX;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j]=finalM[i][j]+triangle[i][k]*shear[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void yShear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],shear[3][3],finalM[3][3],i,j,k,shearX;
    cout << "\n\tEnter Y shear factor : ";
    cin >> shearX;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            shear[i][j]=0;
    shear[0][0]=1;shear[1][1]=1;shear[2][2]=1;shear[0][1]=shearX;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j]=finalM[i][j]+triangle[i][k]*shear[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void ReflectionOrigin()
{
   glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],reflection[3][3],finalM[3][3],i,j,k;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            reflection[i][j]=0;
    reflection[0][0]=-1;reflection[1][1]=-1;reflection[2][2]=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j]=finalM[i][j]+triangle[i][k]*reflection[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void ReflectionY()
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    int triangle[3][3],reflection[3][3],finalM[3][3],i,j,k;
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            reflection[i][j]=0;
    reflection[0][0]=-1;reflection[2][2]=1;
    reflection[1][1]=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j]=finalM[i][j]+triangle[i][k]*reflection[k][j];
            }
        }
    }
    plotTriangle(finalM);
}

void RotationArbitraryAnticlock(int tx,int ty)
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    double theta,rotation[3][3],finalM[3][3],result2[3][3];
    int triangle[3][3],i,j,k,translation[3][3],result1[3][3];
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    cout << "\n\tEnter angle of rotation in Clockwise direction : ";
    cin >> theta;
    theta = (theta * 3.142)/180;
    cout << "\n\tAngle in radian : " << theta;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            rotation[i][j]=0;
    rotation[0][0]=cos(theta);rotation[0][1]=sin(theta);rotation[1][0]=-sin(theta);rotation[1][1]=cos(theta);rotation[2][2]=1;
    translation[0][0]=translation[1][1]=translation[2][2]=1;
    translation[0][1]=translation[0][2]=translation[1][0]=translation[1][2]=0;
    translation[2][0]=-tx;translation[2][1]=-ty;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            result1[i][j]=0;
            for(k=0;k<3;k++)
            {
                result1[i][j] = result1[i][j] + triangle[i][k] * translation[k][j];
            }
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            result2[i][j]=0;
            for(k=0;k<3;k++)
            {
                result2[i][j] = result2[i][j] + result1[i][k] * rotation[k][j];
            }
        }
    }

    translation[2][0]=tx;translation[2][1]=ty;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j] = finalM[i][j] + result2[i][k] * translation[k][j];
            }
        }
    }
    plotTriangleDouble(finalM);
}
void RotationArbitraryClock(int tx,int ty)
{
    glClear(GL_COLOR_BUFFER_BIT);
    axis();
    double theta,rotation[3][3],finalM[3][3],result2[3][3];
    int triangle[3][3],i,j,k,translation[3][3],result1[3][3];
    triangle[0][2]=triangle[1][2]=triangle[2][2]=1;
    triangle[0][0]=30;triangle[0][1]=30;
    triangle[1][0]=120;triangle[1][1]=30;
    triangle[2][0]=75;triangle[2][1]=108;
    cout << "\n\tEnter angle of rotation in Clockwise direction : ";
    cin >> theta;
    theta = (theta * 3.142)/180;
    cout << "\n\tAngle in radian : " << theta;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            rotation[i][j]=0;
    rotation[0][0]=cos(theta);rotation[0][1]=-sin(theta);rotation[1][0]=sin(theta);rotation[1][1]=cos(theta);rotation[2][2]=1;
    translation[0][0]=translation[1][1]=translation[2][2]=1;
    translation[0][1]=translation[0][2]=translation[1][0]=translation[1][2]=0;
    translation[2][0]=-tx;translation[2][1]=-ty;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            result1[i][j]=0;
            for(k=0;k<3;k++)
            {
                result1[i][j] = result1[i][j] + triangle[i][k] * translation[k][j];
            }
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            result2[i][j]=0;
            for(k=0;k<3;k++)
            {
                result2[i][j] = result2[i][j] + result1[i][k] * rotation[k][j];
            }
        }
    }
    //plotTriangleDouble(result2);

    translation[2][0]=tx;translation[2][1]=ty;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            finalM[i][j]=0;
            for(k=0;k<3;k++)
            {
                finalM[i][j] = finalM[i][j] + result2[i][k] * translation[k][j];
            }
        }
    }

    plotTriangleDouble(finalM);
}

void Menu(int var)     //Menu
{

    cout<<"\nYour Choice is:"<<var;

    if(var==1)
    {
        Translation();
    }
    else if(var==2)
    {
        Scaling();
    }
    else if(var==3)
    {
        int ch;
        cout << "\n\t1.Clockwise";
        cout << "\n\t2.Anticlockwise";
        cout << "\n\tEnter your choice : ";
        cin >> ch;
        if(ch == 1)
            RotationClock();
        else
            RotationAnticlock();
    }
    else if(var==4)
    {
        ReflectionX();
    }
    else if(var==5)
    {
        ReflectionY();
    }
    else if(var==6)
    {
        int ch,tx,ty;
        cout << "\n\t1.Clockwise";
        cout << "\n\t2.Anticlockwise";
        cout << "\n\tEnter your choice : ";
        cin >> ch;
        cout << "\n\tEnter value of tx and ty : ";
        cin >> tx >> ty;
        if(ch==1)
            RotationArbitraryClock(tx,ty);
        else
            RotationArbitraryAnticlock(tx,ty);
    }
    else if(var==7)
    {
        ReflectionOrigin();
    }
    else if(var==8)
    {
        Reflection();
    }
    else if(var==9)
    {
        int ch;
        cout << "\n\t1.X-shear";
        cout << "\n\t2.Y-shear";
        cout << "\n\tEnter choice : ";
        cin >> ch;
        if(ch==1)
            xShear();
        else
            yShear();
    }
    else if(var==10)
    {
        ScaleVertex();
    }
    else if(var==0)
    {
        exit(0);
    }
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Transformations");
    glutDisplayFunc(axis);
    glutCreateMenu(Menu);
    glutAddMenuEntry("Translation",1);
    glutAddMenuEntry("Scaling",2);
    glutAddMenuEntry("Rotation about origin",3);
    glutAddMenuEntry("Reflection About X axis",4);
    glutAddMenuEntry("Reflection About Y axis",5);
    glutAddMenuEntry("Rotation About Arbitrary Point",6);
    glutAddMenuEntry("Reflection at Origin",7);
    glutAddMenuEntry("Reflection at x=y" ,8);
    glutAddMenuEntry("Shear",9);
    glutAddMenuEntry("Scaling at fixed vertex",10);
    glutAddMenuEntry("Exit",0);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    myInit();
    glutMainLoop();
    return 0;
}

/*
OUTPUT :

Your Choice is:2
        Enter value of Sx and Sy : -0.5
-0.5

Your Choice is:3
        1.Clockwise
        2.Anticlockwise
        Enter your choice : 1

        Enter angle of rotation in clockwise direction : 45

        Angle on radian : 0.7855
Your Choice is:4
Your Choice is:5
Your Choice is:6
        1.Clockwise
        2.Anticlockwise
        Enter your choice : 2

        Enter value of tx and ty : 20
20

        Enter angle of rotation in Clockwise direction : 45

        Angle in radian : 0.7855
Your Choice is:7
*/
