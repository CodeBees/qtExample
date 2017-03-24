import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("AbstractTableModel")
    id:rootWindow

    Dialog {
        id: filledDialog
        modality: Qt.WindowModal
        title: "Customized content"
        onRejected: {}
        onAccepted: {}
        onButtonClicked:{ if (clickedButton === StandardButton.Retry);
        }
        contentItem: Rectangle {
            color: "lightskyblue"
            implicitWidth: 400
            implicitHeight: 100
            Label {
                text: "点选了某个数据"
                color: "navy"
                anchors.centerIn: parent
            }
            Keys.onPressed: if (event.key === Qt.Key_R && (event.modifiers & Qt.ControlModifier)) filledDialog.click(StandardButton.Retry)
            Keys.onEnterPressed: filledDialog.accept()
            Keys.onEscapePressed: filledDialog.reject()
            Keys.onBackPressed: filledDialog.reject() // especially necessary on Android
        }
    }



    TableView
    {

        width: parent.width
        height:parent.height

        TableViewColumn
        {
            role:"name"
            title:"Name"

        }

        TableViewColumn{
            role:"sex"
            title:"Sex"
            delegate: Text{
                text: styleData.value;
                verticalAlignment: Text.AlignVCenter;
                horizontalAlignment: Text.AlignLeft;

                MouseArea {
                    anchors.fill: parent;
                    onClicked: {
                        filledDialog.open();
                    }
                }
            }

        }

        model:paremTableViewModel

    }

}
