import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

import ViewModels 1.0

Window {
    visible: true
    width: contentColumn.width
    height: contentColumn.height
    title: qsTr("Hello World")

    ViewModel {
        id: viewModel
        onUpdateLabel: textLabel.text = labelText
    }
    Column {
        id: contentColumn


        /*Label {
            id: textLabel

            anchors.left: parent.left
            anchors.right: parent.righr
              horizontalAlignment: Label.AlignRight

        }*/
        Label {
                    text:'0'
                    id: textLabel
                    width: parent.width
                    horizontalAlignment :Label.AlignRight
                }
        Grid {
            id: contentGrid
            columns: 3
            Repeater {
                Button {
                    text: (index + 1).toString()
                    onClicked: {

                        viewModel.onNumberSelected(text)
                    }
                }
                model: 9
            }

            Button {
                text: "0"
                //horizontalAlignment : Label.AlignRight
                onClicked: {
                    viewModel.onNumberSelected(text)
                }
            }

            Button {
                text: "="
                onClicked: viewModel.onEqSelected()
            }

        }

        Label {
            text: qsTr("Операции")

        }

        Grid {
            columns: 2
            Repeater {
                Button {
                    text: modelData
                    onClicked: viewModel.onOperationSelected(modelData)
                }
                model: viewModel.operations()
            }
        }
        Button {
            text: "AC"
            onClicked: viewModel.clear()

        }
        Label {
           text: qsTr("Plus Minus,Dot,%,")

        }
        Button {
            text: "+/-"
            onClicked: viewModel.plus_minus()

        }
        Button {
            text: "%"
            onClicked: viewModel.percent()
        }
        Button {
            text: "."
            onClicked: viewModel.dot()
        }
        Button {
            text: "Backspace"
            onClicked: viewModel.backspace()
        }
    }
    }


