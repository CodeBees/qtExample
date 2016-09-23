import QtQuick 2.0
import QtQuick.Controls 1.0

Rectangle {
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }

    Button {
        id: button1
        x: 62
        y: 30
        width: 126
        height: 36
        text: qsTr("Button")
    }


}


