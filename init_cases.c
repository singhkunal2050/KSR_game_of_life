
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


