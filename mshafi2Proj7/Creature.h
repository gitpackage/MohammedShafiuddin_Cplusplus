#ifndef CREATURE_H
#define CREATURE_H

#include "Enums.h"
#include <stdio.h>
#include <stdlib.h>
class Island;

class Creature {
	protected:
	int row;
	int col;
	Island* isl;
	int daysElapsed;

	private:
	bool isAnt;
	int index;

	public:

		Creature(bool isant, Island* island, int index);

		bool getIsAnt();

		void setLocation(int r, int c);
		Creature* spawn(int maxDays, int openArrayPosition);
		void move();
		
		int getXLocation();
		int getYLocation();
		void setIndex(int newIndex);
		int getIndex();


	void incrementDaysElapsed();

};

#endif
