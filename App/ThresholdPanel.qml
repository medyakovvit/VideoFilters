import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    width: 200
    height: childrenRect.height

    property var videoFilter

    Rectangle{
        id: title
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top

        height: 20

        RowLayout{
            anchors.fill: parent

            Text{
                anchors.centerIn: parent
                text: qsTr("Threshold")
                Layout.fillWidth: true
            }

            Rectangle{
                height: title.height-4
                width: height
                color: "green"

                MouseArea{
                    anchors.fill: parent
                    onClicked: adjustersPanel.state = "expanded"
                }
            }

            Rectangle{
                height: title.height-4
                width: height
                color: "red"

                MouseArea{
                    anchors.fill: parent
                    onClicked: adjustersPanel.state = ""
                }
            }
        }
    }

    Rectangle{
        id: adjustersPanel
        anchors.top: title.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        color: "steelblue"

        ColumnLayout{
            anchors.fill: parent
            anchors.margins: 5

            RowLayout{
                Text {
                    id: panelText
                    text: qsTr("Threshold:")
                    opacity: 0
                }

                Text{
                    id: thresholdValue
                    text: thresholdSlider.value
                    horizontalAlignment: Text.AlignRight
                    opacity: 0

                    Layout.fillWidth: true
                }
            }

            Slider{
                id: thresholdSlider
                maximumValue: 255.0
                minimumValue: 0.0
                stepSize: 1.0
                value: 150.0

                opacity: 0
                onValueChanged: filter.threshold = value
                Layout.fillWidth: true
            }
        }

        states: [
            State {
                name: "expanded"
                PropertyChanges {target: adjustersPanel; height: 60}
                PropertyChanges {target: panelText; opacity: 1}
                PropertyChanges {target: thresholdValue; opacity: 1}
                PropertyChanges {target: thresholdSlider; opacity: 1}
            }
        ]

        transitions: [
            Transition {
                NumberAnimation {
                    duration: 100;
                    properties: "height"
                }
            }
        ]
    }
}
