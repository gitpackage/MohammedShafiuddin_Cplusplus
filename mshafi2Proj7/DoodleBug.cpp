#include <stdio.h>
#include "DoodleBug.h"
#include "Creature.h"

	DoodleBug::DoodleBug (Island* island, int index) : Creature::Creature(false, island, index) {
		daysSinceEaten = 0;
	}
	
	bool DoodleBug::starve() {
		if(daysSinceEaten > 3){
		//	printf("\n\n I STARVED");
			isl->removeCreature(this);
			return true;
		}
		
		return false;
	}
	
	
	int DoodleBug::hunt(){
		int killedIndex = -1;
	//	printf("\n\nChecking adjacent");
		Ant* killAnt = isl->checkAdjacentAnt(this);
		
		if(killAnt != NULL)	{
		//	printf("\n\n EATING ANT...\n\n");
			killedIndex = killAnt->getIndex();
			isl->eatAnt(killAnt, this);
			daysSinceEaten = 0;
		}else{
		//	printf("\n\n ANT IS NULL...\n\n");
			daysSinceEaten ++;
			
			//Try to move adjacently
			move();
		}
		
		return killedIndex;
	}
	
	void DoodleBug::setDaysSinceEaten(int days){
		daysSinceEaten = days;
	}
		
		
		


