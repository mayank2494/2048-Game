#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<time.h>

int i,j,grid[4][4],vrtual[4][4];
int x,y;
void display()
{
	clrscr();
	cout<<"\n\n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			{cout<<grid[i][j]<<"\t";}
			cout<<"\n\n";
	}

}
class start
{

	public :

	 short int no_gen();

	 void pos();


};

short int start::no_gen()
{
	int temp_no,num;
	randomize();
	temp_no=random(5);

	if(temp_no==1||temp_no==3)
	{num=temp_no + 1;}
	else if(temp_no==0)
	{num=temp_no + 2;}
	else if(temp_no==4||temp_no==2)
	{num=temp_no;}
	return num;
}

void start::pos()
{
	int a1,a2,b1,b2;
	randomize();
	a1=random(4);
	a2=random(4);
	b1=random(4);
	b2=random(4);

	if(a1==a2&&b1==b2)
	{
		if(b1==0)
		{b1=b1 + 1;}
		else
		{b1=b1 - 1;}
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{grid[i][j]=0;}
	}

	grid[a1][b1]=no_gen();
	grid[a2][b2]=no_gen();
}


void over()
{
	int f = 0;
	for(i = 0; i<=3; i++)
	{
		for(j = 0; j<=2; j++)
		{
			if(grid[j][i] == grid[j+1][i])
			{ f = 1;}
		}
	}

	for(i = 0; i<=3; i++)
	{
		for(j = 0; j<=2; j++)
		{
			if(grid[i][j] == grid[i][j+1])
			{ f = 1;}
		}
	}

	if(f == 0)
	{
		clrscr();
		cout<<"\n\n***************Game Over***************/n/n";
		display();
		getch();
		exit(0);
	}
}

void nos()
{
	short int a,b,rndm,k,free1[16],free2[16],count=0;
	start obj;
	for(k=0;k<16;k++)
	{
		free1[k] = 0;
		free2[k] = 0;
	}
	for(k=0;k<16;k++)
	{        count = 0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{

				if(grid[i][j] == 0)
				{
					++count;
					free1[k] = i;
					free2[k] = j;
				}

			}
		}
	}

	randomize();
	rndm = 0;
	rndm = random(count);
	a = free1[rndm];
	b = free2[rndm];
	grid[a][b] =obj.no_gen();
}


void up_move()
{
	for(i = 0; i<=3; i++)
	{
		int n = 0;
		for(j = 0; j<=3; j++)
		{
			if(grid[j][i] != 0)
			{ n++; }
		}


	int pos1 = 4 , pos2 = 4, pos3 = 4;

	if(n == 1)
	{
		for(j = 3; j>=1; j--)
		{
			if(grid[j][i] != 0)
			{
				grid[0][i] = grid[j][i];
				grid[j][i] = 0;
			}
		}
	}

	else if(n == 2)
	{
		for(j = 3; j>=0; j--)
		{
			if(grid[j][i] != 0)
			{
				if(pos1 == 4)
				{ pos1 = j ;}
				else
				{ pos2 = j; }
			}
		}
		if(grid[pos1][i] == grid[pos2][i])
		{
			grid[0][i] = grid[pos1][i] + grid[pos2][i];
			grid[pos1][i] = 0;
			if(pos2 != 0)
			{ grid[pos2][i] = 0;}
		}

		else
		{
			grid[0][i] = grid[pos2][i];
			grid[1][i] = grid[pos1][i];
			grid[2][i] = 0;
			grid[3][i] = 0;
		}
      }

	else if(n == 3)
	{
		for(j = 3; j>=0; j--)
		{
			if(grid[j][i] != 0)
			{
				if(pos1 == 4)
				{ pos1 = j;}

			else if(pos2 == 4)
			{ pos2 = j;}

			else
			{ pos3 = j;}
			}

		}

		if((grid[pos1][i] == grid[pos2][i])&&(grid[pos1][i] == grid[pos3][i]))
		{
			grid[0][i] = grid[pos2][i] + grid[pos3][i];
			grid[1][i] = grid[pos1][i];
			grid[2][i] = 0;
			grid[3][i] = 0;
		}

		else if((grid[pos1][i] != grid[pos2][i])&&(grid[pos2][i] != grid[pos3][i]))
		{
			grid[0][i] = grid[pos3][i];
			grid[1][i] = grid[pos2][i];
			grid[2][i] = grid[pos1][i];
			grid[3][i] = 0;
		}

		else if(grid[pos1][i] == grid[pos2][i])
		{
			grid[0][i] = grid[pos3][i];
			grid[1][i] = grid[pos2][i] +grid[pos1][i];
			grid[2][i] = 0;
			grid[3][i] = 0;
		}

		else if(grid[pos2][i] == grid[pos3][i])
		{
			grid[0][i] = grid[pos3][i] + grid[pos2][i];
			grid[1][i] = grid[pos1][i];
			grid[2][i] = 0;
			grid[3][i] = 0;
		}
      }

	else if( n == 4)
	{
		if((grid[0][i] == grid[1][i])&&(grid[2][i] == grid[3][i]))
		{
			grid[0][i] = grid[0][i] + grid[1][i];
			grid[1][i] = grid[2][i] + grid[3][i];
			grid[2][i] = 0;
			grid[3][i] = 0;
		}

		else if(((grid[0][i] != grid[1][i])&&(grid[1][i] != grid[2][i]))&&(grid[2][i] == grid[3][i]))
		{
			grid[0][i] = grid[0][i] ;
			grid[1][i] = grid[1][i] ;
			grid[2][i] = grid[2][i] + grid[3][i];
			grid[3][i] = 0;
		}

		else if(((grid[1][i] != grid[2][i])||(grid[2][i] != grid[3][i]))&&(grid[1][i] == grid[0][i]))
		{
			grid[0][i] = grid[0][i] + grid[1][i];
			grid[1][i] = grid[2][i] ;
			grid[2][i] = grid[3][i] ;
			grid[3][i] = 0;
		}

		else if((grid[2][i] == grid[1][i])&&(grid[0][i] != grid[1][i]))
		{
			grid[0][i] = grid[0][i] ;
			grid[1][i] = grid[2][i] + grid[1][i] ;
			grid[2][i] = grid[3][i] ;
			grid[3][i] = 0;
		}

		else if((grid[2][i] != grid[1][i])&&((grid[0][i] != grid[1][i])&&(grid[2][i] != grid[3][i])))
		{
			grid[0][i] = grid[0][i];
			grid[1][i] = grid[1][i];
			grid[2][i] = grid[2][i];
			grid[3][i] = grid[3][i];
		}


	}

	}

}

