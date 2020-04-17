//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

//Circle Algorithm

#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
#define w 600
#define hei 600

void myInit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0f,1.0f,1.0f);
    glPointSize(3.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-hei/2,hei/2);
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
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(2.0);
    for(i=-w/2;i<=w/2;i+=2)
    {
        plot(i,0);
        plot(0,i);
    }
}

void DDA(float x1,float y1,float x2,float y2)
{
    float length,s1,s2,dx,dy,x,y;
    if(abs(x2-x1) >= abs(y2-y1))
    {
        length=abs(x2-x1);
    }
    else
    {
        length=abs(y2-y1);
    }
    dx=(x2-x1)/length;
    dy=(y2-y1)/length;
    int i=1;
    x=x1+0.5*sign(dx);
    y=y1+0.5*sign(dy);
    while(i<=length)
    {
        plot(x,y);
        x=x+dx;
        y=y+dy;
        i+=1;
    }
}

void concentric()
{
    int rad,h,k,num,d,i=0,x,y;
    do{
        cout << "\n\tEnter radius of circle : ";
        cin >> rad;
        if(rad <= 0)
            cout << "\n\tRadius can't be zero or negative..!!";
    }while(rad <= 0);
    cout << "\n\tEnter x and y co ordinates of center of circle : ";
    cin >> h >> k;
    cout << "\n\tEnter number of circle to draw : ";
    cin >> num;
    glColor3f(0.0,1.0,0.0);
    while(i < num)
    {
        x = 0;
        y = rad;
        d = 3 - 2*rad;
        while(x <= y)
        {
            if(d < 0)
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
            plot(x+h,y+k);
            plot(y+h,x+k);
            plot(-y+h,x+k);
            plot(-x+h,y+k);
            plot(-x+h,-y+k);
            plot(-y+h,-x+k);
            plot(x+h,-y+k);
            plot(y+h,-x+k);
        }
        rad = rad+30;
        i++;
    }
}

void spiral()
{
    int rad,h,k,num,d,i=0,x,y,count=0,rad1;
    do{
        cout << "\n\tEnter radius of circle : ";
        cin >> rad;
        if(rad <= 0)
            cout << "\n\tRadius can't be zero or negative..!!";
    }while(rad <= 0);
    rad1=rad;
    h=0;k=0;
    while(count < 3)
    {
        glColor3f(1.0,0.0,1.0);
        x=0;
        y=rad;
        d=3-2*rad;
        while(x <= y)
        {
            if(d <= 0)
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
            plot(x+h,y+k);
            plot(y+h,x+k);
            plot(-y+h,x+k);
            plot(-x+h,y+k);
        }

        h=rad1;
        k=0;
        rad=rad+rad1;
        d=3-2*rad;
        x=0;
        y=rad;
        glColor3f(3.0,2.0,0.0);
        while(x <= y)
        {
            if(d <= 0)
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
            plot(-x+h,-y+k);
            plot(-y+k+rad1,-x+k);
            plot(y+h,-x+k);
            plot(x+h,-y+k);
        }

        h=0;
        rad=rad+rad1;
        count++;
    }
}

void simple(int rad,int h,int k)
{
    int d,x,y;
    d=3-2*rad;
    x=0;
    y=rad;
    plot(h,k);
    while(x <= y)
    {
        if(d < 0)
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
        plot(x+h,y+k);
        plot(y+h,x+k);
        plot(-y+h,x+k);
        plot(-x+h,y+k);
        plot(-x+h,-y+k);
        plot(-y+h,-x+k);
        plot(y+h,-x+k);
        plot(x+h,-y+k);
    }
}

void olympic()
{
    int rad,h,k,count=0,c=5,x,y,d;
    do{
        cout << "\n\tEnter radius of circle : ";
        cin >> rad;
        if(rad <= 0)
            cout << "\n\tRadius can't be zero or negative..!!";
    }while(rad <= 0);
    cout << "\n\tEnter center coordinates of circle : ";
    cin >> h >> k;
    glColor3f(3.0,3.0,0.0);
    while(count < c)
    {
        x=0;
        y=rad;
        d=3-2*rad;
        while(x <= y)
        {
            if(d < 0)
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
            plot(x+h,y+k);
            plot(y+h,x+k);
            plot(-y+h,x+k);
            plot(-x+h,y+k);
            plot(-x+h,-y+k);
            plot(-y+h,-x+k);
            plot(y+h,-x+k);
            plot(x+h,-y+k);
        }
        h=h+120;
        if(count==2)
        {
            h=h-300;
            k=k-50;
        }
        count++;
    }
}

void pattern()
{
    int rad,h,k;
    do{
        cout << "\n\tEnter radius of circle : ";
        cin >> rad;
        if(rad <= 0)
            cout << "\n\tRadius can't be negative or less than zero..!!";
    }while(rad <= 0);
    cout << "\n\tEnter x and y co ordinates of center of circle : ";
    cin >> h >> k;
    glColor3f(3.0,2.0,0.0);
    simple(rad,h,k);

    glColor3f(1.0,0.0,0.0);
    DDA(h,k+rad,h-(0.866*rad),k-(0.5*rad));
    DDA(h-(0.866*rad),k-(0.5*rad),h+(0.866*rad),k-(rad*0.5));
    DDA(h+(0.866*rad),k-(rad*0.5),h,k+rad);

    glColor3f(1.0,0.0,1.0);
    simple(rad/2,h,k);
}

void menu(int value)
{
    if(value == 1)
    {
        int rad,h,k;
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        do{
        cout << "\n\tEnter radius of circle : ";
        cin >> rad;
        if(rad <= 0)
            cout << "\n\tRadius can't be negative or less than zero..!!";
        }while(rad <= 0);
        cout << "\n\tEnter x and y co ordinates of center of circle : ";
        cin >> h >> k;
        glColor3f(1.0,0.0,0.0);
        simple(rad,h,k);
    }
    else if(value == 2)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        concentric();
    }
    else if(value == 3)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        olympic();
    }
    else if(value == 4)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        spiral();
    }
    else if(value == 5)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        axis();
        pattern();
    }
    else
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
    glutCreateWindow("Circle");
    glutDisplayFunc(axis);
    glutCreateMenu(menu);
    glutAddMenuEntry("Simple Circle",1);
    glutAddMenuEntry("Concentric Circle",2);
    glutAddMenuEntry("Olympic",3);
    glutAddMenuEntry("Spiral",4);
    glutAddMenuEntry("Pattern",5);
    glutAddMenuEntry("Exit",0);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    myInit();
    glutMainLoop();
}
