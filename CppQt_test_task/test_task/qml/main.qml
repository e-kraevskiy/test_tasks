import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.1

import widgets 1.0


ApplicationWindow {
    id: main__window

    minimumWidth: 1280
    minimumHeight: 720
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight

    visible: true
    title: qsTr("This is my test progtamm")


    FileDialog {
        id: file_dialog
        property url previousFolder: ""
        folder: shortcuts.home
        selectFolder: true
        onAccepted: {
            if (selectFolder)
                file_module_.setDirPath(file_dialog.fileUrl)
            else
                file_module_.setFilePath(file_dialog.fileUrl)
        }
        //Если пользователь отменил открытие файла (нажал на "отмена")
        onRejected: {
            console.log("Файл не выбран")
        }
    }

    MouseArea {
        id: mouse_area
        anchors.fill: parent
        hoverEnabled: true
        onPositionChanged: {
            mouse_handler__widget.x_coordinate = mouseX
            mouse_handler__widget.y_coordinate = mouseY
        }
    }

    MouseHandlerWidget {
        id: mouse_handler__widget
    }

    SettingsPopup {
        id: settings__popup
    }

    NotifyPopup {
        id: notify__popup
    }

    ButtonWidget {}


    Timer {
        id: left__timer
        interval: 10
        repeat: true
        onTriggered: {
            mouse_handler_.calcMouseDist(mouse_area.mouseX,
                                         mouse_area.mouseY)
            if (!mouse_handler_.isTimerRunning()) {
                left__timer.stop()
            }
        }
    }


    Shortcut {
        sequences: ["Ctrl+Q"]
        onActivated: Qt.quit()
    }

}
