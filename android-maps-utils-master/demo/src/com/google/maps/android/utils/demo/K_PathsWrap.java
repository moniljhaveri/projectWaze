/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.google.maps.android.utils.demo;

public class K_PathsWrap {
  public static void k_paths(NodeVec nodes, K_Paths paths, Node start_node, Node end_node, long k_max) {
    K_PathsWrapJNI.k_paths(NodeVec.getCPtr(nodes), nodes, K_Paths.getCPtr(paths), paths, Node.getCPtr(start_node), start_node, Node.getCPtr(end_node), end_node, k_max);
  }

}
