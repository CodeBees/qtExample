import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal sendMessageSigal(string msg)

    function getMessage(msg)
    {
        label3.text=msg;

        sendMessageSigal.disconnect(getMessage);
    }

    function setLabelText()
    {
         label1.text = "Connections example";
    }

    Rectangle
    {
        color: "#f9f9f9"
        anchors.fill: parent

        Connections
        {
            //qml 连接 qml 中函数
            target: button1;
            onClicked:
            {
                setLabelText();
            }

        }


        Connections
        {
           //qml 连接 c++ 信号
           target:interaction
           onConnectcppsignal:
           {
                label2.text=strMsg;
           }

        }


        Button {
            id: button1
            x: 37
            y: 27
            width: 147
            height: 58
            text: qsTr("1")

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
            font.pointSize: 12
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
            text: qsTr("2")
            onClicked:
            {
                //qml 调用 c++函数
                interaction.test();
            }
        }

        Label {

            id: label2
            x: 202
            y: 91
            width: 371
            height: 58
            color: "#f22c2c"
            text: qsTr("Label")
            style: Text.Normal
            styleColor: "#f20d0d"
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 12
            font.family: "Verdana"
            verticalAlignment: Text.AlignVCenter
        }

        Button {
            id: button3
            x: 37
            y: 163
            width: 147
            height: 58
            text: qsTr("3")

            onClicked:
            {
                sendMessageSigal("qml signal connect with qml fucntion");
            }
        }

        Label {
            id: label3
            x: 202
            y: 163
            width: 371
            height: 58
            color: "#2cf242"
            text: qsTr("Label")
            style: Text.Normal
            styleColor: "#f20d0d"
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 12
            font.family: "Verdana"
            verticalAlignment: Text.AlignVCenter
        }

    }

    Component.onCompleted:
    {
        //qml 信号连接 qml函数
        sendMessageSigal.connect(getMessage);
    }


}
