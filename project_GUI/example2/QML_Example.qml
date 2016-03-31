import QtQuick 2.3

Rectangle{
    id: page
    width: 320; height: 480
    color: "blue"

    Text{

        id: helloText
        text: "Hello world!"
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }
}
