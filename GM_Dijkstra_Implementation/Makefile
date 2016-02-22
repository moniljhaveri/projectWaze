main: main.o Node.o Load.o Dijkstra.o SmoothsortPriorityQueue.o
	g++ -std=c++1y main.o Node.o Load.o Dijkstra.o SmoothsortPriorityQueue.o -o main

main.o: main.cpp Node.h SmoothsortPriorityQueue.h 
	g++ -std=c++1y -c main.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++1y -c Node.cpp
	
Load.o: Load.cpp Load.h
	g++ -std=c++1y -c Load.cpp
	
SmoothsortPriorityQueue.o: SmoothsortPriorityQueue.cpp SmoothsortPriorityQueue.h Node.h
	g++ -std=c++1y -c SmoothsortPriorityQueue.cpp
	
Dijkstra.o: Dijkstra.cpp Node.h SmoothsortPriorityQueue.h
	g++ -std=c++1y -c Dijkstra.cpp

clean:
	rm *.o main