/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.google.maps.android.utils.demo;

public class NodeWrapJNI {
  public final static native long new_Node__SWIG_0(int jarg1, double jarg2, double jarg3);
  public final static native long new_Node__SWIG_1(int jarg1, double jarg2);
  public final static native long new_Node__SWIG_2(int jarg1);
  public final static native long new_Node__SWIG_3();
  public final static native void Node_linkedNode_ID_set(long jarg1, Node.linkedNode jarg1_, int jarg2);
  public final static native int Node_linkedNode_ID_get(long jarg1, Node.linkedNode jarg1_);
  public final static native void Node_linkedNode_node_set(long jarg1, Node.linkedNode jarg1_, long jarg2, Node jarg2_);
  public final static native long Node_linkedNode_node_get(long jarg1, Node.linkedNode jarg1_);
  public final static native void Node_linkedNode_distance_set(long jarg1, Node.linkedNode jarg1_, double jarg2);
  public final static native double Node_linkedNode_distance_get(long jarg1, Node.linkedNode jarg1_);
  public final static native long new_Node_linkedNode();
  public final static native void delete_Node_linkedNode(long jarg1);
  public final static native void Node_addLinkedNodeRaw__SWIG_0(long jarg1, Node jarg1_, int jarg2, long jarg3, Node jarg3_, double jarg4);
  public final static native void Node_addLinkedNodeRaw__SWIG_1(long jarg1, Node jarg1_, int jarg2, long jarg3, Node jarg3_);
  public final static native void Node_addLinkedNodeRaw__SWIG_2(long jarg1, Node jarg1_, int jarg2);
  public final static native void Node_addLinkedNodeRaw__SWIG_3(long jarg1, Node jarg1_);
  public final static native void Node_addLinkedNode(long jarg1, Node jarg1_, long jarg2, Node.linkedNode jarg2_);
  public final static native void Node_removeLinkedNode__SWIG_0(long jarg1, Node jarg1_, long jarg2, Node jarg2_);
  public final static native void Node_removeLinkedNode__SWIG_1(long jarg1, Node jarg1_);
  public final static native void Node_restoreLinks(long jarg1, Node jarg1_);
  public final static native void Node_removeNode(long jarg1, Node jarg1_);
  public final static native void Node_addNode(long jarg1, Node jarg1_);
  public final static native boolean Node_isInGraph(long jarg1, Node jarg1_);
  public final static native double Node_getDistanceTo__SWIG_0(long jarg1, Node jarg1_, long jarg2, Node jarg2_);
  public final static native double Node_getDistanceTo__SWIG_1(long jarg1, Node jarg1_);
  public final static native long Node_getLinkedNodes(long jarg1, Node jarg1_);
  public final static native int Node_getNumberOfLinkedNodes(long jarg1, Node jarg1_);
  public final static native boolean Node_hasLinkedNodes(long jarg1, Node jarg1_);
  public final static native void Node_setID__SWIG_0(long jarg1, Node jarg1_, int jarg2);
  public final static native void Node_setID__SWIG_1(long jarg1, Node jarg1_);
  public final static native int Node_getID(long jarg1, Node jarg1_);
  public final static native void Node_setLatLon__SWIG_0(long jarg1, Node jarg1_, double jarg2, double jarg3);
  public final static native void Node_setLatLon__SWIG_1(long jarg1, Node jarg1_, double jarg2);
  public final static native void Node_setLatLon__SWIG_2(long jarg1, Node jarg1_);
  public final static native double Node_getLat(long jarg1, Node jarg1_);
  public final static native double Node_getLon(long jarg1, Node jarg1_);
  public final static native void Node_setDistanceFromStart__SWIG_0(long jarg1, Node jarg1_, double jarg2);
  public final static native void Node_setDistanceFromStart__SWIG_1(long jarg1, Node jarg1_);
  public final static native double Node_getDistanceFromStart(long jarg1, Node jarg1_);
  public final static native void Node_setParent__SWIG_0(long jarg1, Node jarg1_, long jarg2, Node jarg2_);
  public final static native void Node_setParent__SWIG_1(long jarg1, Node jarg1_);
  public final static native long Node_getParent(long jarg1, Node jarg1_);
  public final static native void Node_setHVal__SWIG_0(long jarg1, Node jarg1_, double jarg2);
  public final static native void Node_setHVal__SWIG_1(long jarg1, Node jarg1_);
  public final static native double Node_getHVal(long jarg1, Node jarg1_);
  public final static native void Node_setGVal__SWIG_0(long jarg1, Node jarg1_, double jarg2);
  public final static native void Node_setGVal__SWIG_1(long jarg1, Node jarg1_);
  public final static native double Node_getGVal(long jarg1, Node jarg1_);
  public final static native void delete_Node(long jarg1);
  public final static native void reset_nodes(long jarg1, NodeVec jarg1_);
  public final static native void restore_all_links(long jarg1, NodeVec jarg1_);
  public final static native long new_NodeVec__SWIG_0();
  public final static native long new_NodeVec__SWIG_1(long jarg1);
  public final static native long NodeVec_size(long jarg1, NodeVec jarg1_);
  public final static native long NodeVec_capacity(long jarg1, NodeVec jarg1_);
  public final static native void NodeVec_reserve(long jarg1, NodeVec jarg1_, long jarg2);
  public final static native boolean NodeVec_isEmpty(long jarg1, NodeVec jarg1_);
  public final static native void NodeVec_clear(long jarg1, NodeVec jarg1_);
  public final static native void NodeVec_add(long jarg1, NodeVec jarg1_, long jarg2, Node jarg2_);
  public final static native long NodeVec_get(long jarg1, NodeVec jarg1_, int jarg2);
  public final static native void NodeVec_set(long jarg1, NodeVec jarg1_, int jarg2, long jarg3, Node jarg3_);
  public final static native void delete_NodeVec(long jarg1);
  public final static native long new_PathVec__SWIG_0();
  public final static native long new_PathVec__SWIG_1(long jarg1);
  public final static native long PathVec_size(long jarg1, PathVec jarg1_);
  public final static native long PathVec_capacity(long jarg1, PathVec jarg1_);
  public final static native void PathVec_reserve(long jarg1, PathVec jarg1_, long jarg2);
  public final static native boolean PathVec_isEmpty(long jarg1, PathVec jarg1_);
  public final static native void PathVec_clear(long jarg1, PathVec jarg1_);
  public final static native void PathVec_add(long jarg1, PathVec jarg1_, long jarg2, Node jarg2_);
  public final static native long PathVec_get(long jarg1, PathVec jarg1_, int jarg2);
  public final static native void PathVec_set(long jarg1, PathVec jarg1_, int jarg2, long jarg3, Node jarg3_);
  public final static native void delete_PathVec(long jarg1);
  public final static native long new_LinkedNodes__SWIG_0();
  public final static native long new_LinkedNodes__SWIG_1(long jarg1);
  public final static native long LinkedNodes_size(long jarg1, LinkedNodes jarg1_);
  public final static native long LinkedNodes_capacity(long jarg1, LinkedNodes jarg1_);
  public final static native void LinkedNodes_reserve(long jarg1, LinkedNodes jarg1_, long jarg2);
  public final static native boolean LinkedNodes_isEmpty(long jarg1, LinkedNodes jarg1_);
  public final static native void LinkedNodes_clear(long jarg1, LinkedNodes jarg1_);
  public final static native void LinkedNodes_add(long jarg1, LinkedNodes jarg1_, long jarg2, Node.linkedNode jarg2_);
  public final static native long LinkedNodes_get(long jarg1, LinkedNodes jarg1_, int jarg2);
  public final static native void LinkedNodes_set(long jarg1, LinkedNodes jarg1_, int jarg2, long jarg3, Node.linkedNode jarg3_);
  public final static native void delete_LinkedNodes(long jarg1);
  public final static native long new_K_Paths__SWIG_0();
  public final static native long new_K_Paths__SWIG_1(long jarg1);
  public final static native long K_Paths_size(long jarg1, K_Paths jarg1_);
  public final static native long K_Paths_capacity(long jarg1, K_Paths jarg1_);
  public final static native void K_Paths_reserve(long jarg1, K_Paths jarg1_, long jarg2);
  public final static native boolean K_Paths_isEmpty(long jarg1, K_Paths jarg1_);
  public final static native void K_Paths_clear(long jarg1, K_Paths jarg1_);
  public final static native void K_Paths_add(long jarg1, K_Paths jarg1_, long jarg2, PathVec jarg2_);
  public final static native long K_Paths_get(long jarg1, K_Paths jarg1_, int jarg2);
  public final static native void K_Paths_set(long jarg1, K_Paths jarg1_, int jarg2, long jarg3, PathVec jarg3_);
  public final static native void delete_K_Paths(long jarg1);
}
