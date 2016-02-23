#include <iostream>
#include <vector> 
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include "Node.h"
#include "Load.h"
#include "Dijkstra.h"
#include <chrono> 

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{ high_resolution_clock::time_point t1 = high_resolution_clock::now();
string Nfile = argv[1]; // set Node file
string Rfile = argv[2]; // set Road file
int begin = stoi(argv[3]); // start node
int end = stoi(argv[4]); // end node

vector<Node> nodevec; // nodevec holds information on all nodes

nodevec = loadNodes(Nfile);   
	
loadRoads(Rfile, nodevec);  

//create vector of pointers. One pointer for each node in nodevec.
//A min binary heap is made from the vector of pointers, using the distance from
//the start node to order the heap. A separate vector (nodevec) holding the nodes
//allows us to update node information in O(1) time without having to keep track of a node's
//position in the heap
vector<Node*> ptrvec(nodevec.size());
for(int i = 0; i<nodevec.size(); i++)
	ptrvec[i] = &nodevec[i]; 

//make ptrvec into a min heap
make_heap(ptrvec.begin(), ptrvec.end(), CompareNodePtrs());

dijkstra(ptrvec, nodevec, begin, end);

high_resolution_clock::time_point t2 = high_resolution_clock::now();
auto duration = duration_cast<microseconds>( t2 - t1 ).count();
cout << duration << " Time" << endl;
return 0;
}
