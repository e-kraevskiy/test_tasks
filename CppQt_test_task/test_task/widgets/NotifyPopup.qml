import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Popup {
    id: root

    property string message: ""

    Connections {
        target: file_module_
        function onAppendNotify(notify_message) {
            settings__popup.close()
            message = notify_message
            root.open()
        }
    }


    width: parent.width / 6
    height: parent.height / 10
    anchors.centerIn: parent
    visible: false
    closePolicy: Popup.CloseOnPressOutside

    background: Rectangle {
        anchors.fill: parent
        radius: 10
        color: "gray"

        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: message
        }
    }
}
