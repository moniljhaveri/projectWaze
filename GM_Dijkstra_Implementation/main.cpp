#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Load.h"
#include "Dijkstra.h"
#include "Astar.h"
#include "Yen.h"
#include "k_paths.h"
#include "SmoothsortPriorityQueue.h"
#include <chrono>

using namespace std;
//using namespace std::chrono;

// KNOWN ISSUE:
//	If the graph is partitioned, and start node is in one section and the end node is in
//	another section, this will fail.

int main(int argc, char *argv[])
{
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	vector<Node> nodes;
	vector<Node*> path;
	vector< vector<Node*>* > paths;
	int num_nodes;
	int start_node = stoi(argv[3]);
	int end_node = stoi(argv[4]);
	string node_file = argv[1];
	string edge_file = argv[2];

	// set up the data structure
	num_nodes = Load( &nodes, node_file, edge_file );

	// run the algorithm
	//Dijkstra( &nodes, &path, &(nodes[start_node]), &(nodes[end_node]) );
	//Astar( &nodes, &path, &(nodes[start_node]), &(nodes[end_node]), 10.0, false );
	// Yen( &nodes, &paths, &(nodes[start_node]), &(nodes[end_node]), 3 );
  k_paths( &nodes, &paths, &(nodes[start_node]), &(nodes[end_node]), 3 );

	// print the Dijkstra or Astar results
	//for (vector<Node*>::iterator it = path.begin() ; it != path.end(); ++it)
	//	cout << (*(*it)).getID() << endl;
	//cout << "\nNodes in path: " << path.size() << endl;

	// print the Yen results
	int path_number = 1;
	for (vector< vector<Node*>* >::iterator path_it = paths.begin() ; path_it != paths.end(); ++path_it)
	{
		cout << "Path number " << path_number++ << ": " << endl;
		for (vector<Node*>::iterator node_it = (*path_it)->begin() ; node_it != (*path_it)->end(); ++node_it)
			cout << "  " << (*node_it)->getID() << endl;
		cout << "Nodes in path: " << (*path_it)->size() << endl;
	}

	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	//cout << "Total Time: " << duration << endl;

	return 0;
}
