import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width:400
    height: 300
    property alias comboBox1: comboBox1
    title: qsTr("Hello World")

    MouseArea {
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }

        Button {
            id: button1
            x: 31
            y: 27
            width: 121
            height: 37
            text: qsTr("Button")
            KeyNavigation.tab: checkBox1
        }

        Button {
            id: button2
            x: 31
            y: 80
            width: 121
            height: 38
            text: qsTr("Button")
             KeyNavigation.tab: comboBox1
        }

        CheckBox {
            id: checkBox1
            x: 31
            y: 134
            width: 104
            height: 15
            text: qsTr("Check Box")
             KeyNavigation.tab: button2

        }

        ComboBox {
            id: comboBox1
            x: 31
            y: 164
            width: 125
            height: 33
            z: 1
        }

        ComboBox {
            id: comboBox2
            x: 31
            y: 218
            width: 125
            height: 34
        }

        GroupBox {
            id: groupBox1
            x: 13
            y: 0
            width: 324
            height: 284
            title: qsTr("Tab 顺序 ")
        }


    }


}
