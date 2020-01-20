#include <GL/gl.h>
#include <GL/glut.h>
#include<time.h>
#include<stdio.h>

#define rows 200				// ideal 50	
#define cols 200
#define P_SIZE 3

float r,g,b;

//for gol
struct cell
{
	int state;
};

int i,j,k,l;
int count;							// count of neigh
struct cell curr[rows][cols];
struct cell next[rows][cols];

void initGOL()
{
	srand(time(0));                         // psuedo random base for random generation init by curr time 
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			next[i][j].state=curr[i][j].state=rand()%2;									// gets the random values form 0 | 1	
}

void play()
{
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			next[i][j].state=curr[i][j].state;		// gets the next generation for calculating future gen		

	for(i=1;i<rows-1;i++)							// not starting from extreme ends 
	{
		srand(time(0));                         	// psuedo random base for random generation init by curr time 
		for(j=1;j<cols-1;j++)
		{
			for(k=-1;k<2;k++)
				for(l=-1;l<2;l++)
					count+=curr[i+k][j+l].state;					//count for neigh states

			count-=curr[i][j].state;								//removing its own count from neighh

			if(curr[i][j].state==1 && (count>3 || count<2) )		//cell dies in crowd or loneliness 
				next[i][j].state=0;
			else if(curr[i][j].state==1 && (count==3 || count==2) )		//statis no changes 
				next[i][j].state=curr[i][j].state;
			else if(curr[i][j].state==0 && count==3)					//new cell takes birth if a dead cell has exactly 3 neigh 
				next[i][j].state=1;
	
			count =0;						// resetting count
		}
	}

	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			curr[i][j].state=next[i][j].state;									// stores the latest gen in curr for next iteration		

}



void display()
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%d ",next[i][j].state);
		}
			printf("\n");
	}
	printf("------------------------------------------------\n");
}


//graphics

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glPointSize(P_SIZE);					//ideal 8
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,rows,0.0,cols);
	initGOL();
	//display();

}

void showGrid(){
	srand(time(0));                         // psuedo random base for random generation init by curr time 
	for (i = 1; i < rows-1; i++)			//// I+P_size
	{
		for (j = 1; j < cols-1; j++)		// j+P_size
		{	
		    r=rand()%255;		    g=rand()%255;		    b=rand()%255;
		    
		    glBegin(GL_POINTS);
			if(curr[i][j].state==1)					//living cell
			{
			    glColor3ub(r,g,b);						// random colors option
				//glColor3f(1,1,1);						// white cells
				glVertex2f(i,j);
			}		
			else if(curr[i][j].state==0)					//living cell
			{
			    glColor3f(0,0,0);
				glVertex2f(i,j);
			}
			glEnd();
		}
	}
}

void myDisplay(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	play();						//executing game
    showGrid();					//displaying next gen
	glutSwapBuffers();

}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("KSR GAME OF LIFE ");
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);
	init();
	glutMainLoop();

	return 0;
}