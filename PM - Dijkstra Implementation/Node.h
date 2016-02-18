#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <vector>
#include "Road.h"

using namespace std; 

class Node
{
	private:	
	string nodeID;
	float lat;
	float longit;
	vector<Road> roads;
	string nodefrom;
	float distance;	

	public:
	Node(string ID, float lat, float longit);
	void setDistance(float);
	float getDistance() const;
	string getNodeFrom() const;
	void setNodeFrom(string nodeID);
	void setCoord(float lat, float longit);
	string getNode() const;
	float getLat() const;
	float getLongit() const;
	void addRoad(Road);
	vector<Road> getRoads();
	bool operator<(const Node &d);
	bool operator>(const Node &d);
	
};

struct CompareNodes {
    bool operator()(const Node &n1, const Node &n2) const
	{
        return n1.getDistance() > n2.getDistance();
    }
};

struct CompareNodePtrs {
	bool operator()(Node* a, Node* b) 
	{ return (*a > *b); }
};

#endif // NODE_H_