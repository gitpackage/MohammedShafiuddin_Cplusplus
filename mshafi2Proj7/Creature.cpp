#include <stdio.h>
#include "Creature.h"
#include "Island.h"
#include "DoodleBug.h"
#include "Ant.h"

Creature::Creature(bool isant, Island* island, int i) {
			isAnt = isant;
			isl = island;
			index = i;
			daysElapsed = 0;
		}

		bool Creature::getIsAnt() {
			return isAnt;
		}

		void Creature::setLocation(int r, int c) {
			row = r;
			col = c;
		}

	Creature* Creature::spawn(int maxDays, int openArrayPosition) {

		if(daysElapsed >= maxDays){
			//printf("\n\nDAY %dn\n", maxDays);
			Creature* babyCreature;
			if(isAnt){
			 	babyCreature = new Ant(isl, openArrayPosition);
			}
			else{
				babyCreature = new DoodleBug(isl, openArrayPosition);
			}

			if(isl->isValid( row-1, col) && !(isl->isOccupied(row-1, col))){
				//DOWN
				isl->insertNewCreature(babyCreature, row-1, col);
				daysElapsed = 0;

			} else if (isl->isValid(row+1, col) && !(isl->isOccupied(row+1, col))){
				//UP
				isl->insertNewCreature(babyCreature, row+1, col);
				daysElapsed = 0;
			}
			else if (isl->isValid(row, col-1) && !(isl->isOccupied(row, col-1))){
				//LEFT
				isl->insertNewCreature(babyCreature, row, col-1);
				daysElapsed = 0;
			}
			else if (isl->isValid(row, col+1) && !(isl->isOccupied(row, col+1))){
				//RIGHT
				isl->insertNewCreature(babyCreature, row, col+1);
				daysElapsed = 0;
			}else{
				delete babyCreature;
				babyCreature = NULL;
			}
			
			
			return babyCreature;
		}

	}
	
	void Creature::move() {
		int nextX = -999;
		int nextY = -999;

		int direction = rand() % (4);

		if(direction == UP){
			//	printf("\n\nUP = %d\n\n", direction);
				nextX = row-1;
				nextY = col;
		} else if(direction == DOWN) {
			//	printf("\n\nDOWN = %d\n\n", direction);
				nextX = row+1;
				nextY = col;
		} else if(direction == LEFT) {
			//	printf("\n\nLEFT = %d\n\n", direction);
				nextX = row;
				nextY = col-1;
		} else if(direction == RIGHT) {
			//printf("\n\nRIGHT = %d\n\n", direction);
			nextX = row;
			nextY = col+1;
		}

		isl->moveCreature(row, col, nextX, nextY);
	}


	void Creature::incrementDaysElapsed() {
		daysElapsed++;
	}
	
	int Creature::getXLocation() {
		return row;
	}
	
	int Creature::getYLocation() {
		return col;
	}
	
	void Creature::setIndex(int newIndex){
		index = newIndex;
	}
	
	int Creature::getIndex(){
		return index;
	}
