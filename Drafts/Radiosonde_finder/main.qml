import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: "Radiosonde finder"

    ColumnLayout {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.leftMargin: 140

        TextField {
            id: newSondeId
            Layout.preferredWidth: 100
            Layout.preferredHeight: 25
            width: 100
            height: 25
            placeholderText: "Enter sonde ID"
        }

        Button {
            Layout.preferredWidth: 100
            Layout.preferredHeight: 25
            text: "Add"
            onClicked: {
                radiosondesList.receiveId(newSondeId.text)
                newSondeId.text = ""
            }
        }

        Button {
            Layout.preferredWidth: 100
            Layout.preferredHeight: 25
            text: "Write to file"
            onClicked: radiosondesList.writeToFile()
        }

        Button {
            Layout.preferredWidth: 100
            Layout.preferredHeight: 25
            text: "Close"
            onClicked: Qt.quit()
        }
    }

    ColumnLayout {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.leftMargin: 10

        Label { text: "List of radiosondes:" }

        Rectangle {
            width: 110
            height: 100

            Component {
                id: radiosondeListDelegate

                Item {
                    width: 110
                    height: 20

                    Column {

                        Text {
                            anchors.fill: parent
                            anchors.leftMargin: 5
                            text: modelData
                        }
                    }
                }
            }

            ListView {
                clip: true
                anchors.fill: parent
                model: radiosondesList.id_list
                delegate: radiosondeListDelegate
                //highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                focus: true
            }
        }
    }
}
