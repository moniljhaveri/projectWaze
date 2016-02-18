Project WazeApp
===============

In the WazeApp project you’ll have to build an interactive application that
displays California Road Network on a map and enables shortest path queries
on this map.

The road network data consists of 2 datasets. Feifei Li, Dihan Cheng, Marios Hadjieleftheriou, George Kollios and Shang-Hua Teng, “On Trip Planning Queries in
Spatial Databases”, In Proceedings of the 9th International Symposium on Spatial and Temporal Databases (SSTD
’05), 2005.

First dataset stores the road intersection points (nodes) along with their
Longitude and Latitude information. i.e. California Road Network's Nodes (Node
ID, Longitude, Latitude)
		 
Second dataset stores the road data (edges) along with road distances. i.e.
California Road Network's Edges (Edge ID, Start Node ID, End Node ID, L2
Distance)
	 	 
Your WazeApp will display a map of California Road Network and support two
types of queries.

- First, if a user clicks on directions and then clicks on two intersection points in
the map, your app highlight the three shortest paths between those points on
the map as well as displaying the distances of those three paths.
		 
- Second, if a user clicks on an intersection point (a node), your app will highlight
the roads (edges) starting from (adjacent to) that point.
	 	 
Your system will first load the road network in efficient shortest path and
adjacency search amenable data structure(s). Then it will allow users to query
your data structure by i) clicking on intersection points in your map or ii) by
asking for shortest paths between intersection points.

You are free to use any data structure you like for storing the road network. You
must define the complexities of i) building the data structures used for
supporting the two types of queries, ii) running the two types of queries in your
system. Efficient data structure selection & usage will get higher points.



- Develop a GUI, which displays a map of California Road Network and lets users click on
various intersection points on the map and displays the decimal latitude and a decimal
longitude of the clicked point. Also it presents the shortest distance querying UI. 

- Completed project that supports both query types. 

- Project presentations 


Comparative Features


Your WazeApp will be compared against others in the class and ranked according to:

- First: Speed of query operations.

- Second: Cost of building your data structures.

- Third: Usability of your UI.