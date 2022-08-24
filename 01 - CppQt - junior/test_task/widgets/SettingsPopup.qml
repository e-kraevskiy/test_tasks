import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

// Появляющееся окно настройки программы
Popup {
    id: root

    property int time_set: 0

    width: parent.width / 3.5
    height: parent.height / 6
    anchors.centerIn: parent
    closePolicy: Popup.CloseOnPressOutside
    modal: true
    visible: true

    background: Rectangle {
        anchors.fill: parent
        radius: 10
        color: "gray"

        ColumnLayout {
            anchors.fill: parent
            spacing: 3

            Button {
                Layout.alignment: Qt.AlignRight | Qt.AlignTop
                Layout.preferredWidth: parent.width / 4
                Layout.preferredHeight: parent.height / 5
                Layout.margins: 5
                text: "Закрыть"

                onClicked: {
                    root.close()
                }
            }
            RowLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.leftMargin: 5
                Layout.rightMargin: 5
                Layout.margins: 5
                spacing: 10

                Item {
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width * 0.8

                    Text {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        text: "Введите интервал времени, сек "
                    }
                }
                TextField {
                    id: second_amount__text_field
                    Layout.fillWidth: true
                    Layout.preferredHeight: root.height / 4
                    selectionColor: "grey"
                    text: time_set.toString()
                    validator: RegExpValidator {
                        regExp: /\d{1,3}/
                    }
                }
            }

            RowLayout {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height / 4

                Button {
                    Layout.fillHeight: true
                    Layout.margins: 5
                    text: "Выбрать папку"

                    onClicked: {
                        file_dialog.title = "Выберите папку"
                        file_dialog.selectFolder = true;
                        file_dialog.open()
                    }
                }
                Button {
                    Layout.fillHeight: true
                    Layout.margins: 5
                    text: "Открыть файл"

                    onClicked: {
                        file_dialog.title = "Выберите файл"
                        file_dialog.selectFolder = false;
                        file_dialog.open()
                    }
                }
                Button {
                    Layout.fillHeight: true
                    Layout.margins: 5
                    text: "Применить"

                    onClicked: {
                        mouse_handler_.setTime(
                                    parseInt(second_amount__text_field.text))
                    }
                }
            }
        }
    }
} //~Popup
