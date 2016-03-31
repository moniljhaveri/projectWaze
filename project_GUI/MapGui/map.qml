import QtQuick 2.3
import QtQuick.Window 2.2
import QtPositioning 5.5
import QtLocation 5.5

Rectangle {
    width: 400
    height: 400
    Plugin {
        id: mapPlugin
        name: "osm"
    }
    PositionSource {
        id: positionSource
        //property variant
    }
    /*PlaceSearchModel{
        id: nodeModel
        plugin: mapPlugin

        searchTerm "Pizza"
        searchArea: QtPositioning.coordinate(38.575764, -121.478851)
        Component.onCompleted: update()
    }*/



    property variant  locationCali: QtPositioning.coordinate(38.575764, -121.478851)
    Map{
        id: map
        anchors.fill: parent
        plugin: mapPlugin;
        center: locationCali
        zoomLevel: 7

        MapItemView{
            model: nodeModel
            delegate: MapQuickItem{

                anchorPoint.x: image.width * 0.5
                anchorPoint.y: image.height

                sourceItem: Column{
                    Image { id: image; source: "marker.png" }
                    }

                }
            Component.onCompleted: coordinate = map.toCoordinate(QtPositioning.coordinate(38.575764, -121.478851))

            }
        }



}



