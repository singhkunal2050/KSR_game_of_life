void initGOL()
{
	srand(time(0));                         // psuedo random base for random generation init by curr time 
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			if(i==j || i==rows-j && (i>50 && i<100) )										// i == hor line(col)
				next[i][j].state=curr[i][j].state=1;									// gets the random values form 0 | 1 for even postn
			else
				next[i][j].state=curr[i][j].state=0;									// 0 at every odd postn

}

//minimal 

void initGOL()
{	
	srand(time(0));                         	// psuedo random base for random generation init by curr time 
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			if((i==66 && j>50 && j<100) || (i==132 && j>50 && j<100)  )										// i == hor line(col)
				next[i][j].state=curr[i][j].state=1;									// gets the random values form 0 | 1 for even postn
			else
				next[i][j].state=curr[i][j].state=0;									// 0 at every odd postn
}


void initGOL()
{
	srand(time(0));                         // psuedo random base for random generation init by curr time 
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			if(i==j || i==rows-j || i==rows/2 || j==cols/2)										// i == hor line(col)
				next[i][j].state=curr[i][j].state=0;									// gets the random values form 0 | 1 for even postn
			else
				next[i][j].state=curr[i][j].state=1;									// 0 at every odd postn

}


// basic oscilating hexagon 

void initGOL()
{	
	srand(time(0));                         	// psuedo random base for random generation init by curr time 
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			if((i==100 && j>50 && j<100) )										// i == hor line(col)
				next[i][j].state=curr[i][j].state=1;									// gets the random values form 0 | 1 for even postn
			else
				next[i][j].state=curr[i][j].state=0;									// 0 at every odd postn
}

