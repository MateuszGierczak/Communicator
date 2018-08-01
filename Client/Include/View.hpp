#pragma once

#include "ui_View.h"

#include <QMainWindow>
#include <QScopedPointer>
#include <QPushButton>

class ServerSettings;

class View : public QMainWindow
{
    Q_OBJECT
public:
    View();

    void updateAfterClientConnected();
    void updateAfterClientDisconnected();

signals:
    void connectClient(const ServerSettings&, QString);
    void disconnectClient();

private slots:
    void handlePressedConnectButton();

private:
    QScopedPointer<Ui::View> ui { new Ui::View() };
    QPushButton* connectButton { new QPushButton("Connect", this) };
    QPushButton* disconnectButton { new QPushButton("Disconnect", this) };
};
