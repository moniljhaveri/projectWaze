package com.example.patrick.wazemap;

import android.graphics.Camera;
import android.graphics.Color;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.UiSettings;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.android.gms.maps.model.Polyline;
import com.google.android.gms.maps.model.PolylineOptions;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Vector;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {
    //Needed to use wrapped C++ code
    static {
        System.loadLibrary("NodeWrap");
    }
    static {
        System.loadLibrary("AstarWrap");
    }
    static {
        System.loadLibrary("SmoothSortWrap");
    }
    static {
        System.loadLibrary("DijkstraWrap");
    }

    private GoogleMap mMap;
    private NodeVec nodeVector = new NodeVec();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
        // Read in Node data
        BufferedReader reader;
        try {
            final InputStream file = getAssets().open("cal.cnode.txt");
            reader = new BufferedReader(new InputStreamReader(file));
            String line = reader.readLine();
            while(line != null) {
                String delims = "[ ]+";
                String[] tokens = line.split(delims);
                // tokens[0]  = Node ID, tokens[1] = Longitude, tokens[2] = Latitude
                nodeVector.add(new Node(Integer.parseInt(tokens[0]), Double.parseDouble(tokens[2]), Double.parseDouble(tokens[1])));
                line = reader.readLine();
            }
            file.close();
            reader.close();
        } catch(IOException ioe){
            ioe.printStackTrace();
        }
        // For Testing all Nodes read in
        //Log.d("NodeLength: ", String.valueOf(nodeVector.size()));

        //Read in path
        BufferedReader pathReader;
        try {
            final InputStream pathfile = getAssets().open("cal.cedge.txt");
            pathReader = new BufferedReader(new InputStreamReader(pathfile));
            String pathLine = pathReader.readLine();
            // pathTest for testing all roads read in
            //int pathTest = 0;
            while (pathLine != null) {
                String delims = "[ ]+";
                String[] tokens = pathLine.split(delims);
                // tokens[0]  = Road ID, tokens[1] = Start Node, tokens[2] = End Node, tokens[3] = Distance
                nodeVector.get(Integer.parseInt(tokens[1])).addLinkedNode(Integer.parseInt(tokens[0]),
                        nodeVector.get(Integer.parseInt(tokens[2])), Double.parseDouble(tokens[3]));
                nodeVector.get(Integer.parseInt(tokens[2])).addLinkedNode(Integer.parseInt(tokens[0]),
                        nodeVector.get(Integer.parseInt(tokens[1])), Double.parseDouble(tokens[3]));
                pathLine = pathReader.readLine();
                //pathTest = pathTest+1;

            }
            //Log.d("Pathlen: ", Integer.toString(pathTest));
            pathfile.close();
            pathReader.close();
        } catch(IOException ioe){
                ioe.printStackTrace();
        }
        getAssets().close();
       // Log.d("Pathlen: ", Integer.toString(pathTest));

    }
    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        mMap.setMapType(GoogleMap.MAP_TYPE_NORMAL);
        UiSettings mUiSettings = mMap.getUiSettings();
        mUiSettings.setZoomControlsEnabled(true);

        PathVec pathVec = new PathVec();
        Vector<Marker> markers = new Vector<Marker>(21048);

        // For testing output of Dijkstra - Dijkstra output matches C++ output for the below case - should test additional cases
        // DijkstraWrap.Dijkstra(nodeVector, pathVec, nodeVector.get(0), nodeVector.get(21047));
        // For testing output of Astar - Getting fewer nodes in Android than just running C++ Astar
        AstarWrap.Astar(nodeVector, pathVec, nodeVector.get(0), nodeVector.get(21047), 10.0f, false);

        int counter = 0;
        for(int k = 0; k<pathVec.size(); k++) {
            Log.d("Path: ", Integer.toString(pathVec.get(k).getID()));
            counter = counter + 1;
        }
        Log.d("Total: ", Integer.toString(counter));


        LinkedNodes linkedNodes = new LinkedNodes();
        //Plot first 1000 nodes and roads - Need to change so roads.nodes only visible at certain zoom
        // to prevent performance issues
        for(int j = 0; j<1000; j++) {
            Marker marker = mMap.addMarker(new MarkerOptions().position(new LatLng(nodeVector.get(j).getLat(),
                    nodeVector.get(j).getLon())).title("Node "+nodeVector.get(j).getID()).visible(true));
            markers.add(marker);
            linkedNodes = nodeVector.get(j).getLinkedNodes();
            for(int m = 0; m<linkedNodes.size(); m++) {
                Polyline road = mMap.addPolyline(new PolylineOptions()
                        .add(new LatLng(nodeVector.get(j).getLat(), nodeVector.get(j).getLon()),
                                new LatLng(linkedNodes.get(m).getNode().getLat(), linkedNodes.get(m).getNode().getLon()))
                        .width(5)
                        .color(Color.RED));
            }
        }
        mMap.moveCamera(CameraUpdateFactory.newLatLng(new LatLng(nodeVector.get(0).getLat(), nodeVector.get(0).getLon())));

    }


}