void up()
{
	int flag=0;

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			vrtual[i][j]=grid[i][j];
		}
	}

	up_move();

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(vrtual[i][j]==grid[i][j])
			{ flag += 1;}
			else
			continue;
		}
	}

	if(flag!=16)
	{
		nos();
		clrscr();
		display();
	}
	else
	{
		clrscr();
		display();
	}

	over();
}

void down_move()
{
	for(i = 0; i<=3; i++)
	{
		int n = 0;
		for(j = 0; j<=3; j++)
		{
			if(grid[j][i] != 0)
			{ n++; }
		}

	int pos1 = 4 , pos2 = 4, pos3 = 4;
	if(n == 1)
	{
		for(j = 0; j<=2; j++)
		{
			if(grid[j][i] != 0)
			{
				grid[3][i] = grid[j][i];
				grid[j][i] = 0;
			}
		}
	}

	else if(n == 2)
	{
		for(j = 0; j<=3; j++)
		{
			if(grid[j][i] != 0)
			{
				if(pos1 == 4)
				{ pos1 = j ;}
				else
				{ pos2 = j; }
			}
		}

		if(grid[pos1][i] == grid[pos2][i])
		{
			grid[3][i] = grid[pos1][i] + grid[pos2][i];
			grid[pos1][i] = 0;

			if(pos2 != 3)
			{
				grid[pos2][i] = 0;}
			}
			else
			{
				grid[3][i] = grid[pos2][i];
				grid[2][i] = grid[pos1][i];
				grid[1][i] = 0;
				grid[0][i] = 0;
			}
		}

		else if(n == 3)
		{
			for(j = 0; j<=3; j++)
			{
				if(grid[j][i] != 0)
				{
					if(pos1 == 4)
					{ pos1 = j;}
					else if(pos2 == 4)
					{ pos2 = j;}
					else
					{ pos3 = j;}
				}
			}

			if((grid[pos1][i] == grid[pos2][i])&&(grid[pos1][i] == grid[pos3][i]))
			{
				grid[3][i] = grid[pos2][i] + grid[pos3][i];
				grid[2][i] = grid[pos1][i];
				grid[1][i] = 0;
				grid[0][i] = 0;
			}

			else if((grid[pos1][i] != grid[pos2][i])&&(grid[pos2][i] != grid[pos3][i]))
			{
				grid[3][i] = grid[pos3][i];
				grid[2][i] = grid[pos2][i];
				grid[1][i] = grid[pos1][i];
				grid[0][i] = 0;
			}

			else if(grid[pos1][i] == grid[pos2][i])
			{
				grid[3][i] = grid[pos3][i];
				grid[2][i] = grid[pos2][i] +grid[pos1][i];
				grid[1][i] = 0;
				grid[0][i] = 0;
			}

			else if(grid[pos2][i] == grid[pos3][i])
			{
				grid[3][i] = grid[pos3][i] + grid[pos2][i];
				grid[2][i] = grid[pos1][i];
				grid[1][i] = 0;
				grid[0][i] = 0;
			}
	}

	else if( n == 4)
	{
		if((grid[0][i] == grid[1][i])&&(grid[2][i] == grid[3][i]))
		{
			grid[3][i] = grid[3][i] + grid[2][i];
			grid[2][i] = grid[0][i] + grid[1][i];
			grid[1][i] = 0;
			grid[0][i] = 0;
		}

		else if((grid[3][i] == grid[2][i])&&(grid[1][i] != grid[0][i]))
		{
			grid[3][i] = grid[3][i] + grid[2][i];
			grid[2][i] = grid[1][i] ;
			grid[1][i] = grid[0][i] ;
			grid[0][i] = 0;
		}

		else if(((grid[3][i] != grid[2][i])&&(grid[1][i] == grid[0][i]))&&(grid[1][i] != grid[2][i]))
		{
			grid[3][i] = grid[3][i] ;
			grid[2][i] = grid[2][i] ;
			grid[1][i] = grid[1][i] + grid[0][i];
			grid[0][i] = 0;
		}

		else if((grid[2][i] == grid[1][i])&&(grid[2][i] != grid[3][i]))
		{
			grid[3][i] = grid[3][i] ;
			grid[2][i] = grid[2][i] + grid[1][i] ;
			grid[1][i] = grid[0][i] ;
			grid[0][i] = 0;
		}

		else if((grid[2][i] != grid[1][i])&&((grid[0][i] != grid[1][i])&&(grid[2][i] != grid[3][i])))
		{
			grid[0][i] = grid[0][i];
			grid[1][i] = grid[1][i];
			grid[2][i] = grid[2][i];
			grid[3][i] = grid[3][i];
		}


		}
	 }
}

