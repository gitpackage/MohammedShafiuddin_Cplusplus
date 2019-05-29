#ifndef ISLAND_H
#define ISLAND_H

class Creature;
class GridDisplay;
class Ant;
class DoodleBug;

class Island {
	private:
	int rows;
	int cols;
	Creature* **board;
	GridDisplay* gridDisplay;

	public:

	Island();

    bool isValid (int r, int c);

    bool isOccupied (int r, int c);
    
    bool isOccupiedAnt (int r, int c);

    bool moveCreature (int currX, int currY, int nextX, int nextY);

    void insertCreature(Creature* creature);
    
    void removeCreature(Creature* creature);

    void insertNewCreature(Creature* creature, int row, int col);

    void showGrid();

    void sleep(int milliseconds);
    
    Ant* checkAdjacentAnt(DoodleBug* bug);
    
    void eatAnt(Ant* killAnt, DoodleBug* bug);

};

#endif
