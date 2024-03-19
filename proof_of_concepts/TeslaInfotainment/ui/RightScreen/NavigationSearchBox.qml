import QtQuick 2.15

Rectangle {
    id: navSearchBox
    radius: 5
    color: "#f0f0f0"

    Image {
        id: searchIcon

        anchors {
            left: parent.left
            leftMargin: 25
            verticalCenter: parent.verticalCenter
        }

        height:  parent.height * .45
        fillMode: Image.PreserveAspectFit

        source: "../assets/search.png"
    }

    Text {
        id: navigationPlaceHolderText
        color: "#808080"
        text: "Navigate"

        anchors {
            verticalCenter: parent.verticalCenter
            left: searchIcon.right
            leftMargin: 20
        }

        visible: navigationTextInput.text === ""
    }

    TextInput {
        id: navigationTextInput
        clip: true

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: searchIcon.right
            leftMargin: 20
        }

        verticalAlignment: Text.AlignVCenter
        color: "#808080"
        font.pixelSize: 16
    }
}
