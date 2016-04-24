package com.google.maps.android.utils.demo;

import android.content.Context;
import android.util.Log;

import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.google.maps.android.clustering.Cluster;
import com.google.maps.android.clustering.ClusterManager;
import com.google.maps.android.clustering.view.DefaultClusterRenderer;

/**
 * Created by Patrick on 4/15/16.
 */
class MyClusterRenderer extends DefaultClusterRenderer<MyItem> {

    public GoogleMap mMap;

    public MyClusterRenderer(Context context, GoogleMap map,
                             ClusterManager<MyItem> clusterManager) {
        super(context, map, clusterManager);
        mMap = map;
    }

    @Override
    protected void onBeforeClusterItemRendered(MyItem item, MarkerOptions markerOptions) {
        super.onBeforeClusterItemRendered(item, markerOptions);

       // markerOptions.title(item.getTitle());
    }

    @Override
    protected void onClusterItemRendered(MyItem clusterItem, Marker marker) {
        super.onClusterItemRendered(clusterItem, marker);

        //marker.setTitle("TEST");

        ClusteringDemoActivity demo = new ClusteringDemoActivity();
        Log.d("Renderer Demo",Integer.toString(demo.getEndID()));
        Log.d("Renderer Cluster",Integer.toString(clusterItem.getID()));
        if(demo.getStartID() != -1 && clusterItem.getID() == demo.getStartID()) {
            marker.setIcon(BitmapDescriptorFactory
                    .defaultMarker(BitmapDescriptorFactory.HUE_ORANGE ));
            /*marker.setTitle("Start " + "Node: " + Integer.toString(clusterItem.getID()) + ", Latitude: "
                    + Double.toString(marker.getPosition().latitude) +
                    ", Longitude: " + Double.toString(marker.getPosition().longitude));
            marker.showInfoWindow();*/
        }
        if(demo.getEndID() != -1 && clusterItem.getID() == demo.getEndID()) {
            marker.setIcon(BitmapDescriptorFactory
                    .defaultMarker(BitmapDescriptorFactory.HUE_VIOLET));
           /* marker.setTitle("End " + "Node: " + Integer.toString(clusterItem.getID()) + ", Latitude: "
                    + Double.toString(marker.getPosition().latitude) +
                    ", Longitude: " + Double.toString(marker.getPosition().longitude));
            marker.showInfoWindow();*/
        }
        if(demo.geClickedID() != -1 && demo.geClickedID() == clusterItem.getID()){
            marker.setTitle( "Node: " + Integer.toString(clusterItem.getID()) + ", Latitude: "
                    + Double.toString(marker.getPosition().latitude) +
                    ", Longitude: " + Double.toString(marker.getPosition().longitude));
            marker.showInfoWindow();
        }

        //here you have access to the marker itself
    }

}