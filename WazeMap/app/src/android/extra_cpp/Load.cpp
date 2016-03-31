#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Node.h"

using namespace std;

int Load(vector<Node>* nodes, string fpath_nodes, string fpath_edges)
{
	string line;
	char * line_c;
	char * pEnd;
	char * parsed_line[4];
	
	ifstream file(fpath_nodes);
	if (file.is_open())
	{
		while ( getline (file,line) )
		{	
			line_c = (char*)line.c_str();
			
			int ID     = (int)strtol( strtok(line_c, " ") , &pEnd , 10);
			double lat =      strtod( strtok(NULL, " ")   , &pEnd);
			double lon =      strtod( strtok(NULL, " ")   , &pEnd);
			
			Node new_node(ID, lat, lon);
			(*nodes).push_back(new_node);
		}
		file.close();	
	}
	else
	{
		cout << "Unable to open node file\n";
		return false;
	}
	
	file.open(fpath_edges);
	if (file.is_open())
	{
		while ( getline (file,line) )
		{	
			line_c = (char*)line.c_str();
			
			int ID          = (int)strtol( strtok(line_c, " ") , &pEnd , 10);
			int start_node  = (int)strtol( strtok(NULL, " ")   , &pEnd , 10);
			int end_node    = (int)strtol( strtok(NULL, " ")   , &pEnd , 10);
			double distance =      strtod( strtok(NULL, " ")   , &pEnd);
			
			(*nodes)[start_node].addLinkedNode( ID, &(*nodes)[end_node],   distance);
			(*nodes)[end_node].addLinkedNode  ( ID, &(*nodes)[start_node], distance);
		}
		file.close();	
	}
	else
	{
		cout << "Unable to open edge file\n";
		return false;
	}
	return true;
}
