import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Loader
    {
        sourceComponent: idTextExtend
        height:200
        width:200
    }

    Component
    {
        id:idTextExtend

        Rectangle
        {
            objectName: "TextExtend"

            property string strText:"Hello"

            function setTextString(msg) {

                strText=msg
            }

            Text
            {
                id:idInnerText
                anchors.fill: parent
                text:strText
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color:"red"
            }

        }

    }

}
