import QtQuick 2.5
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

            ListView{
                width: 200
                height: 200
                model: filtersModel
                delegate: delegate
            }

            FiltersListViewDelegate{
                id: delegate
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

