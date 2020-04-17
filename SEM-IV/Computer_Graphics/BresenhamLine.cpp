//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

//Bresenham Line

#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
#define w 600
#define h 600

void myInit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0f,1.0f,1.0f);
    glPointSize(3.0f);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

int sign(float x)
{
    if(x > 0)
        return 1;
    else if(x < 0)
        return -1;
    else
        return 0;
}

void plot(float x,float y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void axis()
{
    int i;
    glColor3f(0.7f,0.7f,0.7f);
    glPointSize(3.0f);
    for(i=-w/2;i<=w/2;i+=2)
    {
        plot(0,i);
        plot(i,0);
    }
    glFlush();
}

void line()
{
    float x1,x2,y1,y2,length,interchange,dx,dy,x,y,s1,s2,e,temp;
    cout << "\n\tEnter value of x1 and y1 : ";
    cin >> x1 >> y1;
    cout << "\n\tEnter value of x2 and y2 : ";
    cin >> x2 >> y2;
    glColor3f(0.0f,1.0f,0.0f);
    x=x1;
    y=y1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    s1=sign(x2-x1);
    s2=sign(y2-y1);

    if(dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }

    e = (2 * dy) - dx;
    plot(x,y);

    for(int i=1;i<=dx;i++)
    {
        plot(x,y);
        while(e >= 0)
        {
            if(interchange == 1)
                x = x + s1;
            else
                y = y + s2;
            e = e - 2 * dx;
        }
        if(interchange == 1)
        {
            y = y + s2;
        }
        else
        {
            x = x + s1;
        }
        e = e + 2 * dy;
    }
}

void square(float x1,float y1,float x2,float y2)
{
    float length,interchange,dx,dy,x,y,s1,s2,e,temp;
    x=x1;
    y=y1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    s1=sign(x2-x1);
    s2=sign(y2-y1);

    if(dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }

    e = (2 * dy) - dx;
    plot(x,y);

    for(int i=1;i<=dx;i++)
    {
        plot(x,y);
        while(e >= 0)
        {
            if(interchange == 1)
                x = x + s1;
            else
                y = y + s2;
            e = e - 2 * dx;
        }
        if(interchange == 1)
        {
            y = y + s2;
        }
        else
        {
            x = x + s1;
        }
        e = e + 2 * dy;
    }
}

void dashed()
{
    float x1,x2,y1,y2,length,interchange,dx,dy,x,y,s1,s2,e,temp;
    cout << "\n\tEnter value of x1 and y1 : ";
    cin >> x1 >> y1;
    cout << "\n\tEnter value of x2 and y2 : ";
    cin >> x2 >> y2;
    glColor3f(0.0f,1.0f,1.0f);
    x=x1;
    y=y1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    s1=sign(x2-x1);
    s2=sign(y2-y1);

    if(dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }

    e = (2 * dy) - dx;
    plot(x,y);

    for(int i=1;i<=dx;i++)
    {
        if((i/20)%2==0)
        plot(x,y);
        while(e >= 0)
        {
            if(interchange == 1)
                x = x + s1;
            else
                y = y + s2;
            e = e - 2 * dx;
        }
        if(interchange == 1)
        {
            y = y + s2;
        }
        else
        {
            x = x + s1;
        }
        e = e + 2 * dy;
    }
}

void dotted()
{
    float x1,x2,y1,y2,length,interchange,dx,dy,x,y,s1,s2,e,temp;
    cout << "\n\tEnter value of x1 and y1 : ";
    cin >> x1 >> y1;
    cout << "\n\tEnter value of x2 and y2 : ";
    cin >> x2 >> y2;
    glColor3f(1.0f,1.0f,0.0f);
    x=x1;
    y=y1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    s1=sign(x2-x1);
    s2=sign(y2-y1);

    if(dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }

    e = (2 * dy) - dx;
    plot(x,y);

    for(int i=1;i<=dx;i++)
    {
        if((i/5)%5==0)
            plot(x,y);
        while(e >= 0)
        {
            if(interchange == 1)
                x = x + s1;
            else
                y = y + s2;
            e = e - 2 * dx;
        }
        if(interchange == 1)
        {
            y = y + s2;
        }
        else
        {
            x = x + s1;
        }
        e = e + 2 * dy;
    }
}

void pattern()
{
    glColor3f(1.0f,0.0f,0.0f);
    square(-200,200,-200,-200);
    square(-200,200,200,200);
    square(200,200,200,-200);
    square(200,-200,-200,-200);

    glColor3f(0.0,1.0,0.0);
    square(0,200,200,0);
    square(200,0,0,-200);
    square(0,-200,-200,0);
    square(-200,0,0,200);

    glColor3f(1.0,0.0,1.0);
    square(-100,100,-100,-100);
    square(-100,100,100,100);
    square(100,100,100,-100);
    square(100,-100,-100,-100);

    glEnd();
    glFlush();
}

void menu(int value)
{
    if(value == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        line();
    }
    else if(value == 2)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        dashed();
    }
    else if(value == 3)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        dotted();
    }
    else if(value == 4)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        pattern();
    }
    else if(value == 5)
    {
        exit(1);
    }
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Bresenham");
    glutDisplayFunc(axis);
    glutCreateMenu(menu);
    glutAddMenuEntry("Simple Line",1);
    glutAddMenuEntry("Dashed Line",2);
    glutAddMenuEntry("Dotted Line",3);
    glutAddMenuEntry("Pattern",4);
    glutAddMenuEntry("Exit",5);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    myInit();
    glutMainLoop();
}
