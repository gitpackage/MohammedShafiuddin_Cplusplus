#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Creature.h"
class Island;

class DoodleBug: public Creature{
	private:
	int daysSinceEaten;

	public:
	DoodleBug (Island* island, int index);
	bool starve();
	int hunt();
	
	void setDaysSinceEaten(int days);


};

#endif
