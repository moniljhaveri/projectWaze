#include <vector>
#include <limits>
#include "k_paths.h"
#include "Node.h"
#include "Dijkstra.h"
#include <iostream>

// -----------------------------------------------------------
//  The strategy for this function is to get three paths from
//  beginning node to the end node. The first path will be
//  the absolute shortest (calculated by Dijkstra's algorithm)
//  From there, we'll remove the middle node of the previous
//  shortest path and re-run Dijkstra's to get another path.
//  This will continue until we're either found 'k_max' paths
//  or can't find nay more paths. Note the this means that
//  after the first path, the k'th path isn't necessarily
//  strictly the k'th shortest path (though they'll be valid
//  paths based on the previous Dijkstra's run.)
// -----------------------------------------------------------
void k_paths(vector<Node>* nodes, vector< vector<Node*>* >* paths, Node *start_node, Node *end_node, unsigned int k_max)
{
  bool debug = true;

	// get the 0th (absolute) shortest path
  if (debug) cout << "calculating path 0" << endl;
	paths->push_back(new vector<Node*>);
	Dijkstra( nodes, (*paths)[0], start_node, end_node );
	reset_nodes(nodes);

  // get the next k paths
  for (int k=1; k<k_max; k++)
  {
    if (debug) cout << "calculating path " << k << endl;
    vector<Node*>* last_path_ptr = paths->back();

    int previous_path_size = last_path_ptr->size();

    // Pick out the node in the middle of the previous path.
    // Starting at that node, check nodes moving out from the center
    // until we find a node that has > 2 linked nodes. This way
    // when we remove the links to it's next node and it's previous
    // node, the node will still have a place to go (at least
    // locally.)
    int spur_node_index = (previous_path_size-1) / 2;
    Node *spur_node;
    bool found = false;
    int offset = 1;
    while((spur_node_index >= 0) && (spur_node_index < previous_path_size-1))
    {
      spur_node = last_path_ptr->at(spur_node_index);
      // if it's the first node it only needs to have at least two links
      int min_links = (spur_node_index == 0) ? 1 : 2;
      if (spur_node->getNumberOfLinkedNodes() > min_links)
      {
        found = true;
        break;
      }

      // This bit moves us out from the center of the previous path
      // For example, if we started at node 10, the sequence of
      // nodes we'd check is 10, 9, 11, 8, 12, 7, 13, etc.
      if (offset % 2 == 0) spur_node_index += offset;
      else spur_node_index -= offset;
      offset++;
    }

    if (found)
    {
      spur_node->removeLinkedNode( last_path_ptr->at(spur_node_index+1) );
      if (spur_node_index != 0) spur_node->removeLinkedNode( last_path_ptr->at(spur_node_index-1) );

      vector<Node*> tmp_path;
    	Dijkstra( nodes, &tmp_path, spur_node, end_node );

      // if the end node has a distance of infinity, it means we couldn't find a path
      if ( end_node->getDistanceFromStart() != numeric_limits<double>::infinity() )
      {
        paths->push_back(new vector<Node*>);

        // set the current path as the previous path up to the spur
        for (vector<Node*>::iterator node_it = last_path_ptr->begin() ; node_it != last_path_ptr->end(); ++node_it)
        {
          if (*node_it == spur_node) break;
          paths->back()->push_back(*node_it);
        }
        // add the new path found
        for (vector<Node*>::iterator node_it = tmp_path.begin() ; node_it != tmp_path.end(); ++node_it)
          paths->back()->push_back(*node_it);

        reset_nodes(nodes);
      }
    }
    else break;
  }
  restore_all_links(nodes);
}
