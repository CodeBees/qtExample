import QtQuick 2.7
import QtQuick.Controls 1.5

//目录的导入
import "./qml" as QLL

import "./qml2"

import "https://www.codebee.cc/components"

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    QLL.UserDefineRect{
        x:20
        y:20
        width:200
        height: 400
    }

    RedRect{
        x:230
        y:20
        width:200
        height: 400
    }
}
