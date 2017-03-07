import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

import on.someedit 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Some Edition")

    // Image
    Rectangle {
        FilterableImage {
            id: image
        }

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: loadButton.top

        color: "lightsteelblue"
    }

    // LoadButton
    Button {
        id: loadButton
        text: "Load File"

        anchors.left: parent.left
        anchors.bottom: parent.bottom

        width: 90
        height: 90
    }

    // Effect Slider
    Slider {
        id: slider
        value: 0.5

        anchors.left: loadButton.right
        anchors.right: saveButton.left
        anchors.top: loadButton.top
        anchors.bottom: parent.bottom

        onValueChanged: image.level = value;
    }

    // SaveButton
    Button {
        id: saveButton
        text: "Save File"

        anchors.right: parent.right
        anchors.bottom: parent.bottom

        width: 90
        height: 90
    }
}
