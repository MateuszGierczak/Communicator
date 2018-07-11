#pragma once

#include "ServerSettings.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

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
    QLineEdit *hostLineEdit {new QLineEdit()};
    QLineEdit *portLineEdit {new QLineEdit()};
    QPushButton *connectButton {new QPushButton("Connect")};
};