void down()
{
	int flag=0;

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			vrtual[i][j]=grid[i][j];
		}
	}

	down_move();

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(vrtual[i][j]==grid[i][j])
			{ flag += 1;}
			else
			continue;
		}
	}

	if(flag!=16)
	{
		nos();
		clrscr();
		display();
	}
	else
	{
		clrscr();
		display();
	}

	over();
}

void right_move()
{
	for(i = 0; i<=3; i++)
	{
		int n = 0;
		for(j = 0; j<=3; j++)
		{
			if(grid[i][j] != 0)
			{ n++; }
		}

	int pos1 = 4 , pos2 = 4, pos3 = 4;
	if(n == 1)
	{
		for(j = 0; j<=2; j++)
		{
			if(grid[i][j] != 0)
			{
				grid[i][3] = grid[i][j];
				grid[i][j] = 0;
			}
		}
	}
	else if(n == 2)
	{
		for(j = 0; j<=3; j++)
		{
			if(grid[i][j] != 0)
			{
				if(pos1 == 4)
				{ pos1 = j ;}
				else
				{ pos2 = j; }
			}
		}
	
		if(grid[i][pos1] == grid[i][pos2])
	 	{ 
			grid[i][3] = grid[i][pos1] + grid[i][pos2];
	   		grid[i][pos1] = 0;
	    		if(pos2 != 3)
	     		{ 
				grid[i][pos2] = 0;}
	  		}
			else
	  		{ 
				grid[i][3] = grid[i][pos2];
	    			grid[i][2] = grid[i][pos1];
	    			grid[i][1] = 0;
	    			grid[i][0] = 0;
	  		}
      		}
     
		else if(n == 3)
     		{   
			for(j = 0; j<=3; j++)
	   		{ 
				if(grid[i][j] != 0)
	      			{ 
					if(pos1 == 4)
		 			{ pos1 = j;}
	       				else if(pos2 == 4)
		     			{ pos2 = j;}
	       				else
		   			{ pos3 = j;}
	       			}
	   		}
	 
			if((grid[i][pos1] == grid[i][pos2])&&(grid[i][pos1] == grid[i][pos3]))
	  		{ 
				grid[i][3] = grid[i][pos2] + grid[i][pos3];
	    			grid[i][2] = grid[i][pos1];
	    			grid[i][1] = 0;
	    			grid[i][0] = 0;
	  		}
	 
			else if((grid[i][pos1] != grid[i][pos2])&&(grid[i][pos2] != grid[i][pos3]))
	       		{ 
				grid[i][3] = grid[i][pos3];
		 		grid[i][2] = grid[i][pos2];
		 		grid[i][1] = grid[i][pos1];
		 		grid[i][0] = 0;
	       		}
	       
			else if(grid[i][pos1] == grid[i][pos2])
		     	{  
				grid[i][3] = grid[i][pos3];
				grid[i][2] = grid[i][pos2] +grid[i][pos1];
				grid[i][1] = 0;
				grid[i][0] = 0;
		     	}
		    
			else if(grid[i][pos2] == grid[i][pos3])
			{  
				grid[i][3] = grid[i][pos3] + grid[i][pos2];
			      	grid[i][2] = grid[i][pos1];
			      	grid[i][1] = 0;
			      	grid[i][0] = 0;
			}
      	}
       
	else if( n == 4)
	{ 
		if((grid[i][0] == grid[i][1])&&(grid[i][2] == grid[i][3]))
		{   
			grid[i][3] = grid[i][3] + grid[i][2];
		      	grid[i][2] = grid[i][0] + grid[i][1];
		      	grid[i][1] = 0;
		      	grid[i][0] = 0;
		}
		   
		else if((grid[i][3] == grid[i][2])&&(grid[i][1] != grid[i][0]))
		{  
			grid[i][3] = grid[i][3] + grid[i][2];
			grid[i][2] = grid[i][1] ;
			grid[i][1] = grid[i][0] ;
			grid[i][0] = 0;
		}
			 
		else if(((grid[i][3] != grid[i][2])&&(grid[i][1] == grid[i][0]))&&(grid[i][1] != grid[i][2]))
		{  
			grid[i][3] = grid[i][3] ;
			grid[i][2] = grid[i][2] ;
			grid[i][1] = grid[i][1] + grid[i][0];
			grid[i][0] = 0;
		}
			       
		else if((grid[i][2] == grid[i][1])&&(grid[i][2] != grid[i][3]))
		{   
			grid[i][3] = grid[i][3] ;
			grid[i][2] = grid[i][2] + grid[i][1] ;
			grid[i][1] = grid[i][0] ;
			grid[i][0] = 0;
		}
				      
		else if((grid[i][2] != grid[i][1])&&((grid[i][0] != grid[i][1])&&(grid[i][2] != grid[i][3])))
		{
			grid[i][0] = grid[i][0];
			grid[i][1] = grid[i][1];
			grid[i][2] = grid[i][2];
			grid[i][3] = grid[i][3];
		}


		}
 	}
}

