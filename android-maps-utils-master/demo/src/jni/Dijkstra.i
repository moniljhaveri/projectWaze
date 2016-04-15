%module DijkstraWrap
%{
#include "Dijkstra.h"
%}
%import "Node.i"
%import "SmoothsortPriorityQueue.i"

%include "Dijkstra.h"
