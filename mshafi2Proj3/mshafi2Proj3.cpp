/*This program is for class CS 211, about a maze visitation
Author: Mohammed Shafiuddin
NetId: mshafi
*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;

typedef struct mazeStruct
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
{

char arr[32][32]; /* array of 30 by 30 size plus the walls around it. */

//setting up variables for size, start and end positons.
int xsize, ysize;

int xstart, ystart;

int xend, yend;

} maze;
//----------------------------------------------------------------------------
void readMaze ( maze & m1 )

{

int xpos, ypos;

int i,j, argc;

   ifstream is;

   cout << "Enter the name of a data file with .txt extension: ";

   char fname2[80];

   cin >> fname2;

   is.open (fname2, ios::in);
  
   if ( is.fail() )

     {

      fprintf(stderr, " The name given did not match that of a valid file \n");
     
      exit (-1);   // exit with error message, when entered command is not valid

     }

/* reads size, starting and ending positions of the maze */

is >> m1.xsize >> m1.ysize;
is >> m1.xstart >> m1.ystart;
is >> m1.xend >> m1.yend;

	
	printf("Size:  %i %i\n", m1.xsize, m1.ysize);
	printf("Start: %i %i \n", m1.xstart, m1.ystart);
	printf("end: %i %i\n", m1.xend , m1.yend); 
	
	
	if(m1.ysize<1 || m1.ysize >7){
		printf(" %i %i", m1.xsize, m1.ysize);
		printf("   => Invalid: Maze sizes must be greater than 0 \n", m1.ysize);
	}
	
	if(m1.xstart >9 && m1.ystart <10 ){
		printf(" %i %i ", m1.xstart, m1.ystart );
		printf("  => Maze becomes size %i x %i\n", m1.xstart, m1.ystart);
	}
     
     for(i=0; i<m1.xend; i++){
     	if(m1.ysize >0)
     printf("ysize is: %i\n", m1.ysize);
 }
	  
	   	if(m1.arr[m1.xsize>15]){
    	printf("%i %i", m1.xstart, m1.ysize);
    	printf("   => Invalid: row %i is outside range from 1 to 15 \n", *m1.arr[m1.xsize]+m1.xstart);
	 } 
   	
/* initializes the maze to empty */

for (i = 0; i < m1.xsize+2; i++)

     for (j = 0; j < m1.ysize+2; j++)

       m1.arr[i][j] = '.';
       

/* Borders of the maze is marked with *'s */

for (i=0; i < m1.xsize+2; i++)

    {

     m1.arr[i][0] = '*';

     m1.arr[i][m1.ysize+1] = '*';

    }

for (i=0; i < m1.ysize+2; i++)

    {

     m1.arr[0][i] = '*';

     m1.arr[m1.xsize+1][i] = '*';

    }
    
   

/* starting and ending position are marked in the maze */

m1.arr[m1.xstart][m1.ystart] = 's';

m1.arr[m1.xend][m1.yend] = 'e';


is >> xpos >> ypos;

	printf("%i %i", xpos, ypos);
	printf("    => Starting position is at position %i , %i\n", xpos, ypos);	
	
while ( ! is.eof() )

    {

     m1.arr[xpos][ypos] = '*';

     is >> xpos >> ypos;
	}
 	  	 
	printf("%i %i", xpos, ypos);
	printf("    => Ending position is at position %i , %i\n", xpos, ypos);	

}

	
//--------------------------------------------------------------------------
int main (int argc, char **argv)

{

maze m1;

readMaze ( m1 );

int xpos, ypos;

int i,j;

/* print out the initial maze */

for (i = 0; i < m1.xsize+2; i++)

    {

     for (j = 0; j < m1.ysize+2; j++)

       printf ("%c", m1.arr[i][j]);
       printf("\n");

    }
    
    if(m1.arr[j>7]){
    	printf("%i %i", m1.xend, m1.yend);
    printf("   => Invalid: column %i is outside range from 1 to 7 \n", m1.yend);
	 }


}
//end of program
