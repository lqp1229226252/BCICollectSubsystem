import QtQuick 2.0

import QtQuick.Controls 2.0

Item{
    property var times: 0

    function setTimes(values){
        times = values
    }

    id: element
    property bool flicker: false
    Text {
        id: gameTime
        text: times
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.underline: false
        font.italic: true
        font.bold: true
        font.pointSize: 40

    }

    ProgressBar {
        id: progressBar
        width: 500
        height: 15
        anchors.bottom: gameTime.verticalCenter
        anchors.bottomMargin: -50
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: "Courier"
        value: 1


        background: Rectangle {   //背景项
            implicitWidth: progressBar.width
            implicitHeight: progressBar.height
//            color: "#ebedee"
            color: "#4facfe"
            radius: 50 //圆滑度
        }

        contentItem: Item {   //内容项
            Rectangle {
                id:frontColor
                width: progressBar.visualPosition * progressBar.width
                height: progressBar.height
                radius: 50
                color: "#ebedee"
                opacity: 0.2
                SequentialAnimation {

                    id: scrollingAnimation
                    running: true
                    loops: Animation.Infinite

                    PropertyAnimation {
                        target: frontColor
                        property: "x"
                        to: progressBar.width
                        duration: 2000
                        easing.type: Easing.Linear
                    }

                    PropertyAnimation {
                        target: frontColor
                        property: "x"
                        to: 0
                        duration: 0
                    }
                }
            }
        }

    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2;anchors_height:15;anchors_width:500}
}
##^##*/
