#include "SmoothsortPriorityQueue.h"
#include "Node.h"

SmoothsortPriorityQueue::SmoothsortPriorityQueue( vector<Node>* nodes )
{
	// initialize our class copy of the list
	queue = new Node*[ (*nodes).size() ];
	
	int max_queue_size = (*nodes).size();
	//queue_size = (*nodes).size();
	queue_size = 0;
	for ( int i=0; i<max_queue_size ; i++ ) 
	{
		if ( (*nodes)[i].isInGraph() )
			queue[queue_size++] = &(*nodes)[i];
	}
	
	// initialize the leonardo number
	leonardo_numbers[0] = 1;
	leonardo_numbers[1] = 1;
	for ( int i=2 ; i<NUMBER_OF_LEONARDO_NUMBERS ; i++ )
	{
		leonardo_numbers[i] = leonardo_numbers[i-1] + leonardo_numbers[i-2] + 1;
	}
	
	// initialize tracking of our heaps
	tree_index = 0;
	for ( int i=0 ; i<TREES_LENGTH ; i++ ) trees[i] = 0;
}

void SmoothsortPriorityQueue::sort()
{
	for ( int i=0 ; i<queue_size ; i++ )
	{
		// Case 0: If there are no elements in the heap, add a tree of order 1.
		if ( trees[0] == 0 )
		{
			trees[0] = 1;
			tree_index++;
			continue;
		}
		// Case 1: If the last two heaps have sizes that differ by one, we
		//         add the new element by merging the last two heaps.
		else if ( ( tree_index > 1 ) && ( trees[ tree_index-2 ] - trees[ tree_index-1 ] == 1 ) )
		{
			trees[ --tree_index-1 ] += 1;
			trees[ tree_index ] = 0;
		}
		// Case 2: Otherwise, if the last heap has Leonardo number 1, add
		//         a singleton heap of Leonardo number 0.
		else if ( trees[ tree_index-1 ] == 1 )
		{
			trees[ tree_index++ ] = 0;
		}
		// Case 3: Otherwise, add a singleton heap of Leonardo number 1.
		else
		{
			trees[ tree_index++ ] = 1;
		}
		move_to_correct_heap(i);
	}
}

void SmoothsortPriorityQueue::sift(int index, int tree_size)
{
	Node **left_child;
	Node **right_child;
	while ( tree_size > 1 )
	{
		left_child = &queue[ index - (leonardo_numbers[ tree_size ] - leonardo_numbers[ tree_size-1 ]) ];
		right_child = &queue[ index - 1 ];
		if ( ( (**left_child).getDistanceFromStart() <= (**right_child).getDistanceFromStart() ) && ( (**left_child).getDistanceFromStart() < (*queue[ index ]).getDistanceFromStart() ) )
		{
			Node *tmp = queue[ index ];
			queue[ index ] = *left_child;
			*left_child = tmp;
			index -= leonardo_numbers[ tree_size ] - leonardo_numbers[ tree_size-1 ];
			tree_size--;
		}
		else if ( ( (**right_child).getDistanceFromStart() < (**left_child).getDistanceFromStart() ) && ( (**right_child).getDistanceFromStart() < (*queue[ index ]).getDistanceFromStart() ) )
		{
		
			Node *tmp = queue[ index ];
			queue[ index ] = *right_child;
			*right_child = tmp;
			index--;
			tree_size -= 2;
		}
		else break;
	}
}

void SmoothsortPriorityQueue::move_to_correct_heap(int index)
{
	bool need_to_sort_lowest_tree = true;
	int lookback = 0;
	for ( int j=tree_index-1 ; j>0 ; j-- )
	{
		lookback = leonardo_numbers[ trees[ j ] ];
		
		if ( (*queue[ index ]).getDistanceFromStart() > (*queue[ index - lookback ]).getDistanceFromStart() )
		{
			Node *tmp = queue[ index ];
			queue[ index ] = queue[index - lookback ];
			queue[ index - lookback ] = tmp;
			sift(index, trees[j]);
			index -= lookback;
		}
		else
		{
			sift(index, trees[j]);
			need_to_sort_lowest_tree = false;
			break;
		}
	}
	if (need_to_sort_lowest_tree) sift(leonardo_numbers[ trees[0] ] - 1, trees[0]);
}

void SmoothsortPriorityQueue::move_to_correct_heap_dequeue(int index)
{
	int lookback = 0;
	double minimum = (*queue[ index ]).getDistanceFromStart();
	int index_of_minimum = index;
	int tree_size_of_minimum = trees[ tree_index - 1 ];
	for ( int j=tree_index-1 ; j>0 ; j-- )
	{
		lookback += leonardo_numbers[ trees[ j ] ];
	
		if ( minimum > (*queue[ index - lookback ]).getDistanceFromStart() )
		{
			minimum = (*queue[ index - lookback ]).getDistanceFromStart();
			index_of_minimum = index - lookback;
			tree_size_of_minimum = trees[ j-1 ];
		}
	}
	
	if (index_of_minimum != index)
	{
		Node *tmp = queue[ index ];
		queue[ index ] = queue[ index_of_minimum ];
		queue[ index_of_minimum ] = tmp;
		sift(index, trees[ tree_index - 1 ]);
		sift(index_of_minimum, tree_size_of_minimum);
	}
}

Node *SmoothsortPriorityQueue::dequeue()
{
	if (trees[ tree_index-1 ] > 1)
	{
		trees[ tree_index-1 ] = trees[ tree_index-1 ] - 1;
		trees[ tree_index ] = trees[ tree_index-1 ] - 1;
		tree_index++;
	}
	else
	{
		trees[ --tree_index ] = 0;
	}
	move_to_correct_heap_dequeue( --queue_size - 1 );
	
	// Note to self - can probably combine the sorting a dequeuing since they're dependant
	tree_index = 0;
	for ( int i=0 ; i<TREES_LENGTH ; i++ ) trees[i] = 0;
	
	return queue[queue_size];
}

int SmoothsortPriorityQueue::getQueueSize()
{
	return this->queue_size;
}