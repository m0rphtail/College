//Kshitij Chitnis
//SE-IT  
//S2 Batch
//8016

//House

#include<iostream>
#include<GL/glut.h>

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f ,1.0f, 1.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void hardwiredHouse(void)
{
	glBegin(GL_LINE_LOOP); //shell
	glVertex2i(40,40);
	glVertex2i(40,90);
	glVertex2i(70,120);
	glVertex2i(100,90);
	glVertex2i(100,40);
	glEnd();
        glFlush();


        glBegin(GL_LINE_LOOP);  //door
        glVertex2i(48,40);
	glVertex2i(48,70);
	glVertex2i(65,70);
	glVertex2i(65,40);
	glEnd();
        glFlush();

        glBegin(GL_LINE_LOOP); //chimney
        glVertex2i(50,100);
        glVertex2i(50,120);
        glVertex2i(60,120);
        glVertex2i(60,110);
        glEnd();
        glFlush();

        glBegin(GL_LINE_LOOP);  //window
        glVertex2i(70,70);
	glVertex2i(70,90);
	glVertex2i(90,90);
	glVertex2i(90,70);
	glEnd();
        glFlush();

}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("my first attempt");
	//glutDisplayFunc(myDisplay);
	glutDisplayFunc(hardwiredHouse);
	myInit();
	glutMainLoop();
	return 0;
}
