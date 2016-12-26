import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    function setLabelText()
    {
         label1.text = "Connections example";
    }

    Rectangle
    {
        anchors.fill: parent
        color:"#888888"

        Connections
        {
            target: button1;

            onClicked:
            {
                setLabelText();
            }

        }

        Button {
            id: button1
            x: 37
            y: 27
            width: 147
            height: 58
            text: qsTr("Button")

        }

        Label {
            id: label1
            x: 202
            y: 27
            width: 371
            height: 58
            color: "#2c7af2"
            text: qsTr("Label")
            font.family: "Verdana"
            font.pointSize: 26
            style: Text.Normal
            styleColor: "#f20d0d"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Button {
            id: button2
            x: 37
            y: 91
            width: 147
            height: 58
            text: qsTr("Button")
        }

        Label {
            id: label2
            x: 202
            y: 91
            width: 371
            height: 58
            color: "#2c7af2"
            text: qsTr("Label")
            style: Text.Normal
            styleColor: "#f20d0d"
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 26
            font.family: "Verdana"
            verticalAlignment: Text.AlignVCenter
        }




    }

}
