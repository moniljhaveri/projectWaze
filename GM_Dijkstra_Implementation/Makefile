
main: main.o Node.o Load.o Dijkstra.o Astar.o Yen.o k_paths.o SmoothsortPriorityQueue.o
	g++ -std=c++1y main.o Node.o Load.o Dijkstra.o Astar.o Yen.o k_paths.o SmoothsortPriorityQueue.o -o main

main.o: main.cpp Node.h SmoothsortPriorityQueue.h
	g++ -std=c++1y -c main.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++1y -c Node.cpp

Load.o: Load.cpp Load.h
	g++ -std=c++1y -c Load.cpp

SmoothsortPriorityQueue.o: SmoothsortPriorityQueue.cpp SmoothsortPriorityQueue.h Node.h
	g++ -std=c++1y -c SmoothsortPriorityQueue.cpp

Dijkstra.o: Dijkstra.cpp Dijkstra.h Node.h SmoothsortPriorityQueue.h
	g++ -std=c++1y -c Dijkstra.cpp

Astar.o: Astar.cpp Astar.h Node.h SmoothsortPriorityQueue.h
	g++ -std=c++1y -c Astar.cpp

Yen.o: Yen.cpp Yen.h Node.h
	g++ -std=c++1y -c Yen.cpp

k_paths.o: k_paths.cpp k_paths.h
	g++ -std=c++1y -c k_paths.cpp

clean:
	rm *.o main
