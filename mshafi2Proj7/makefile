mshafi2Proj7:  mshafi2Proj7.cpp Creature.o Island.o Ant.o DoodleBug.o GridDisplay.o
	g++ -o mshafi2Proj7 mshafi2Proj7.cpp Creature.o Island.o Ant.o DoodleBug.o GridDisplay.o

Creature.o: Creature.cpp Creature.h Island.h DoodleBug.h Enums.h
	g++ -c Creature.cpp
	
Island.o: Island.cpp Island.h GridDisplay.h Creature.h Ant.h DoodleBug.h
	g++ -c Island.cpp
	

	
Ant.o: Ant.cpp Ant.h Creature.h Enums.h
	g++ -c Ant.cpp
	
DoodleBug.o: DoodleBug.cpp DoodleBug.h Creature.h
	g++ -c DoodleBug.cpp
	
GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -c GridDisplay.cpp

clean:
	rm -f *.o mshafi2Proj7
