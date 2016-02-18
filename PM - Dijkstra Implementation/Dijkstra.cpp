#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Node.h"
#include "Dijkstra.h"
#include "Road.h"

void dijkstra(vector<Node*> &ptrvec, vector<Node> &nodevec, string begin, string end)
{	
	vector<Node*> visited;
	vector<Road> roadvec;
	nodevec[0].setDistance(0.0);
	make_heap(ptrvec.begin(), ptrvec.end(), CompareNodePtrs());
	while(ptrvec.size())
	{
		roadvec = ptrvec[0]->getRoads();
		updateNodeDist(ptrvec, nodevec, roadvec); 
		visited.push_back(ptrvec[0]);
		pop_heap(ptrvec.begin(), ptrvec.end(), CompareNodePtrs());
		ptrvec.pop_back();
		make_heap(ptrvec.begin(), ptrvec.end(), CompareNodePtrs());
		if(ptrvec[0]->getNode() == end)
			break;
	}
	vector<string> path = retrievePath(ptrvec, nodevec, begin, end);	
}

void updateNodeDist(vector<Node*> &ptrvec, vector<Node> &nodevec, vector<Road> roadvec)
{
	float d;

	for(int i = 0; i<roadvec.size(); i++)
	{
		string toNode = roadvec[i].getEnd();
		d = ptrvec[0]->getDistance() + roadvec[i].getLength();
				
		if(d < nodevec[stoi(toNode)].getDistance())
		{	
			nodevec[stoi(toNode)].setDistance(d);
			nodevec[stoi(toNode)].setNodeFrom(roadvec[i].getStart());}
	}	
}

vector<string> retrievePath(vector<Node*> &ptrvec, vector<Node> &nodevec, string begin, string end)
{
	vector<string> path;
	path.push_back(ptrvec[0]->getNode());
	string nodefrom = ptrvec[0]->getNodeFrom();

	path.push_back(nodefrom);
	while(nodefrom != begin)
	{	nodefrom = nodevec[stoi(nodefrom)].getNodeFrom();
		path.push_back(nodefrom);
	}
	reverse(path.begin(),path.end());
	for(int i = 0; i<path.size(); i++)
		{cout<<path[i]<<" ";}
	cout<<endl;
	return path;
}