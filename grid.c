#include <GL/glut.h>
#include<time.h>

#define rows 50
#define cols 50

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glPointSize(9);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,rows,0.0,cols);
}

void myDisplay(){
	int i,j;


	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

	for (i = 1; i < rows; i++)
	{
   		srand(time(0));                         // psuedo random base for random generation init by curr time 
		for (j = 1; j < cols; j++)
		{	
			int r=rand()%255;
		    int g=rand()%255;
		    int b=rand()%255;
		    glColor3ub(r,g,b);
			glVertex2f(i,j);
		}
	}


	glEnd();
	glFlush();
	glutSwapBuffers();

}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("GRID");
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);

	init();
	glutMainLoop();

	return 0;
}