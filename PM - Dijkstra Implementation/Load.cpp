#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Node.h"
#include "Road.h"

using namespace std;

vector<Node> loadNodes(string nodefile)
{
ifstream infile(nodefile);
int ID;
float lat;
float longit;
vector<Node> nodevec;
while(infile >> ID){
	infile >> lat;
	infile >> longit;
	Node nodename(ID,lat,longit);
	nodevec.push_back(nodename);
}
return nodevec;
}

void loadRoads(string filename, vector<Node> &nodevec)
{
ifstream infile(filename);
int ID;
int st;
int end;
float length; 
while(infile >> ID)
{
	infile >> st;
	infile >> end;
	infile >> length;

	Road roadname(ID,st,end,length);
	nodevec[st].addRoad(roadname);
	
	Road oppositeDir(ID,end,st,length);
	nodevec[end].addRoad(oppositeDir);

}
}