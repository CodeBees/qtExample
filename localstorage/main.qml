import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("localstorage")

    property var localdb

    ListModel {
        id:idListMode
        ListElement {
            name: "testname"
            score: "99.5"
        }
    }


    ColumnLayout {
        id: columnLayout1
        anchors.fill: parent

        Rectangle {
            id: rectangle1
            Layout.fillWidth: true
            Layout.fillHeight: true
            height: 200
            color: "#ffffff"

            ListView
            {
                anchors.fill: parent
                model:idListMode
                delegate: Text {
                    text: name + "        :       " + score
                }

                Component.onCompleted:
                {
                    openDB();
                    getDBData();
                }
            }

        }

        Rectangle {
            id: rectangle2

            Layout.fillWidth: true
            height: 100


            Label {
                id: label1
                x: 91
                y: 35
                width: 101
                height: 21
                text: "姓名"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
            }

            Label {
                id: label2
                x: 91
                y: 62
                width: 101
                height: 21
                text: "成绩"
                wrapMode: Text.WordWrap
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }


            TextField {
                id: idName
                x: 205
                y: 36
                placeholderText: qsTr("")
            }

            TextField {
                id: idScore
                x: 205
                y: 63
                inputMask: "00"

            }

            Button {
                id: button1
                x: 416
                y: 35
                width: 112
                height: 48
                text:"添加"
                onClicked:
                {

                    if((idName.text.length>0)&&(idScore.text.length))
                    {
                        insertDBData(idName.text,idScore.text);
                        idListMode.append({"name":idName.text,"score":idScore.text});
                    }
                    else
                    {
                        console.log("cann't empty");
                    }
                }
            }
        }
    }

    //打开数据库，没有则创建，没有指定表则创建
    function  openDB()
    {
        localdb = LocalStorage.openDatabaseSync("QQmlValueRecordDB", "1.0", "QML LocalStorage", 1000000);

        localdb.transaction(function(tx){

            tx.executeSql('CREATE TABLE IF NOT EXISTS datasheet(name TEXT, score TEXT)');
        })
    }

    //数据库插入数据
    function insertDBData(name,score)
    {
        localdb.transaction(function(tx)
        {
            tx.executeSql('INSERT INTO datasheet VALUES(?,?)', [name,score]);
        })

    }

    //从数据库获取数据
    function getDBData()
    {
        localdb.transaction(function(tx)
        {
            var rs = tx.executeSql('SELECT * FROM datasheet');

            for(var i = 0; i < rs.rows.length; i++)
            {
                idListMode.append({"name":rs.rows.item(i).name,"score":rs.rows.item(i).score});
            }
        })

    }

}
