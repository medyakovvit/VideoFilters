import QtQuick 2.0
import QtQuick.Layouts 1.1

Component {

    Loader{
        //width: ListView.view.width
        source: qmlFile
        property var videoFilter: filter
    }
}
