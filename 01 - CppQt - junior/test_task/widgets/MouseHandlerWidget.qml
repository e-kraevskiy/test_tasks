import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Item {
    id: root

    property int x_coordinate: 0
    property int y_coordinate: 0
    property int distance: 0

    Connections {
        target: mouse_handler_
        function onUpdateTime(time) {
            time_set__text.text = time.toString()
            settings__popup.time_set = time
        }
        function onUpdateTimeLeft(time_left) {
            left_time__text.text = time_left.toFixed(2)
        }
        function onUpdateDistance(distance) {
            distance__text.text = distance.toString()
        }
    }

    anchors.top: parent.top
    anchors.right : parent.right
    anchors.margins: 10
    width: parent.width / 4
    height: parent.height / 6


    Rectangle {
        anchors.fill: parent
        radius: 10
        color: "gray"
        opacity: 0.8

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 5

            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 6
                Text {
                    horizontalAlignment: Text.AlighRight
                    verticalAlignment: Text.AlignVCenter
                    text: "Координата X ="
                }
                Text {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: x_coordinate.toString()
                }

            }
            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 6
                Text {
                    horizontalAlignment: Text.AlighRight
                    verticalAlignment: Text.AlignVCenter
                    text: "Координата Y = "
                }
                Text {
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: y_coordinate.toString()
                }
            }
            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 6
                Text {
                    horizontalAlignment: Text.AlighRight
                    verticalAlignment: Text.AlignVCenter
                    text: "Установленное время = "
                }
                Text {
                    id: time_set__text
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: "0"
                }
                Text {
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: "сек"
                }
            }
            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 6
                Text {
                    horizontalAlignment: Text.AlighRight
                    verticalAlignment: Text.AlignVCenter
                    text: "Оставшееся время = "
                }
                Text {
                    id: left_time__text
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: "0"
                }
                Text {
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: "сек"
                }
            }
            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 6
                visible: (mouse_handler_.distance !== 0)
                Text {
                    horizontalAlignment: Text.AlighRight
                    verticalAlignment: Text.AlignVCenter
                    text: "Пройденное расстояние = "
                }
                Text {
                    id: distance__text
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: "0"
                }
                Text {
                    horizontalAlignment: Text.AlighLeft
                    verticalAlignment: Text.AlignVCenter
                    text: "пикселей"
                }
            }
        }
    }
}
