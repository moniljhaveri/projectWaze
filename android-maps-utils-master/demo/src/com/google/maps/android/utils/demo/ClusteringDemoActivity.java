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

import android.content.Intent;
import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.UiSettings;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.maps.model.PolylineOptions;
import com.google.maps.android.clustering.Cluster;
import com.google.maps.android.clustering.ClusterManager;

import org.json.JSONException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.security.PublicKey;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Vector;

/**
 * Simple activity demonstrating ClusterManager.
 */
public class ClusteringDemoActivity extends BaseDemoActivity {
    private ClusterManager<MyItem> mClusterManager;
    public NodeVec nodeVector = new NodeVec();
    public PathVec pathVector = new PathVec();
    ArrayList<Integer> pathIDs;
    LinkedNodes linkedNodes = new LinkedNodes();
    int linkID = -1;
    int startID = -1;
    int endID = -1;
    int turnByTurn = 0;
    private ProgressBar bar;

    public ProgressBar getProgressBar(){
        return bar;
    }

    public void showProgressBar(){
        bar.setVisibility(View.VISIBLE);
    }
    public void hideProgressBar(){
        bar.setVisibility(View.INVISIBLE);
    }

    public NodeVec getNodeVector(){
        return nodeVector;
    }

    public PathVec getPathVector(){
        return pathVector;
    }

    public void setPathVector(PathVec path){
        pathVector = path;
    }

    public int getStartID(){
        return startID;
    }

    public int getEndID(){
        return endID;
    }

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

