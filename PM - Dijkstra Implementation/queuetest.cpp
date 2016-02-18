#include <iostream>
#include <vector> 
#include <fstream>
#include <string>
#include <algorithm>
#include "Node.h"
#include "Load.h"
#include "Road.h"


using namespace std;

int main(int argc, char *argv[])
{
string Nfile = argv[1];
string Rfile = argv[2];
vector<Node> nodevec;


nodevec = loadnodes(Nfile);
priority_queue<Node> heap (nodevec.begin(), nodevec.end());

for(int i = 0; i<7; i++)
{
	cout << nodevec[i].getnode() << " " <<  nodevec[i].getlat();
	cout << " " << nodevec[i].getlongit() << endl;
	
} 
loadroads(Rfile, nodevec);
for(int j = 0; j < nodevec.end(); j++)
{
	cout<<heap[j].getnode() <<endl;
}
//vector<Road> myroads = nodevec[5].getroads();
//cout << myroads.size() << endl;
//for(int j = 0; j<myroads.size(); j++)
//	cout << myroads[j].getroad() << " ";
//cout<<endl;
return 0;
}
