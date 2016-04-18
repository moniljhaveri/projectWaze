package com.google.maps.android.utils.demo;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;

public class TurnByTurnActivity extends ListActivity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        setContentView(R.layout.turnbyturn_view);

        ListAdapter adapter = createAdapter();
        setListAdapter(adapter);
    }

    /**
     * Creates and returns a list adapter for the current list activity
     * @return
     */
    protected ListAdapter createAdapter()
    {
        Intent map = getIntent();
        Bundle extras = map.getExtras();
        String[] path = extras.getStringArray("path");
        ListAdapter adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, path);
        return adapter;
    }
}