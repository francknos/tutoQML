import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtCharts 2.13
import CPP.Team 1.0

Window {
    id: root
    width: 800
    height: 800
    visible: true
    title: qsTr("Hello World")


    ColumnLayout {
        anchors.fill: parent
        spacing: 5
        Rectangle {
            //anchors.fill: parent
            Layout.preferredWidth: 50//parent.width
            Layout.preferredHeight: 50//parent.height
            Layout.alignment: Qt.AlignCenter
            color: "#FF0000"
        }

        Rectangle {
           // anchors.fill: parent
            Layout.preferredWidth: 50//parent.width
            Layout.preferredHeight: 50//parent.height
            Layout.alignment: Qt.AlignCenter
            color: "#00FF00"
        }
    }


    Rectangle {
        id: bottom_message
        color: "#FF0000"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 200
        //clip: true
        Text {
            id: teams
            anchors.fill:parent
            bottomPadding: 5

            text: qsTr("Franck FURIC, Jean-Marie REMOLEUR, François WIBAUX, Vincent CHATELIN, Pierre-Yves LENAOUR")
            wrapMode: Text.WordWrap
            font.pointSize: 30
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: top_message
        color: "#FF00AA"
        anchors.top: parent.top
        radius: 10
        anchors.horizontalCenter: parent.horizontalCenter
        height: 80
        width: 300
        clip: true
        Text {
            id: teams2
            text: SoftTeam.getRndTeamNames()
            font.pointSize: 20
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            verticalAlignment: Text.AlignVCenter

            PropertyAnimation on x
            {
                id: anim_text
                from: top_message.width
                to: -teams2.width + top_message.width
                duration: 6000
                //running: false
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                teams2.text = SoftTeam.getRndTeamNames()
                //anim_text.start()
            }
        }
    }

    function showArray(e)
    {
        console.log("Show Array")
        for(var i in e)
            console.log(e[i])
    }
}


