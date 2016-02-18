#ifndef HEAP_H_
#define HEAP_H_
#include "Node.h"

using namespace std;

class MinHeap
{
	private:
	vector<Node> heap;

	public:
	max_heapify(vector<Node> heap, int index);
	build_max_heap(vector<Node>);
	heap_sort(vector<Node>);
	
}	


#endif // HEAP_H_
