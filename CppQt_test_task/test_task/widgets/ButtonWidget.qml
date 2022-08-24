import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

Item {
    id: root

    anchors.top: parent.top
    anchors.left: parent.left
    Button {
        id: setting__button
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10

        text: "Настройки"

        background: Rectangle {
            radius: 5
            color: "gray"
            opacity: 0.8
        }

        onClicked: {
            settings__popup.open()
        }
    }

    Button {
        id: save__button
        anchors.top: parent.top
        anchors.left: setting__button.right
        anchors.margins: 10

        text: "Сохранить"

        background: Rectangle {
            radius: 5
            color: "gray"
            opacity: 0.8
        }

        onClicked: {
            if (file_module_.getDirPath() === "") {
                notify__popup.message = "Не выбрана папка"
                notify__popup.open()
                return
            }
            file_module_.seveResult()
        }
    }

    Button {
        id: start__button
        anchors.top: parent.top
        anchors.left: save__button.right
        anchors.margins: 10

        text: "Начать"

        background: Rectangle {
            radius: 5
            color: "gray"
            opacity: 0.8
        }

        onClicked: {
            if (mouse_handler_.time === 0) {
                notify__popup.message = "Не выбран интервал времени"
                notify__popup.open()
                return
            }
            left__timer.start()
            mouse_handler_.initMousePos(mouse_area.mouseX, mouse_area.mouseY)
            mouse_handler_.startTimer()
        }
    }
}
