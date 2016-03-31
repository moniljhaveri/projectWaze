import QtQuick 2.3
import QtQuick.Window 2.2
import QtLocation 5.5
import QtPositioning 5.5

Rectangle {
    width: 400
    height: 400
    Plugin {
        id: mapPlugin
        name: "osm"
    }
    PositionSource {
        id: positionSource
        //QtPositioning.coordinate(38.57s5764, -121.478851)
        //property variant
    }
    PlaceSearchModel{
        id: nodeModel
        plugin: mapPlugin

        //searchTerm: "Pizza"
        searchArea: QtPositioning.coordinate(38.575764, -121.478851)
        Component.onCompleted: update()
    }



    property variant  locationCali: QtPositioning.coordinate(38.575764, -121.478851)
    Map{
        id: map
        anchors.fill: parent
        plugin: mapPlugin;
        center: locationCali
        zoomLevel: 7

        MapQuickItem{
            id: marker
            anchorPoint.x: image.width/4
            anchorPoint.y: image.height

            sourceItem: Image{
                id: image
                source: "marker.png"

            }

        }
        Component.onCompleted:{
            marker.coordinate = QtPositioning.coordinate(38.575764, -121.478851)
            //marker.coordinate = QtPositioning.coordinate(40.000000, -121.478851)
            map.addMapItem(marker)

        }



    }
}
/*MapQuickItem{

    }
   /* id: marker
    property alias lastMouseX: markerMouseArea.lastX
    property alias lastMouseY: markerMouseArea.lastY

    anchorPoint.x: image.width/4
    anchorPoint.y: image.height

    sourceItem: Image{
        id: image
        source: "marker.png"
        opacity: markerMouseArea.pressed ? 0.6 : 1.0
        Component.onCompleted:  coordinate = QtPositioning.coordinate(38.575764, -121.478851)
        MouseArea {
            id: markerMouseArea
            property int pressX: -1
            property int pressY: -1
            property int jitterThreshold : 10
            property int lastX: -1
            property int lastY: -1
            anchors.fill: parent
            hoverEnabled: false
            drag.target: marker
            preventStealing: true
        }

            onPressed : {
                map.pressX = mouse.X
                map.pressY = mouse.Y
                map.currentMarker = -1
                for (var i = 0; i< map.markers.length; i++){
                    if (marker == map.markers[i]){
                        map.currentMarker = i
                        break
                    }
                }
            }

            onPressAndHold:{
                if ((Math.abs(map.pressX - mouse.x) < map.jitterThreshold) && (Math.abs(map.pressY - mouse.y) < map.jitterThreshold)) {
                    var p = map.fromCoordinate(marker.coordinate)
                    lastX = p.x
                    lastY = p.y
                    map.showMarkerMenu(marker.coordinate)
                }
              }

            }

            Text{
                id: number
                y: image.height/10
                width: image.width
                color: "white"
                font.bold: true
                font.pixelSize: 14
                horizontalAlignment: Text.AlignHCenter
                Component.onCompleted: {
                    text = map.markerCounter
                }
            }*/





