#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class View : public QWidget
{
    Q_OBJECT
public:
    View();

signals:
    void connectClient(QString);

private slots:
    void handlePressedConnectButton();

private:
    QLineEdit *nickLineEdit {new QLineEdit()};
    QPushButton *connectButton {new QPushButton("Connect")};
};
