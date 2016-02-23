#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Node.h"
#include "Dijkstra.h"
#include "Road.h"

#include <chrono> 
using namespace std::chrono;

void dijkstra(vector<Node*> &ptrvec, vector<Node> &nodevec, int begin, int end)
{	
	vector<Node*> visited;
	vector<Road> roadvec;
	nodevec[begin].setDistance(0.0);
    make_heap(ptrvec.begin(), ptrvec.end(), CompareNodePtrs());
		
	while(ptrvec.size())
	{
		roadvec = ptrvec[0]->getRoads();
		updateNodeDist(ptrvec, nodevec, roadvec); 
		ptrvec.erase(ptrvec.begin());
		make_heap(ptrvec.begin(), ptrvec.end(), CompareNodePtrs());
		if((ptrvec[0]->getNode()) == end)
			break;
	}

    vector<int> path = retrievePath(ptrvec, nodevec, begin);
}

void updateNodeDist(vector<Node*> &ptrvec, vector<Node> &nodevec, vector<Road> &roadvec)
{
	float d;

	for(int i = 0; i<roadvec.size(); i++)
	{
		int toNode = roadvec[i].getEnd();
		d = ptrvec[0]->getDistance() + roadvec[i].getLength();
				
		if(d < nodevec[toNode].getDistance())
		{	
			nodevec[toNode].setDistance(d);
			nodevec[toNode].setNodeFrom(roadvec[i].getStart());}
	}	
}

vector<int> retrievePath(vector<Node*> &ptrvec, vector<Node> &nodevec, int begin)
{
	vector<int> path;
	path.push_back(ptrvec[0]->getNode());
	int nodefrom = ptrvec[0]->getNodeFrom();

	path.push_back(nodefrom);
	while(nodefrom != begin)
	{	nodefrom = nodevec[nodefrom].getNodeFrom();
		path.push_back(nodefrom);
	}
	reverse(path.begin(),path.end());
	for(int i = 0; i<path.size(); i++)
		{cout<<path[i]<<" ";}
	cout<<endl;
	return path;
}