void right()
{
	int flag=0;

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			vrtual[i][j]=grid[i][j];
		}
	}

	right_move();

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(vrtual[i][j]==grid[i][j])
			{ flag += 1;}
			else
			continue;
		}
	}

	if(flag!=16)
	{
		nos();
		clrscr();
		display();
	}
	else
	{
		clrscr();
		display();
	}

	over();
}

void left_move()
{ 
	for(i = 0; i<=3; i++)
  	{
		int n = 0;
   		for(j = 0; j<=3; j++)
    		{  
			if(grid[i][j] != 0)
	 		{ n++; }
    		}
    
	int pos1 = 4 , pos2 = 4, pos3 = 4;
    	if(n == 1)
     	{ 
		for(j = 3; j>=1; j--)
		{
			if(grid[i][j] != 0)
	  		{
				grid[i][0] = grid[i][j];
	    			grid[i][j] = 0;
	  		}
	 	}
     	}
    
	else if(n == 2)
     	{ 
		for(j = 3; j>=0; j--)
		{  
			if(grid[i][j] != 0)
	    		{ 
				if(pos1 == 4)
				{ pos1 = j ;}
	      			else
				{ pos2 = j; }
	     		}
	 	}
	
	if(grid[i][pos1] == grid[i][pos2])
	{
		grid[i][0] = grid[i][pos1] + grid[i][pos2];
		grid[i][pos1] = 0;

		if(pos2 != 0)
		{ grid[i][pos2] = 0;}
	}
	else
	{
		grid[i][0] = grid[i][pos2];
		grid[i][1] = grid[i][pos1];
		grid[i][2] = 0;
		grid[i][3] = 0;
	}
      }
     
	else if(n == 3)
     	{   
		for(j = 3; j>=0; j--)
	   	{ 
			if(grid[i][j] != 0)
	      		{ 
				if(pos1 == 4)
		 		{ pos1 = j;}
	       			else if(pos2 == 4)
		     		{ pos2 = j;}
		     		else
				{ pos3 = j;}
	       		}
	   	}
	 
	if((grid[i][pos1] == grid[i][pos2])&&(grid[i][pos1] == grid[i][pos3]))
	{ 
			grid[i][0] = grid[i][pos2] + grid[i][pos3];
	    		grid[i][1] = grid[i][pos1];
	    		grid[i][2] = 0;
	    		grid[i][3] = 0;
	}
	 
	else if((grid[i][pos1] != grid[i][pos2])&&(grid[i][pos2] != grid[i][pos3]))
	{ 
		grid[i][0] = grid[i][pos3];
		grid[i][1] = grid[i][pos2];
		grid[i][2] = grid[i][pos1];
		grid[i][3] = 0;
	}
	       
	else if(grid[i][pos1] == grid[i][pos2])
	{  
		grid[i][0] = grid[i][pos3];
		grid[i][1] = grid[i][pos2] +grid[i][pos1];
		grid[i][2] = 0;
		grid[i][3] = 0;
	}
		    
	else if(grid[i][pos2] == grid[i][pos3])
	{  
		grid[i][0] = grid[i][pos3] + grid[i][pos2];
		grid[i][1] = grid[i][pos1];
		grid[i][2] = 0;
		grid[i][3] = 0;
	}
      }
       
	else if( n == 4)
	{ 
		if((grid[i][0] == grid[i][1])&&(grid[i][2] == grid[i][3]))
		{   
			grid[i][0] = grid[i][0] + grid[i][1];
		      	grid[i][1] = grid[i][2] + grid[i][3];
		      	grid[i][2] = 0;
		      	grid[i][3] = 0;
		}
		   
		else if(((grid[i][0] != grid[i][1])&&(grid[i][1] != grid[i][2]))&&(grid[i][2] == grid[i][3]))
		{  
			grid[i][0] = grid[i][0] ;
			grid[i][1] = grid[i][1] ;
			grid[i][2] = grid[i][2] + grid[i][3];
			grid[i][3] = 0;
		}
			 
		else if(((grid[i][1] != grid[i][2])||(grid[i][2] != grid[i][3]))&&(grid[i][1] == grid[i][0]))
		{  
			grid[i][0] = grid[i][0] + grid[i][1];
			grid[i][1] = grid[i][2] ;
			grid[i][2] = grid[i][3] ;
			grid[i][3] = 0;
		}
			       
		else if((grid[i][2] == grid[i][1])&&(grid[i][0] != grid[i][1]))
		{   
			grid[i][0] = grid[i][0] ;
			grid[i][1] = grid[i][2] + grid[i][1] ;
			grid[i][2] = grid[i][3] ;
			grid[i][3] = 0;
		}
				      
		else if((grid[i][2] != grid[i][1])&&((grid[i][0] != grid[i][1])&&(grid[i][2] != grid[i][3])))
		{
			grid[i][0] = grid[i][0];
			grid[i][1] = grid[i][1];
			grid[i][2] = grid[i][2];
			grid[i][3] = grid[i][3];
		}


		}
	}
}

void left()
{
	int flag=0;

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			vrtual[i][j]=grid[i][j];
		}
	}
	left_move();

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(vrtual[i][j]==grid[i][j])
			{ flag += 1;}
			else
			continue;
		}

	}

	if(flag!=16)
	{
		nos();
		clrscr();
		display();
	}
	else
	{
		clrscr();
		display();
	}

	over();
}

void undo()
{
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			grid[i][j] = vrtual[i][j];
		}
	}

	display();
}

void main()
{
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\tWELCOME TO 2048";
	cout<<"\n\n\n\t\tUse the following keys to process the game\n\ns - down\n\nw - up\n\nd - right\n\na - left\n\nu - undo\n\nq - quit";
	sleep(10);
	start call;
	call.pos();
	char in;
	for(;;)
	{       display();
		cout<<"\n\n\t\tEnter The Move : ";
		cin>>in;

		switch(in)
		{
			case 's' : {clrscr();down();break;}

			case 'w' : {clrscr();up();break;}

			case 'a' : {clrscr();left();break;}

			case 'd' : {clrscr();right();break;}

			case 'u' : {clrscr();undo();break;}

			case 'q' : exit(0);

			default  : {continue;clrscr();}
		}

	}

}


