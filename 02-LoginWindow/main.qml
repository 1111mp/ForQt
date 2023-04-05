import QtQuick
import QtQuick.Controls

Instantiator {
    id: instance;

    model: ListModel {
        id: rootModel;
        ListElement {
            title: qsTr("Login");
            width: 280;
            height: 372;
            source: "LoginWindow.qml";
        }
    }

    delegate: Window {
        id: window;
        title: model.title;
        width: model.width;
        height: model.height;
        maximumWidth: model.width;
        maximumHeight: model.height;
        minimumWidth: model.width;
        minimumHeight: model.height;
        visible: true;
        color: model.color ? model.color : "white";


        Loader {
            anchors.fill: parent;
            sourceComponent: Qt.createComponent(model.source);
        }

        Component.onCompleted: {
            console.log("Window onCompleted.");
            model.title === "MainWindow" && rootModel.remove(0);
        }

        Component.onDestruction: {
            console.log("Window onDestruction.");
        }

        onClosing: function(evt) {
            console.log("onClosing");
            rootModel.remove(index);
        }

        function createWindow(info) {
            const { title, width, height, source } = info;
            rootModel.append({ title, width, height, source });
        }
    }

    onObjectAdded: function (index, object) {
        console.log("onObjectAdded: "+ object.title);
    }

    onObjectRemoved: function (index, object) {
        console.log("onObjectRemoved: "+ object.title);
    }


}
