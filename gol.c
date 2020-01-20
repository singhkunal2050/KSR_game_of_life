#include <stdio.h>
#include<stdlib.h>


struct cell
{
	int state;
};

int i,j,k,l;
int count;							// count of neigh
struct cell curr[5][5];
struct cell next[5][5];


void initGOL()
{
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			next[i][j].state=rand()%2;									// gets the random values form 0 | 1	
}

void play()
{
	count =0;						// resetting count

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			curr[i][j]=next[i][j];									// gets the next generation for calculating future gen		

	for(i=1;i<5-1;i++)			// not starting from extreme ends 
		for(j=1;j<5-1;j++)
		{
			//for each cell we find its live neigh cell count

			for(k=-1;k<2;k++)
				for(l=-1;l<2;l++)
					count+=curr[i+k][j+l].state;					//count for neigh states

			count-=curr[i][j].state;								//removing its own count from neighh

			if(curr[i][j].state==1 && (count>3 || count<2) )		//cell dies in crowd or loneliness 
				next[i][j].state=0;
			
			if(curr[i][j].state==1 && (count==3 || count==2) )		//statis no changes 
				next[i][j].state=curr[i][j].state;

			if(curr[i][j].state==0 && count==3)					//new cell takes birth if a dead cell has exactly 3 neigh 
				next[i][j].state=1;
			
		}
}




void display()
{
	printf("------------------------------------------------\n");

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",next[i][j].state);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	int c;

	initGOL();	
	//display();

	for (c = 0; c < 10; c++)
	{
		display();
		play();
	}




	return 0;
}
