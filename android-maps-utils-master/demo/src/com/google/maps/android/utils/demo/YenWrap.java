/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.google.maps.android.utils.demo;

public class YenWrap {
  public static void Yen(NodeVec nodes, YenPath paths, Node start_node, Node end_node, int k_max) {
    YenWrapJNI.Yen(NodeVec.getCPtr(nodes), nodes, YenPath.getCPtr(paths), paths, Node.getCPtr(start_node), start_node, Node.getCPtr(end_node), end_node, k_max);
  }

}
