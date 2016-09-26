import QtQuick 2.5
import QtQuick.Window 2.2
import com.ink.qmlcomponents 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property int pluginvalue: 200


    CQMLExtendPlugin{
        width: 100
        height: 100
        Rectangle
        {
            id: idplugin
            anchors.fill: parent
            color:"red"

        }

        MouseArea {
            anchors.fill: parent
            onClicked: {

                idtext.text = 'button clicked'
                idtext.color ='black'
            }

        }
    }

    Text {

        id:idtext
        color: "#e53030"
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
