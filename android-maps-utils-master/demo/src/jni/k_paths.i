%module K_PathsWrap
%{
#include "k_paths.h"
%}
%import "Node.i"
%import "SmoothsortPriorityQueue.i"
%import "Dijkstra.i"

%include "k_paths.h"
