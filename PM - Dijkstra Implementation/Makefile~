dijk: main.o Load.o Node.o Road.o Dijkstra.o
	g++ -std=c++1y main.o Load.o Node.o Road.o Dijkstra.o -o dijk

main.o: main.cpp Load.h Node.h Dijkstra.h
	g++ -std=c++1y -c main.cpp

Load.o: Load.cpp Load.h Node.h Road.h
	g++ -std=c++1y -c Load.cpp

Node.o:	Node.cpp Node.h Road.h
	g++ -std=c++1y -c Node.cpp

Road.o: Road.cpp Road.h
	g++ -std=c++1y -c Road.cpp

Dijkstra.o: Dijkstra.cpp Dijkstra.h Node.h Road.h 
	g++ -std=c++1y -c Dijkstra.cpp

clean:
	rm *.o dijk
