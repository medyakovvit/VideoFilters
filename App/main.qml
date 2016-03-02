import QtQuick 2.3
import QtQuick.Controls 1.2
import QtMultimedia 5.5
import QtQuick.Layouts 1.1

import my.filters 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Camera{
        id: camera
    }

    FiltersModel{
        id: filtersModel
    }

    ColumnLayout{
        anchors.fill: parent

        RowLayout{

            Slider{
                id: threshSlider
                maximumValue: 255.0
                minimumValue: 0.0
                value: 150.0
                stepSize: 1.0

                height: 30
            }

            Button{
                id: btnAddFilter
                text: qsTr("Add Threshold")

                onClicked: filtersModel.addFilter()
            }
        }

        VideoOutput{
            id: vo
            source: camera
            filters: filtersModel.filters
        }
    }
}

