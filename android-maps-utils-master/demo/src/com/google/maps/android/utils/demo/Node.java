/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.google.maps.android.utils.demo;

public class Node {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected Node(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Node obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        NodeWrapJNI.delete_Node(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public Node(int ID, double lat, double lon) {
    this(NodeWrapJNI.new_Node__SWIG_0(ID, lat, lon), true);
  }

  public Node(int ID, double lat) {
    this(NodeWrapJNI.new_Node__SWIG_1(ID, lat), true);
  }

  public Node(int ID) {
    this(NodeWrapJNI.new_Node__SWIG_2(ID), true);
  }

  public Node() {
    this(NodeWrapJNI.new_Node__SWIG_3(), true);
  }

  static public class linkedNode {
    private transient long swigCPtr;
    protected transient boolean swigCMemOwn;
  
    protected linkedNode(long cPtr, boolean cMemoryOwn) {
      swigCMemOwn = cMemoryOwn;
      swigCPtr = cPtr;
    }
  
    protected static long getCPtr(linkedNode obj) {
      return (obj == null) ? 0 : obj.swigCPtr;
    }
  
    protected void finalize() {
      delete();
    }
  
    public synchronized void delete() {
      if (swigCPtr != 0) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          NodeWrapJNI.delete_Node_linkedNode(swigCPtr);
        }
        swigCPtr = 0;
      }
    }
  
    public void setID(int value) {
      NodeWrapJNI.Node_linkedNode_ID_set(swigCPtr, this, value);
    }
  
    public int getID() {
      return NodeWrapJNI.Node_linkedNode_ID_get(swigCPtr, this);
    }
  
    public void setNode(Node value) {
      NodeWrapJNI.Node_linkedNode_node_set(swigCPtr, this, Node.getCPtr(value), value);
    }
  
    public Node getNode() {
      long cPtr = NodeWrapJNI.Node_linkedNode_node_get(swigCPtr, this);
      return (cPtr == 0) ? null : new Node(cPtr, false);
    }
  
    public void setDistance(double value) {
      NodeWrapJNI.Node_linkedNode_distance_set(swigCPtr, this, value);
    }
  
    public double getDistance() {
      return NodeWrapJNI.Node_linkedNode_distance_get(swigCPtr, this);
    }
  
    public linkedNode() {
      this(NodeWrapJNI.new_Node_linkedNode(), true);
    }
  
  }

  public void addLinkedNodeRaw(int ID, Node node, double distance) {
    NodeWrapJNI.Node_addLinkedNodeRaw__SWIG_0(swigCPtr, this, ID, Node.getCPtr(node), node, distance);
  }

  public void addLinkedNodeRaw(int ID, Node node) {
    NodeWrapJNI.Node_addLinkedNodeRaw__SWIG_1(swigCPtr, this, ID, Node.getCPtr(node), node);
  }

  public void addLinkedNodeRaw(int ID) {
    NodeWrapJNI.Node_addLinkedNodeRaw__SWIG_2(swigCPtr, this, ID);
  }

  public void addLinkedNodeRaw() {
    NodeWrapJNI.Node_addLinkedNodeRaw__SWIG_3(swigCPtr, this);
  }

  public void addLinkedNode(Node.linkedNode node) {
    NodeWrapJNI.Node_addLinkedNode(swigCPtr, this, Node.linkedNode.getCPtr(node), node);
  }

  public void removeLinkedNode(Node node) {
    NodeWrapJNI.Node_removeLinkedNode__SWIG_0(swigCPtr, this, Node.getCPtr(node), node);
  }

  public void removeLinkedNode() {
    NodeWrapJNI.Node_removeLinkedNode__SWIG_1(swigCPtr, this);
  }

  public void restoreLinks() {
    NodeWrapJNI.Node_restoreLinks(swigCPtr, this);
  }

  public void removeNode() {
    NodeWrapJNI.Node_removeNode(swigCPtr, this);
  }

  public void addNode() {
    NodeWrapJNI.Node_addNode(swigCPtr, this);
  }

  public boolean isInGraph() {
    return NodeWrapJNI.Node_isInGraph(swigCPtr, this);
  }

  public double getDistanceTo(Node node) {
    return NodeWrapJNI.Node_getDistanceTo__SWIG_0(swigCPtr, this, Node.getCPtr(node), node);
  }

  public double getDistanceTo() {
    return NodeWrapJNI.Node_getDistanceTo__SWIG_1(swigCPtr, this);
  }

  public LinkedNodes getLinkedNodes() {
    return new LinkedNodes(NodeWrapJNI.Node_getLinkedNodes(swigCPtr, this), true);
  }

  public int getNumberOfLinkedNodes() {
    return NodeWrapJNI.Node_getNumberOfLinkedNodes(swigCPtr, this);
  }

  public boolean hasLinkedNodes() {
    return NodeWrapJNI.Node_hasLinkedNodes(swigCPtr, this);
  }

  public void setID(int ID) {
    NodeWrapJNI.Node_setID__SWIG_0(swigCPtr, this, ID);
  }

  public void setID() {
    NodeWrapJNI.Node_setID__SWIG_1(swigCPtr, this);
  }

  public int getID() {
    return NodeWrapJNI.Node_getID(swigCPtr, this);
  }

  public void setLatLon(double lat, double lon) {
    NodeWrapJNI.Node_setLatLon__SWIG_0(swigCPtr, this, lat, lon);
  }

  public void setLatLon(double lat) {
    NodeWrapJNI.Node_setLatLon__SWIG_1(swigCPtr, this, lat);
  }

  public void setLatLon() {
    NodeWrapJNI.Node_setLatLon__SWIG_2(swigCPtr, this);
  }

  public double getLat() {
    return NodeWrapJNI.Node_getLat(swigCPtr, this);
  }

  public double getLon() {
    return NodeWrapJNI.Node_getLon(swigCPtr, this);
  }

  public void setDistanceFromStart(double distance) {
    NodeWrapJNI.Node_setDistanceFromStart__SWIG_0(swigCPtr, this, distance);
  }

  public void setDistanceFromStart() {
    NodeWrapJNI.Node_setDistanceFromStart__SWIG_1(swigCPtr, this);
  }

  public double getDistanceFromStart() {
    return NodeWrapJNI.Node_getDistanceFromStart(swigCPtr, this);
  }

  public void setParent(Node node) {
    NodeWrapJNI.Node_setParent__SWIG_0(swigCPtr, this, Node.getCPtr(node), node);
  }

  public void setParent() {
    NodeWrapJNI.Node_setParent__SWIG_1(swigCPtr, this);
  }

  public Node getParent() {
    long cPtr = NodeWrapJNI.Node_getParent(swigCPtr, this);
    return (cPtr == 0) ? null : new Node(cPtr, false);
  }

  public void setHVal(double h_val) {
    NodeWrapJNI.Node_setHVal__SWIG_0(swigCPtr, this, h_val);
  }

  public void setHVal() {
    NodeWrapJNI.Node_setHVal__SWIG_1(swigCPtr, this);
  }

  public double getHVal() {
    return NodeWrapJNI.Node_getHVal(swigCPtr, this);
  }

  public void setGVal(double g_val) {
    NodeWrapJNI.Node_setGVal__SWIG_0(swigCPtr, this, g_val);
  }

  public void setGVal() {
    NodeWrapJNI.Node_setGVal__SWIG_1(swigCPtr, this);
  }

  public double getGVal() {
    return NodeWrapJNI.Node_getGVal(swigCPtr, this);
  }

}
