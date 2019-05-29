#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include "GridDisplay.cpp"
#include "Island.cpp"
#include "Ant.cpp"
#include "Creature.cpp"
#include "DoodleBug.cpp"

void increaseSizeOfBugArray(DoodleBug** *creatures, int* oldSize) {
//	printf("\n\nINCREASED SIZE OF ARRAY to %d", *oldSize + 50);
	
	DoodleBug** biggerArray = new DoodleBug*[*oldSize + 50];
	
	for(int i = 0; i<(*oldSize); i++){
		biggerArray[i] = (*creatures)[i];
	}
	
	free(*creatures);
	
	(*creatures) = biggerArray;
	*oldSize += 50;
}

void increaseSizeOfAntArray(Ant** *creatures, int* oldSize) {
//	printf("\n\nINCREASED SIZE OF ARRAY to %d", *oldSize + 50);
	
	Ant** biggerArray = new Ant*[*oldSize + 50];
	
	for(int i = 0; i<(*oldSize); i++){
		biggerArray[i] = (*creatures)[i];
	}
	
	free(*creatures);
	
	(*creatures) = biggerArray;
	*oldSize += 50;
}

int main(int argx, char** argv) {
	int sleepTime = 1000;
	
	//Check for debug mode -d flag
	int i;
	for(i = 0; i< argx; i++)
	{
		if(strcmp(argv[i], "-d") == 0)
		{
			sleepTime = atoi(argv[i+1]);
			printf("\n\n -d FLAG ENTERED, sleep Time = %d\n\n", sleepTime);
		}
	}
	
	
	
	srand(time(NULL));
	int day = 0;
	int bugCount = 5;
	int openBugPosition = 5;
	int openAntPosition = 100;
	int antCount = 100;

	Island* island = new Island();
	
	Ant** ants = new Ant*[antCount];
	DoodleBug** bugs = new DoodleBug*[bugCount];
 	
 	for (int i = 0 ; i < antCount ; i++){
   		ants[i] = new Ant(island, i);
   		island->insertCreature(ants[i]);
   	}
 	
	for (int i = 0 ; i < bugCount ; i++){
   		bugs[i] = new DoodleBug(island, i);
   		island->insertCreature(bugs[i]);
   	}

   	
//  	
//   	printf("\n\n New size of bugcount = %d, emptySpot = %d", bugCount, openBugPosition);
//   	
//   	for(int i = 0; i<bugCount; i ++){
//   		printf("\n\nBug %d: %s", i, (bugs[i] == NULL ? "EMPTY" : "EXISTS"));
//	}

   // show the initial locations of the creatures
 	island->showGrid();

	 // loop forever
	 while ( true )
	 {
	    day++;
	
	    //DoodleBug's turn
	    for (int i = 0 ; i < bugCount ; i++)
	    {
	    	if(bugs[i] != NULL){
	    		int killedAntIndex = bugs[i]->hunt();
	    		
	    		if( killedAntIndex != -1){
	    			
	    			ants[killedAntIndex] = NULL;
		       		ants[killedAntIndex] = ants[openAntPosition -1];
		       		ants[openAntPosition -1] = NULL;
		       		if(ants[killedAntIndex] != NULL){
	       				ants[killedAntIndex]->setIndex(killedAntIndex);
					}
		       		
		       		openAntPosition --;
	       	
				}
	       

	       //SPAWN
	       DoodleBug* newBug = (DoodleBug*)bugs[i]->spawn(8, openBugPosition);
	       if(newBug != NULL){
	       		
	       		if(openBugPosition >= bugCount){
	       			increaseSizeOfBugArray(&bugs, &bugCount);
				}
	       	
	       		bugs[openBugPosition] = newBug;
	       		openBugPosition ++;
		   }
	       
	       //STARVE
	       if(bugs[i]->starve()){
	       		bugs[i] = NULL;
	       		bugs[i] = bugs[openBugPosition -1];
	       		bugs[openBugPosition -1] = NULL;
	       		
	       		if(bugs[i] != NULL){
	       			bugs[i]->setIndex(i);
				}
	       		
	       		openBugPosition --;
	       		i--;
		  	 }
			}
	    }
	    
	    //Ant's turn
	    for (int i = 0 ; i < antCount ; i++)
	    {
	    //	printf("\n\nAnt i: %d", i);
	    	//MOVE
	    	if(ants[i] != NULL){
	    	//	printf("\nindexArray: %d, locationX = %d, locationY = %d",ants[i]->getIndex(), ants[i]->getXLocation(), ants[i]->getYLocation());
	    		ants[i]->move();

				//SPAWN
		       Ant* newAnt = (Ant*)ants[i]->spawn(3, openAntPosition);
		       if(newAnt != NULL){
		       		
		       		if(openAntPosition >= antCount){
		       			increaseSizeOfAntArray(&ants, &antCount);
					}
		       	
		       		ants[openAntPosition] = newAnt;
		       		openAntPosition ++;
			   }
			}
	       
	    }
	
	    // pause execution to allow "animation" to be seen
	    island->showGrid();
	    printf("\n\nDAY %d\n\n", day);
	    island->sleep( sleepTime );
	    
	 }
		
	
	

	return 0;
}

