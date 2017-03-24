import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 300
    title: qsTr("Text Auto Scrool")
    Rectangle {
        width: 131; height: 25
        color: "red"
        clip:true
        anchors.centerIn: parent

        Text
        {
            id:idtext
            //width: parent.width
            height:parent.height
            text:"123456789abcdefghijklmnopqrstuvwxyz"
            color:"yellow"
            verticalAlignment: Text.AlignVCenter

            SequentialAnimation on x {
                loops: Animation.Infinite

                PropertyAnimation {
                    from:0
                    to: -idtext.width
                    duration: 5000
                }
            }

        }
    }


}
