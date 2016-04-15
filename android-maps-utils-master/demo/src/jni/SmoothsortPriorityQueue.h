#ifndef SMOOTHSORTPRIORITYQUEUE_H
#define SMOOTHSORTPRIORITYQUEUE_H

#include "Node.h"

#define NUMBER_OF_LEONARDO_NUMBERS 20
#define TREES_LENGTH 10

class SmoothsortPriorityQueue
{
	public:
		SmoothsortPriorityQueue( vector<Node>* nodes );
		void sort();
		int getQueueSize();
		Node *dequeue();
		
	private:
		Node **queue;
		int queue_size;
		int leonardo_numbers[NUMBER_OF_LEONARDO_NUMBERS];
		int tree_index;
		int trees[TREES_LENGTH];
		void sift(int index, int tree_size);
		void move_to_correct_heap(int index);
		void move_to_correct_heap_dequeue(int index);
};

#endif