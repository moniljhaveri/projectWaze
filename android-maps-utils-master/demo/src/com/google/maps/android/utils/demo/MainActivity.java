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

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.google.maps.android.clustering.Cluster;

import android.os.Handler;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("NodeWrap");
    }

    static {
        System.loadLibrary("SmoothSortWrap");
    }

    static {
        System.loadLibrary("DijkstraWrap");
    }

    static {
        System.loadLibrary("K_PathsWrap");
    }

    private final int SPLASH_DISPLAY_LENGTH = 1000;
    /** Duration of wait **/

   /* @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        //mListView = (ViewGroup) findViewById(R.id.list);

        Intent clusterIntent= new Intent(MainActivity.this, ClusteringDemoActivity.class);
        startActivity(clusterIntent);

    }*/

    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        setContentView(R.layout.main);
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                /* Create an Intent that will start the Menu-Activity. */
                Intent mainIntent = new Intent(MainActivity.this, ClusteringDemoActivity.class);
                MainActivity.this.startActivity(mainIntent);
                MainActivity.this.finish();
            }
        }, SPLASH_DISPLAY_LENGTH);
    }
}






