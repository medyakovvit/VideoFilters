import QtQuick 2.0

Item {
    width: 200
    height: childrenRect.height

    Rectangle{
        id: title
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        height: 20

        Text{
            anchors.centerIn: parent
            text: qsTr("Rgb2Gray")
        }
    }

    Rectangle{
        anchors.top: title.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 60
        color: "steelblue"

        Text {
            text: qsTr("Rgb2Gray filter")
            anchors.centerIn: parent
        }
    }
}
