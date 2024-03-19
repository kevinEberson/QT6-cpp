import QtQuick 2.15

Item {
    property string fontColor: "#f0eded"

    Connections {
        target: audioController
        function onVolumeLevelChanged() {
            volumeIcon.visible = false
            visibilityTimer.stop()
            visibilityTimer.start()
        }
    }

    Timer {
        id: visibilityTimer
        interval: 1000
        repeat: false
        onTriggered: {
            volumeIcon.visible = true
        }
    }

    width: 111 * (parent.width / 1280)

    Rectangle {
        id: decrementButton

        anchors {
            right: volumeIcon.left
            rightMargin: 15
            top: parent.top
            bottom:  parent.bottom
        }

        width: height / 2
        color: "black"

        Text {
            id: decrementText
            color: fontColor
            anchors.centerIn: parent
            text: "<"
            font.pixelSize: 12
        }
        MouseArea {
            anchors.fill: parent
            onClicked: audioController.changeVolume(-1)
        }
    }

    Image {
        id: volumeIcon
        height: parent.height * .35
        fillMode: Image.PreserveAspectFit

        anchors {
            right: incrementButton.left
            rightMargin: 15
            verticalCenter: parent.verticalCenter
        }

        source: {
            if (audioController.volumeLevel <= 1)
            {
                return "../assets/mute.png"
            }
            else if (audioController.volumeLevel <= 25)
            {
                return "../assets/volume1.png"
            }
            else if (audioController.volumeLevel <= 50)
            {
                return "../assets/volume2.png"
            }
            else
            {
                return "../assets/volume3.png"
            }
        }
    }

    Text {
        id: volumeTextLabel
        visible: !volumeIcon.visible

        anchors {
            centerIn: volumeIcon
        }

        color: fontColor
        font.pixelSize: 24
        text: audioController.volumeLevel
    }

    Rectangle {
        id: incrementButton

        anchors {
            right: parent.right
            top: parent.top
            bottom:  parent.bottom
        }

        width: height / 2
        color: "black"

        Text {
            id: incrementText
            color: fontColor
            anchors.centerIn: parent
            text: ">"
            font.pixelSize: 12
        }
        MouseArea {
            anchors.fill: parent
            onClicked: audioController.changeVolume(1)
        }
    }
}
