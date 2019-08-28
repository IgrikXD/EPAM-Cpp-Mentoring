import QtQuick 2.0

Item {
    id: container
    property alias butText: buttonText.text
    signal clicked()

    width: 60; height: 25

    Rectangle {
        id: button
        border.color: "white"
        anchors.fill: parent
        color: "grey"
        opacity: 0.6

        Text {
            id: buttonText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 10; font.bold: false
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: container.clicked()
    }
}
