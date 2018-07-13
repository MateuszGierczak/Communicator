#pragma once

#include "ui_View.h"
#include "ServerSettings.hpp"

#include <QMainWindow>
#include <QScopedPointer>

class View : public QMainWindow
{
    Q_OBJECT
public:
    View();

signals:
    void connectClient(ServerSettings, QString);

private slots:
    void handlePressedConnectButton();

private:
    QScopedPointer<Ui::View> ui {new Ui::View()};
};
