import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 440
    height: 480
    minimumWidth: 270
    minimumHeight: 190
    visible: true
    title: qsTr("Look All Country !")

    //ListElement {nameCountry: "France"; flag: "fr"}
    ListModel{
        id: monModelDur
        ListElement {nameCountry: "France"; flag: "fr"}
        ListElement {nameCountry: "Espagne"; flag: "es"}
        ListElement {nameCountry: "Angleterre"; flag: "gb"}
        ListElement {nameCountry: "USA"; flag: "us"}
        ListElement {nameCountry: "Allemagne"; flag: "nl"}
        ListElement {nameCountry: "Bellegique"; flag: "be"}
        ListElement {nameCountry: "Bellegique"; flag: "be"}
        ListElement {nameCountry: "France"; flag: "fr"}
        ListElement {nameCountry: "Espagne"; flag: ""}
        ListElement {nameCountry: "Angleterre"; flag: ""}
        ListElement {nameCountry: "USA"; flag: ""}
        ListElement {nameCountry: "Allemagne"; flag: ""}
        ListElement {nameCountry: "Bellegique"; flag: ""}
        ListElement {nameCountry: "France"; flag: ""}
        ListElement {nameCountry: "Espagne"; flag: ""}
        ListElement {nameCountry: "Angleterre"; flag: ""}
        ListElement {nameCountry: "USA"; flag: ""}
        ListElement {nameCountry: "Allemagne"; flag: ""}
        ListElement {nameCountry: "Bellegique"; flag: ""}
        ListElement {nameCountry: "France"; flag: ""}
        ListElement {nameCountry: "Espagne"; flag: ""}
        ListElement {nameCountry: "Angleterre"; flag: ""}
        ListElement {nameCountry: "USA"; flag: ""}
        ListElement {nameCountry: "Allemagne"; flag: ""}
        ListElement {nameCountry: "Bellegique"; flag: ""}
    }

    Component {
        id: listDelegate
        Rectangle{
            id: oneItem
            height: 50
            width: lv.width
            color: lv.currentIndex == index ? "#cf892d" : "lightgrey"

            Row{
                anchors.fill: parent
                anchors.margins: 5
                spacing: 15
                Image {
                    id: flagImg
                    height: parent.height
                    fillMode: Image.PreserveAspectFit
                    //source: "/flag-icons/ad.svg"
                    source: flag
                }
                Text {
                    id: countryTxt
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 32
                    font.bold: lv.currentIndex == index
                    text: country +" " + shortName
                }
            }

            MouseArea{
                anchors.fill: parent
                //onDoubleClicked: monModel.insert(index, {nameCountry:"Item #"+monModel.count})
                onClicked: {
                    console.log("lv.idx", lv.currentIndex, "idx", index)
                    console.log("flag => ",flag)
                    lv.currentIndex = index
                }
            }
        }
    }

    Rectangle{
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: footer.top

            leftMargin: 20
            rightMargin: 20
            topMargin: 5
            bottomMargin: 5
        }

        ListView{
            id: lv
            anchors.fill: parent
            spacing: 5
            model: countryModel
            delegate: listDelegate
            clip: true;

            onCurrentIndexChanged: console.log("Current LV index is now", currentIndex)
        }
    }

    Row {
        id: footer
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        height: 100

        Text {
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
            text: qsTr("Current Selected index:")
        }

        Text {
            id: nameTxt2
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 50
            text: lv.currentIndex
        }
    }
}
