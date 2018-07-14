#pragma once

#include "ui_View.h"

#include <QMainWindow>
#include <QScopedPointer>

class ServerSettings;

class View : public QMainWindow
{
    Q_OBJECT
public:
    View();

signals:
    void connectClient(const ServerSettings&, QString);

private slots:
    void handlePressedConnectButton();

private:
    QScopedPointer<Ui::View> ui {new Ui::View()};
};
