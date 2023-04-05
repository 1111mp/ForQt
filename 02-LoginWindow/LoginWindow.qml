import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic
import Qt5Compat.GraphicalEffects

import "./request.js" as Request

Rectangle {
    color: "#f4f4f4"

    property int type: 1;

    Column {
        padding: 16

        Row {

            Text {
                text: "Hi, "
                font.pixelSize: 16
                font.bold: true
            }

            Text {
                text: "Good Day!"
                color: "#58acec"
                font.pixelSize: 16
                font.bold: true
            }
        }

        Row {
            Text {
                text: "Please " + (type === 1 ? "sign in" : "sign up") +" to continue"
                font.pixelSize: 12
            }
        }

        Row {
            topPadding: 60

            Rectangle {
                width: 248
                height: 50
                radius: 4
                color: "#ffffff"
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 0
                    verticalOffset: 6
                    color: "#d9d9d9"
                }

                Column {
                    topPadding: 6
                    bottomPadding: 6
                    leftPadding: 8
                    rightPadding: 8

                    Row {
                        Text {
                            text: qsTr("Account")
                            font.bold: true
                            font.pixelSize: 12
                        }
                    }

                    Row {

                        TextField {
                            id: actInput
                            width: 232
                            leftPadding: 0
                            verticalAlignment: Text.AlignHCenter
                            font.pixelSize: 12
                            color: "#a8a4a4"
                            selectionColor: "#58acec"
                            placeholderText: qsTr("account")
                            placeholderTextColor: "#a8a4a4"
                            validator: RegularExpressionValidator {
                                regularExpression: /^[1]\d{10}/
                            }

                            background: Rectangle {
                                border.width: 0
                                radius: 4
                            }
                        }
                    }
                }
            }
        }

        Row {
            topPadding: 12

            Rectangle {
                width: 248
                height: 50
                anchors.topMargin: 200
                radius: 4
                color: "#ffffff"
                layer.enabled: true
                layer.effect: DropShadow {
                    transparentBorder: true
                    horizontalOffset: 0
                    verticalOffset: 6
                    color: "#d9d9d9"
                }

                Column {
                    topPadding: 6
                    bottomPadding: 6
                    leftPadding: 8
                    rightPadding: 8

                    Row {
                        Text {
                            text: qsTr("Password")
                            font.bold: true
                        }
                    }

                    Row {

                        TextField {
                            id: pwdInput
                            width: 232
                            leftPadding: 0
                            echoMode: TextInput.Password
                            verticalAlignment: Text.AlignHCenter
                            color: "#a8a4a4"
                            selectionColor: "#58acec"
                            placeholderText: qsTr("password")
                            placeholderTextColor: "#a8a4a4"
                            background: Rectangle {
                                border.width: 0
                                radius: 4
                            }
                        }
                    }
                }
            }
        }

        Row {
            topPadding: 24

            Rectangle {
                width: 248
                height: 28
                color: "#f4f4f4"

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Or")
                    font.pixelSize: 12
                }

                Button {
                    id: check
                    x: 14
                    anchors.verticalCenter: parent.verticalCenter
                    contentItem: Text {
                        text: qsTr(type === 1 ? "Sign up" : "Sign in")
                        font.pixelSize: 12
                        color: "#58acec"
                        opacity: check.pressed ? 0.8 : 1
                    }
                    background: Rectangle {
                        color: "transparent"
                        border.width: 0
                    }

                    onClicked: {
                        type = type === 1 ? 2 : 1;
                    }
                }

                Button {
                    id: submit
                    width: 68
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    contentItem: Text {
                        text: qsTr(type === 1 ? "Sign in" : "Sign up")
                        color: "#ffffff"
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                    }

                    background: Rectangle {
                        radius: 4
                        color: submit.hovered ? "#4ba1e2" : "#58acec"
                        opacity: submit.pressed ? 0.8 : 1
                        layer.enabled: true
                        layer.effect: DropShadow {
                            transparentBorder: true
                            horizontalOffset: 0
                            verticalOffset: 2
                            color: "#9e9c9c"
                        }
                    }

                    onClicked: {
                        const account = actInput.text;
                        const pwd = pwdInput.text;
                        console.log(account);
                        console.log(pwd);
//                        Request.request()
                    }
                }
            }
        }
    }
}
