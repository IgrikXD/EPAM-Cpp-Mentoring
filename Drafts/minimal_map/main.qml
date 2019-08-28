/****************************************************************************

 Copyright (C) 2017 The Qt Company Ltd.
 Contact: https://www.qt.io/licensing/

 This file is part of the examples of the Qt Toolkit.

 $QT_BEGIN_LICENSE:BSD$
 Commercial License Usage
 Licensees holding valid commercial Qt licenses may use this file in
 accordance with the commercial license agreement provided with the
 Software or, alternatively, in accordance with the terms contained in
 a written agreement between you and The Qt Company. For licensing terms
 and conditions see https://www.qt.io/terms-conditions. For further
 information use the contact form at https://www.qt.io/contact-us.

 BSD License Usage
 Alternatively, you may use this file under the terms of the BSD license
 as follows:

 "Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of The Qt Company Ltd nor the names of its
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.


 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."

 $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Controls 2.5

Window {
    id: window
    width: 512
    height: 512
    visible: true
    title: qsTr("Radiosonde finder")

    Plugin {
        id: mapPlugin
        name: "osm"
    }  

    Map {
        id: target_map
        anchors.fill: parent
        plugin: mapPlugin
        center: start
        zoomLevel: 14


        MapPolyline {
            id: main_path
            visible: true
            line.width: 3
            line.color: 'green'
        }

        MapPolyline {
            id: predicted_path
            visible: true
            line.width: 3
            line.color: 'blue'
        }

        MapQuickItem {
             id: last_frame
             coordinate: QtPositioning.coordinate(52.0101, 23.8276)

             anchorPoint.x: image1.width * 0.5
             anchorPoint.y: image1.height

             sourceItem: Column {
             Image {id:image1; source: "marker.png" }
             Text { text: "Last data point"; font.bold: true }
             }
        }

        MapQuickItem {
             id: landing_point
             coordinate: QtPositioning.coordinate(52.0132, 23.8253)

             anchorPoint.x: image2.width * 0.5
             anchorPoint.y: image2.height

             sourceItem: Column {
             Image {id: image2; source: "marker.png" }
             Text { text: "Landing point"; font.bold: true }
             }
        }

        Column {
            spacing: 2

            Switch {
                text: "Show sonde route"
                checked: true
                onToggled: {
                    if (main_path.visible == true) {
                        main_path.visible = false
                        last_frame.visible = false
                    }

                    else {
                        main_path.visible = true
                        last_frame.visible = true
                    }
                }
            }

            Switch {
                text: "Show predicted route"
                checked: true
                onToggled: {
                    if (predicted_path.visible == true) {
                        predicted_path.visible = false
                        landing_point.visible = false
                    }
                    else {
                        predicted_path.visible = true
                        landing_point.visible = true
                    }
                }
            }
        }

        Grid {
            x: 4; anchors.bottom: target_map.bottom; anchors.bottomMargin: 20
            rows: 1; columns: 2; spacing: 3

            //Button { butText: "Finish"; onClicked: target_map.center = QtPositioning.coordinate(52.0101, 23.8276)}
            Button {
                text: "Finish";
                height: 25
                width: 60
                onClicked: target_map.center = QtPositioning.coordinate(52.0101, 23.8276)
            }
            //Button { butText: "Start"; onClicked: target_map.center = QtPositioning.coordinate(52.1211, 23.6738)}
            Button {
                text: "Start";
                height: 25
                width: 60
                onClicked: target_map.center = QtPositioning.coordinate(52.1211, 23.6738)
            }
        }

        Grid {
            x: 448; anchors.bottom: target_map.bottom; anchors.bottomMargin: 20
            rows: 1; columns: 1;

            //Button { butText: "Exit"; onClicked: Qt.quit()}
            Button {
                text: "Close";
                height: 25
                width: 60
                onClicked: Qt.quit()
            }
        }

        Component.onCompleted: {
            var lines = []
            for (var i = 0; i < geopath.size(); i++){

                lines[i] = geopath.coordinateAt(i);

            }
            main_path.path = lines

            var lines_2 = []
            for (i = 0; i < predicted.size(); i++){

                lines_2[i] = predicted.coordinateAt(i);

            }
            predicted_path.path = lines_2


        }
    }
}
