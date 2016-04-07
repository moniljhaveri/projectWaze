#include <vector>
#include <limits>
#include "Yen.h"
#include "Node.h"
#include "Dijkstra.h"
#include <iostream>

void Yen(vector<Node>* nodes, vector< vector<Node*>* >* paths, Node *start_node, Node *end_node, int k_max)
{
	// get the 0th (absolute) shortest path
	(*paths).push_back(new vector<Node*>);
	Dijkstra( nodes, (*paths)[0], start_node, end_node );
	reset_nodes(nodes);
	
	// since we're only finding ~3 (or some small number of) shortest paths,
	// we're just using a vector to store the potential shortest paths. In a full
	// implementation of Yen's algorithm, we should use something like a heap so
	// its quick to sort/insert/delete/etc.
	vector< potential_path > potential_paths;
	
	bool debug = false;
	
	// main loop to get the k^th shortest path
	for (int k=1; k<k_max; k++)
	{	
		cout << "Calculating path " << k << endl;
		
		vector<Node*>* last_path_ptr = (*paths)[k-1];
		int last_k_size = last_path_ptr->size();
		
		if (debug) cout << "last k size: " << last_k_size << endl;
		
		double root_path_distance = 0.0;
		
		for (int spur_index=0; spur_index<last_k_size-1; spur_index++)
		{	
			//if (debug) cout << "----------------\n  spur_index: " << spur_index << endl;
			//cout << "  spur_index: " << spur_index << endl;
			
			Node* spur_node = (*last_path_ptr)[spur_index];
			if (debug) cout << "  spur node: " << spur_node->getID() << endl;
			
			if (spur_index > 0)
			{
				if (debug) cout << "  distance from " << spur_node->getID() << " to " << (*last_path_ptr)[spur_index-1]->getID() << ": ";
				root_path_distance += spur_node->getDistanceTo( (*last_path_ptr)[spur_index-1] );
				if (debug) cout << spur_node->getDistanceTo( (*last_path_ptr)[spur_index-1] ) << endl;
				(*last_path_ptr)[spur_index-1]->removeNode();
			}
			if (debug) cout << "  root path distance: " << root_path_distance << endl;
			
			if (debug) cout << "  removing node " << (*last_path_ptr)[spur_index+1]->getID() << " from node " << spur_node->getID() << endl;
			spur_node->removeLinkedNode( (*last_path_ptr)[spur_index+1] );
			
			// if we're working of the kth path, the we'll loop over the 0 to (k-2)th
			// shortest paths. if the path is the same as the current root path
			// (which is nodes 0 to 'spur_index' in the (k-1)th path), then we'll
			// potentially remove the following edge from the spur node
			if (debug && k>1) cout << "  looping over paths to find others to remove: " << endl;
			for (int path_index=0; path_index<k-1; path_index++)
			{
				if (debug) cout << "    path_index: " << path_index << endl;
				for (int node_index=spur_index; node_index>=0; node_index--)
				{
					if (debug) cout << "    node_index: " << node_index << endl;
					// if the node of the current path under inspection is not equal
					// to the node of root path, break (the root paths aren't the same.)
					if ( (*(*paths)[path_index])[node_index] != (*last_path_ptr)[node_index] )
					{
						if (debug) cout << "    breaking..." << endl;
						break;
					}
					else if (node_index == 0)
					{
						if (debug) cout << "    THIS PATH MATCHES" << endl;
						spur_node->removeLinkedNode( (*(*paths)[path_index])[spur_index+1] );
					}
				}
			}
			
			if (debug) cout << "  running Dijkstra's from node " << spur_node->getID() << " to node " << end_node->getID() << endl;
			vector<Node*> tmp_path;
			Dijkstra( nodes, &tmp_path, spur_node, end_node );
			
			if (debug)
			{
				cout << "    Dijkstra results: " << endl;
				cout << "      total len: " << end_node->getDistanceFromStart() << endl;
				for (vector<Node*>::iterator it = tmp_path.begin() ; it != tmp_path.end(); ++it)
					cout << "        node: " << (*it)->getID() << endl;
			}
			
			// ---------------------------------------------------------------------------
			// THIS WHOLE SECTION IS RESPONSIBLE FOR STORING THE PATH THAT WE'VE FOUND.
			// IF WE'RE TRYING TO FIND THE K_MAX SHORTEST PATHS, THEN HERE WE NEED TO
			// KEEP TRACK OF THE K_MAX-1 SHORTEST PATHS (SINCE WE'LL ALWAYS FIND AT
			// LEAST THE SINGLE SHORTEST PATH IN THE GRAPH.)
			// 
			// NOTE THAT THE SHORTEST PATH IS STORED AT THE *END* OF THIS 'potential_paths'
			// VECTOR. THAT WAY, WE CAN JUST CALL '.pop_back' ON THE VECTOR TO REMOVE
			// THE SHORTEST ONE WHEN WE'RE DONE
			//
			// if we found a path at all
			if ( end_node->getDistanceFromStart() != numeric_limits<double>::infinity() )
			{
				// if it's the first path, just store it
				if ( potential_paths.empty() )
				{
					potential_paths.push_back( potential_path() );
					potential_paths.back().distance = end_node->getDistanceFromStart() + root_path_distance;
				
					// add all the root_path nodes
					for (int root_path_index=0; root_path_index<spur_index; root_path_index++)
						potential_paths.back().path.push_back( (*last_path_ptr)[root_path_index] );
					
					// then add all the tmp_path nodes
					for (vector<Node*>::iterator it = tmp_path.begin() ; it != tmp_path.end(); ++it)
						potential_paths.back().path.push_back( *it );
					
					if (debug)
					{
						cout << "  adding initial PST ( distance: " << potential_paths.back().distance << "): " << endl;
						for (vector<Node*>::iterator it = potential_paths.back().path.begin() ; it != potential_paths.back().path.end(); ++it)
							cout << "    node: " << (*it)->getID() << endl;
					}
				}
				// if we don't yet have (k_max - 1) paths, decide where to put this one
				else if ( potential_paths.size() < k_max - 1 )
				{
					int i;
					for (i=0; i<potential_paths.size(); i++)
					{
						if (debug) cout << "    i: " << i;
						if ( end_node->getDistanceFromStart() + root_path_distance >= potential_paths[i].distance )
						{
							if (debug) cout << " < inserting here" << endl;
							potential_paths.insert( potential_paths.begin()+i, potential_path() );
							break;
						}
						else if (debug) if (debug) cout << " < not inserting here" << endl;
					}
				
					// if we didn't add it, push it onto the end - it's the shortest!
					if ( potential_paths.size() != k_max - 1 )
					{
						if (debug) cout << "    didn't add it before..." << endl;
						if (debug) cout << "    i: " << i << " < inserting here" << endl;
						potential_paths.push_back( potential_path() );
					}
				
					if (debug) cout << "  adding another PST at index " << i << " ( distance: ";
					potential_paths[i].distance = end_node->getDistanceFromStart() + root_path_distance;
				
					// add all the root_path nodes
					for (int root_path_index=0; root_path_index<spur_index; root_path_index++)
						potential_paths[i].path.push_back( (*last_path_ptr)[root_path_index] );
					
					// then add all the tmp_path nodes
					for (vector<Node*>::iterator it = tmp_path.begin() ; it != tmp_path.end(); ++it)
						potential_paths[i].path.push_back( *it );
					
					if (debug)
					{
						cout << potential_paths[i].distance << "): " << endl;
						for (vector<Node*>::iterator it = potential_paths[i].path.begin() ; it != potential_paths[i].path.end(); ++it)
							cout << "    node: " << (*it)->getID() << endl;
					}
				}
				// else figure out if we need to store this path at all
				else if ( end_node->getDistanceFromStart() + root_path_distance < potential_paths.front().distance )
				{
					if (debug) cout << "  adding PST at index 0 ( distance: " << end_node->getDistanceFromStart() + root_path_distance << ")" << endl;
					// We'll make the first path in the potential paths the new one, since we
					// know our new one belongs somewhere in the list
					potential_paths.front().distance = end_node->getDistanceFromStart() + root_path_distance;
					potential_paths.front().path.clear();
				
					// add all the root_path nodes
					for (int root_path_index=0; root_path_index<spur_index; root_path_index++)
						potential_paths.front().path.push_back( (*last_path_ptr)[root_path_index] );
					
					// then add all the tmp_path nodes
					for (vector<Node*>::iterator it = tmp_path.begin() ; it != tmp_path.end(); ++it)
						potential_paths.front().path.push_back( *it );
				
					for (int i=0; i<potential_paths.size()-1; i++)
					{
						if (debug) cout << "    checking swap: " << i << " and " << i+1 << "... ";
						if ( potential_paths[i].distance < potential_paths[i+1].distance )
						{
							if (debug) cout << "swapping!" << endl;
							iter_swap( potential_paths.begin()+i, potential_paths.begin()+i+1 );
						}
						else
						{
							if (debug) cout << "not swapping." << endl;
							break;
						}
					}
				}
				else
				{
					if (debug)
					{
						cout << "  not adding to to potential paths. Results were:" << endl;
						cout << "    Distance: " << end_node->getDistanceFromStart() + root_path_distance << endl;
						// add all the root_path nodes
						for (int root_path_index=0; root_path_index<spur_index; root_path_index++)
							cout << "      node: " << (*last_path_ptr)[root_path_index]->getID() << endl;
					
						// then add all the tmp_path nodes
						for (vector<Node*>::iterator it = tmp_path.begin() ; it != tmp_path.end(); ++it)
							cout << "      node: " << (*it)->getID() << endl;
					}
				}
			}
			// ---------------------------------------------------------------------------
			
			spur_node->restoreLinks();
			reset_nodes(nodes);
		}
		
		// copy over the shortest path for this iteration into a new path in the 'paths' vector
		paths->push_back(new vector<Node*>);
		
		if ( potential_paths.size() == 0 ) break;
		for (vector<Node*>::iterator it = potential_paths.back().path.begin() ; it != potential_paths.back().path.end() ; ++it)
			paths->back()->push_back( *it );
		
		potential_paths.pop_back();
	}
}