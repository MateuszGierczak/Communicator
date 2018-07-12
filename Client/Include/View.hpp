#pragma once

#include "ServerSettings.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>

const QString DEFAULT_HOST {"127.0.0.1"};
const QString DEFAULT_PORT_NUMBER {"1234"};

class View : public QWidget
{
    Q_OBJECT
public:
    View();

signals:
    void connectClient(ServerSettings, QString);

private slots:
    void handlePressedConnectButton();

private:
    QLineEdit *nickLineEdit {new QLineEdit()};
    QLineEdit *hostLineEdit {new QLineEdit(DEFAULT_HOST)};
    QLineEdit *portLineEdit {new QLineEdit(DEFAULT_PORT_NUMBER)};
    QPushButton *connectButton {new QPushButton("Connect")};

    QListWidget *clientList {new QListWidget()};
    QTextEdit *messageBox {new QTextEdit()};
};
