package com.google.maps.android.utils.demo;

import android.app.TabActivity;
import android.content.Intent;
import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TabHost;

import java.util.ArrayList;
import java.util.List;

/**
 * This activity allows you to have multiple views (in this case two {@link ListView}s)
 * in one tab activity.  The advantages over separate activities is that you can
 * maintain tab state much easier and you don't have to constantly re-create each tab
 * activity when the tab is selected.
 */
public class PathTabs extends TabActivity implements TabHost.OnTabChangeListener {

    private static final String LIST1_TAB_TAG = "Path 1";
    private static final String LIST2_TAB_TAG = "Path 2";
    private static final String LIST3_TAB_TAG = "Path 3";

    // The two views in our tabbed example
    private ListView listView1;
    private ListView listView2;
    private ListView listView3;

    private TabHost tabHost;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_path_tabs2);

        tabHost = getTabHost();
        tabHost.setOnTabChangedListener(this);

        Intent map = getIntent();
        Bundle extras = map.getExtras();

        // setup list view 1
        listView1 = (ListView) findViewById(R.id.list1);
        String[] path1 = extras.getStringArray("path1");
        listView1.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, path1));

        // setup list view 2
        listView2 = (ListView) findViewById(R.id.list2);
        String[] path2 = extras.getStringArray("path2");
        listView2.setAdapter(new ArrayAdapter(this, android.R.layout.simple_list_item_1, path2));

        listView3 = (ListView) findViewById(R.id.list3);
        String[] path3 = extras.getStringArray("path3");
        listView3.setAdapter(new ArrayAdapter(this, android.R.layout.simple_list_item_1, path3));

        // add views to tab host
        tabHost.addTab(tabHost.newTabSpec(LIST1_TAB_TAG).setIndicator(LIST1_TAB_TAG).setContent(new TabHost.TabContentFactory() {
            public View createTabContent(String arg0) {
                return listView1;
            }
        }));
        tabHost.addTab(tabHost.newTabSpec(LIST2_TAB_TAG).setIndicator(LIST2_TAB_TAG).setContent(new TabHost.TabContentFactory() {
            public View createTabContent(String arg0) {
                return listView2;
            }
        }));
        tabHost.addTab(tabHost.newTabSpec(LIST3_TAB_TAG).setIndicator(LIST3_TAB_TAG).setContent(new TabHost.TabContentFactory() {
            public View createTabContent(String arg0) {
                return listView3;
            }
        }));

    }

    /**
     * Implement logic here when a tab is selected
     */
    public void onTabChanged(String tabName) {
        if(tabName.equals(LIST2_TAB_TAG)) {
            //do something
        }
        else if(tabName.equals(LIST1_TAB_TAG)) {
            //do something
        }
        else if(tabName.equals(LIST3_TAB_TAG)) {
            //do something
        }
    }
}
