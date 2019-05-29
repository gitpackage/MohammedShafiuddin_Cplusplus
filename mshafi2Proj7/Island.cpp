#include "Island.h"
#include "GridDisplay.h"
#include "Creature.h"
#include "Ant.h"
#include "DoodleBug.h"

	Island::Island() {
		rows = 20;
		cols = 20;

 		board = new Creature**[rows];
		gridDisplay = new GridDisplay();

		for ( int i = 0 ; i < rows ; i++ )
	    {
	       board[i] = new Creature*[cols];
	       for ( int j = 0 ; j < cols ; j++ )
	       {
	          board[i][j] = NULL;
	       }
	    }
	}

	 bool Island::isValid (int r, int c)
   {
    if (( r >= 0 && r < rows ) && ( c >= 0 && c < cols))
      return true;
    else
      return false;
   }

   bool Island::isOccupied (int r, int c)
   {
    if ( board[r][c] == NULL )
      return false;
    else
      return true;
   }
   
   bool Island::isOccupiedAnt(int r, int c) {
   		return board[r][c] != NULL && board[r][c]->getIsAnt();
   }

	bool Island::moveCreature (int currX, int currY, int nextX, int nextY)
   {
   //	printf("\n\nChecking x:%d, y:%d", nextX, nextY);
   	
   //	showGrid();
   	

    if ( isValid (nextX, nextY) == false )
      return false;

    if ( isOccupied (nextX, nextY) == true)
      return false;
      
    //printf("\n\nSUCCESS");

    board[nextX][nextY] = board[currX][currY];
    board[currX][currY] = NULL;
    gridDisplay->setChar (currX, currY, '.');
    
    board[nextX][nextY]->setLocation(nextX, nextY);

    if(board[nextX][nextY]->getIsAnt() == true){
    	gridDisplay->setChar (nextX, nextY, 'A');
	}else {
		gridDisplay->setChar (nextX, nextY, 'D');
	}

    return true;
   }

   void Island::insertCreature(Creature* creature) {
   		int nextX;
   		int nextY;

   		nextX = rand() % rows;
   		nextY = rand() % cols;

   		

   		while(isOccupied(nextX, nextY)) {
   			nextX = rand() % rows;
   			nextY = rand() % cols;
		}
		
	//	printf("\n\nnextX = %d, nextY = %d\n\n", nextX, nextY);

		board[nextX][nextY] = creature;

		if(creature->getIsAnt()){
			gridDisplay->setChar(nextX, nextY, 'A');
		}
		else {
			gridDisplay->setChar(nextX, nextY, 'D');
		}

		creature->setLocation(nextX, nextY);
   }

   void Island::insertNewCreature(Creature* creature, int row, int col) {
		board[row][col] = creature;

		if(creature->getIsAnt()){
			gridDisplay->setChar(row, col, 'A');
		}
		else {
			gridDisplay->setChar(row, col, 'D');
		}
		
		creature->setLocation(row, col);
   }

   void Island::showGrid() {
   	 gridDisplay->showGrid();
   }

   void Island::sleep(int milliseconds) {
   	gridDisplay->mySleep(milliseconds);
   }
   
   void Island::removeCreature(Creature* creature) {
   	    int creatureX = creature->getXLocation();
   	    int creatureY = creature->getYLocation();
   	    
   		board[creatureX][creatureY] = NULL;

		gridDisplay->setChar(creatureX, creatureY, '.');
		
		delete creature;
   }
   
   
   Ant* Island::checkAdjacentAnt(DoodleBug* bug){
   		int row = bug->getXLocation();
   		int col = bug->getYLocation();
   	
   		//printf("\n\n Got bug location");
   		if(Island::isValid(row-1, col) && Island::isOccupiedAnt(row-1, col)){
				//UP
			//	printf("\n\n UP");
				return (Ant*)board[row-1][col];
		} else if(Island::isValid(row+1, col) && Island::isOccupiedAnt(row+1, col)){
				//DOWN
			//	printf("\n\n down");
				return (Ant*)board[row+1][col];
		} else if(Island::isValid(row, col-1) && Island::isOccupiedAnt(row, col-1)){
				//LEFT
			//	printf("\n\n left");
				return (Ant*)board[row][col-1];
		} else if(Island::isValid(row, col+1) && Island::isOccupiedAnt(row, col+1)){
				//RIGHT
			//	printf("\n\n right");
				return (Ant*)board[row][col+1];
		}else {
		//	printf("\n\n null");
			return NULL;
		}
   }
   
   
   void Island::eatAnt(Ant* killAnt, DoodleBug* bug){
   		int insertX = killAnt->getXLocation();
   		int insertY = killAnt->getYLocation();
   		
   		Island::removeCreature(killAnt);
   		
   		//1 reset bug spot in board to null
   		//2 reset bug spot in gridDisplay
   		board[bug->getXLocation()][bug->getYLocation()] = NULL;
   		gridDisplay->setChar(bug->getXLocation(), bug->getYLocation(), '.');
		   
		//3 move bug to insertX and Y location in board
   		//4 and in gridDisplay
   		board[insertX][insertY] = bug;
   		gridDisplay->setChar(insertX, insertY, 'D');
   		
   		//5 update location inside bug
   		bug->setLocation(insertX, insertY);
   }

