/*
 * Copyright 2013 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.google.maps.android.utils.demo;

import android.graphics.Color;
import android.util.Log;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.UiSettings;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.maps.model.PolylineOptions;
import com.google.maps.android.clustering.ClusterManager;

import org.json.JSONException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.security.PublicKey;
import java.util.List;
import java.util.Vector;

/**
 * Simple activity demonstrating ClusterManager.
 */
public class ClusteringDemoActivity extends BaseDemoActivity {
    private ClusterManager<MyItem> mClusterManager;
    public NodeVec nodeVector = new NodeVec();
    public PathVec pathVector = new PathVec();


    protected void LoadNodes(){

        BufferedReader reader;
        try {
            Log.d("Node", "passed");
            final InputStream file = getAssets().open("cal.cnode.txt");
            reader = new BufferedReader(new InputStreamReader(file));
            String line = reader.readLine();
            while (line != null) {
                String delims = "[ ]+";
                String[] tokens = line.split(delims);
                // tokens[0]  = Node ID, tokens[1] = Longitude, tokens[2] = Latitude
                nodeVector.add(new Node(Integer.parseInt(tokens[0]), Double.parseDouble(tokens[2]), Double.parseDouble(tokens[1])));
                line = reader.readLine();
            }
            file.close();
            reader.close();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }
    }

    protected void LoadRoads(){

        //Load Roads

        BufferedReader pathReader;
        try {
            final InputStream pathfile = getAssets().open("cal.cedge.txt");
            pathReader = new BufferedReader(new InputStreamReader(pathfile));
            String pathLine = pathReader.readLine();
            // pathTest for testing all roads read in
            //int pathTest = 0;
            while (pathLine != null) {
               // Log.d("Reading Path", "start");
                String delims = "[ ]+";
                String[] tokens = pathLine.split(delims);
                // tokens[0]  = Road ID, tokens[1] = Start Node, tokens[2] = End Node, tokens[3] = Distance
                nodeVector.get(Integer.parseInt(tokens[1])).addLinkedNodeRaw(Integer.parseInt(tokens[0]),
                        nodeVector.get(Integer.parseInt(tokens[2])), Double.parseDouble(tokens[3]));
                nodeVector.get(Integer.parseInt(tokens[2])).addLinkedNodeRaw(Integer.parseInt(tokens[0]),
                        nodeVector.get(Integer.parseInt(tokens[1])), Double.parseDouble(tokens[3]));
                pathLine = pathReader.readLine();
                //pathTest = pathTest+1;

            }
            //Log.d("Pathlen: ", Integer.toString(pathTest));
            pathfile.close();
            pathReader.close();
        } catch (IOException ioe) {
            //Log.d("Reading Path", "not read");
            ioe.printStackTrace();
        }
    }
    /*
    protected void DrawRoads() {

        for (int i = 0; i < nodeVector.size(); i++) {
            LinkedNodes linkedNodes = new LinkedNodes();
            linkedNodes = nodeVector.get(i).getLinkedNodes();
            for (int m = 0; m < linkedNodes.size(); m++) {
                Polyline road = getMap().addPolyline(new PolylineOptions()
                        .add(new LatLng(nodeVector.get(i).getLat(), nodeVector.get(i).getLon()),
                                new LatLng(linkedNodes.get(m).getNode().getLat(), linkedNodes.get(m).getNode().getLon()))
                        .width(5)
                        .color(Color.RED));
                road.setVisible(true);

            }


        }
    }*/

    @Override
    protected void startDemo() {
        LoadNodes();
        LoadRoads();
       // DrawRoads();
        UiSettings mUiSettings = getMap().getUiSettings();
        mUiSettings.setZoomControlsEnabled(true);


        mClusterManager = new ClusterManager<MyItem>(this, getMap());
        getMap().setOnCameraChangeListener(mClusterManager);
        getMap().setOnMarkerClickListener(mClusterManager);

        getMap().moveCamera(CameraUpdateFactory.newLatLngZoom(new LatLng(nodeVector.get(0).getLat(), nodeVector.get(0).getLon()), 10));

        // for testing Dijkstra
        //DijkstraWrap.Dijkstra(nodeVector, pathVector, nodeVector.get(0), nodeVector.get(21047));
        //for(int i = 0; i<pathVector.size(); i++)
        //    Log.d("Path: ", Long.toString(pathVector.get(i).getID()));

        getMap().setOnCameraChangeListener(new GoogleMap.OnCameraChangeListener() {

            @Override
            public void onCameraChange(CameraPosition cameraPosition) {
                mClusterManager.onCameraChange(cameraPosition);
                LatLng curScreenNE = getMap().getProjection().getVisibleRegion().latLngBounds.northeast;
                LatLng curScreenSW = getMap().getProjection().getVisibleRegion().latLngBounds.southwest;



                mClusterManager.clearItems();
                getMap().clear();
                for (int i = 0; i < nodeVector.size(); i++) {

                    if (nodeVector.get(i).getLat() < curScreenNE.latitude && nodeVector.get(i).getLat() > curScreenSW.latitude) {
                        if (nodeVector.get(i).getLon() < curScreenNE.longitude && nodeVector.get(i).getLon() > curScreenSW.longitude) {
                            // Log.d("Pan","worked");
                            mClusterManager.addItem(new MyItem(nodeVector.get(i).getLat(), nodeVector.get(i).getLon()));
                            //Log.d("change called", "yes");
                           /* LinkedNodes linkedNodes = new LinkedNodes();
                            linkedNodes = nodeVector.get(i).getLinkedNodes();
                            for (int m = 0; m < linkedNodes.size(); m++) {
                                Polyline road = getMap().addPolyline(new PolylineOptions()
                                        .add(new LatLng(nodeVector.get(i).getLat(), nodeVector.get(i).getLon()),
                                                new LatLng(linkedNodes.get(m).getNode().getLat(), linkedNodes.get(m).getNode().getLon()))
                                        .width(5)
                                        .color(Color.RED));
                                road.setVisible(true);

                            }*/
                        }
                    }
                }
                // Needed to make sure markers recluster on camera pan
                mClusterManager.cluster();
            }
        });


        getMap().setOnMarkerClickListener(new GoogleMap.OnMarkerClickListener() {

            @Override
            public boolean onMarkerClick(Marker marker) {


                return false;

            }

        });
    }
}