    @Override
    protected void startDemo() {
        LoadNodes();
        LoadRoads();
       // DrawRoads();
        final UiSettings mUiSettings = getMap().getUiSettings();
        mUiSettings.setZoomControlsEnabled(true);
        getMap().setPadding(0,50,0,100);



        mClusterManager = new ClusterManager<MyItem>(this, getMap());
        mClusterManager.setRenderer(new MyClusterRenderer(this, getMap(), mClusterManager));
        getMap().setOnCameraChangeListener(mClusterManager);
        getMap().setOnMarkerClickListener(mClusterManager);

        Button startButton = (Button) findViewById(R.id.button0);
        final TextView startText = (TextView) findViewById(R.id.startText);
        startText.setText(" Start: ");
        Button endButton = (Button) findViewById(R.id.button1);
        final TextView endText = (TextView) findViewById(R.id.endText);
        endText.setText(" End: ");
        final Button goButton = (Button) findViewById(R.id.button2);
        Button clearButton = (Button) findViewById(R.id.button3);
        bar = (ProgressBar) this.findViewById(R.id.progressBar);


        getMap().moveCamera(CameraUpdateFactory.newLatLngZoom(new LatLng(nodeVector.get(0).getLat(), nodeVector.get(0).getLon()), 10));

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
                            mClusterManager.addItem(new MyItem(nodeVector.get(i).getLat(), nodeVector.get(i).getLon(), nodeVector.get(i).getID(),
                                    "Node: " + Integer.toString(nodeVector.get(i).getID()) + " Latitude: " + Double.toString(nodeVector.get(i).getLat()) + " Longitude: " + Double.toString(nodeVector.get(i).getLon())));
                            //Log.d("change called", "yes");

                            if (cameraPosition.zoom > 10) {
                                LinkedNodes links = new LinkedNodes();
                                links = nodeVector.get(i).getLinkedNodes();
                                for (int m = 0; m < links.size(); m++) {
                                    Polyline road = getMap().addPolyline(new PolylineOptions()
                                            .add(new LatLng(nodeVector.get(i).getLat(), nodeVector.get(i).getLon()),
                                                    new LatLng(links.get(m).getNode().getLat(), links.get(m).getNode().getLon()))
                                            .width(5)
                                            .color(Color.BLACK));
                                    road.setVisible(true);
                                }
                            }
                        }
                    }
                }

                for (int m = 0; m < pathVector.size() - 1; m++) {
                    if (pathVector.get(m).getLat() < curScreenNE.latitude && pathVector.get(m).getLat() > curScreenSW.latitude) {
                        if (pathVector.get(m).getLon() < curScreenNE.longitude && pathVector.get(m).getLon() > curScreenSW.longitude) {
                            Polyline road = getMap().addPolyline(new PolylineOptions()
                                    .add(new LatLng(pathVector.get(m).getLat(), pathVector.get(m).getLon()),
                                            new LatLng(pathVector.get(m + 1).getLat(), pathVector.get(m + 1).getLon()))
                                    .width(5)
                                    .color(Color.MAGENTA));
                            road.setVisible(true);
                        }
                    }
                }
                // Needed to make sure markers recluster on camera pan
                mClusterManager.cluster();

                if (linkedNodes != null) {
                    for (int m = 0; m < linkedNodes.size(); m++) {
                        Polyline road = getMap().addPolyline(new PolylineOptions()
                                .add(new LatLng(nodeVector.get(linkID).getLat(), nodeVector.get(linkID).getLon()),
                                        new LatLng(linkedNodes.get(m).getNode().getLat(), linkedNodes.get(m).getNode().getLon()))
                                .width(5)
                                .color(Color.RED));
                        road.setVisible(true);
                    }
                }
                linkedNodes = null;
                //linkID = -1;
            }
        });

        mClusterManager.setOnClusterItemClickListener(new ClusterManager.OnClusterItemClickListener<MyItem>() {
            @Override
            public boolean onClusterItemClick(MyItem item) {
                item.setTitle("Node: " + Integer.toString(item.getID()) + " Latitude: "
                        + Double.toString(nodeVector.get(item.getID()).getLat()) +
                        " Longitude: " + Double.toString(nodeVector.get(item.getID()).getLon()));
                Log.d("Item: ", Integer.toString(item.getID()));
                linkedNodes = nodeVector.get(item.getID()).getLinkedNodes();
                linkID = item.getID();


                return false;
            }
        });

        startButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                if (linkID != -1) {
                    startID = linkID;
                    String buttonText = " Start: Node "+ Integer.toString(startID)+ ", "
                           + Double.toString(nodeVector.get(linkID).getLat()) + ", "
                            + Double.toString(nodeVector.get(linkID).getLon());
                    startText.setText(buttonText);
                }
            }
        });

        endButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                if(linkID != -1) {
                    endID = linkID;
                    String buttonText = " End: Node " + Integer.toString(endID)+ ", "
                    + Double.toString(nodeVector.get(linkID).getLat()) + ", "
                            + Double.toString(nodeVector.get(linkID).getLon());
                    endText.setText(buttonText);
                }
            }
        });

        goButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                if (endID > -1 && startID > -1 && turnByTurn == 0) {
                    //setTitle("Loading...");
                    new ProgressTask().execute();
                   // DijkstraWrap.Dijkstra(nodeVector, pathVector, nodeVector.get(startID), nodeVector.get(endID));
                   // getMap().moveCamera(CameraUpdateFactory.newLatLng(getMap().getCameraPosition().target));
                    goButton.setText("Turn By Turn");
                    turnByTurn = 1;
                }
                else if(turnByTurn == 1){
                    LinkedNodes links = new LinkedNodes();
                    String[] pathIDs = new String[(int)pathVector.size()];
                    double roadDistance = 0;
                    double totalDistance = 0;
                    for(int i = 0; i<pathVector.size()-1; i++) {
                        links = nodeVector.get(pathVector.get(i).getID()).getLinkedNodes();
                        int roadID = -1;
                        for(int j = 0; j<links.size();j++){
                            if(links.get(j).getNode().getID() == pathVector.get(i+1).getID()) {
                                //Log.d("Links","In If");
                                roadID = links.get(j).getID();
                                roadDistance = links.get(j).getDistance();
                                totalDistance += roadDistance;
                                break;
                            }
                        }

                        pathIDs[i] = "Take road " + Integer.toString(roadID) + " from node "
                                + Integer.toString(pathVector.get(i).getID()) + " to node "
                                + Integer.toString(pathVector.get(i+1).getID()) + ". Dist: "
                                + Double.toString(roadDistance);
                    }
                    pathIDs[(int)pathVector.size()-1] = "Total Distance: " + Double.toString(totalDistance);
                    Intent dirList = new Intent(ClusteringDemoActivity.this, TurnByTurnActivity.class);
                    dirList.putExtra("path", pathIDs);
                    startActivity(dirList);

                }

            }
        });

        clearButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                startID = -1;
                startText.setText(" Start: ");
                endID = -1;
                endText.setText(" End: ");
                pathVector.clear();
                getMap().moveCamera(CameraUpdateFactory.newLatLng(getMap().getCameraPosition().target));
                turnByTurn = 0;
                goButton.setText("Go!");
            }
        });

    }

    private class ProgressTask extends AsyncTask<Void,Void,Void> {
        @Override
        protected void onPreExecute(){
            bar.setVisibility(View.VISIBLE);
        }

        @Override
        protected Void doInBackground(Void... arg0) {
            DijkstraWrap.Dijkstra(nodeVector, pathVector, nodeVector.get(startID), nodeVector.get(endID));
           // getMap().moveCamera(CameraUpdateFactory.newLatLng(getMap().getCameraPosition().target));

            return null;
        }

        @Override
        protected void onPostExecute(Void result) {
            bar.setVisibility(View.GONE);
            getMap().moveCamera(CameraUpdateFactory.newLatLng(getMap().getCameraPosition().target));

        }
    }
}


