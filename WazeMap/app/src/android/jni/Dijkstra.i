%module DijkstraWrap
%{
#include "Dijkstra.h"
%}
%import "Node.i"
%import "SmoothsortPriorityQueue.i"
%import "Astar.i"

%include "Dijkstra.h"
