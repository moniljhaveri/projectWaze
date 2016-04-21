%module NodeWrap
%{
#include "Node.h"
#include <vector>
%}
%include "Node.h"
%include "std_vector.i"

namespace std{
     %template(NodeVec) vector<Node>;
     %template(PathVec) vector<Node*>;
     %template(LinkedNodes) vector<Node::linkedNode>;
     %template(K_Paths) vector<vector<Node*>*>;
 }

