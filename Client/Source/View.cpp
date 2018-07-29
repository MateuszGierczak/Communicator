#include "View.hpp"
#include "ServerSettings.hpp"

#include <QDebug>

constexpr unsigned MIN_PORT_NUMBER = 0;
constexpr unsigned MAX_PORT_NUMBER = 65535;

constexpr unsigned SECOND_ROW = 1;
constexpr unsigned FOURTH_COLUMN = 3;

View::View()
{
    ui->setupUi(this);

    QString ipAddressRegExpPattern {"^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$"};
    ui->hostLineEdit->setValidator(new QRegExpValidator(QRegExp{ipAddressRegExpPattern}, this));
    ui->portLineEdit->setValidator(new QIntValidator(MIN_PORT_NUMBER, MAX_PORT_NUMBER, this));
    
    ui->connectionLayout->addWidget(connectButton, SECOND_ROW, FOURTH_COLUMN);
    ui->connectionLayout->addWidget(disconnectButton, SECOND_ROW, FOURTH_COLUMN);
    
    disconnectButton->hide();

    connect(connectButton, SIGNAL(pressed()), this, SLOT(handlePressedConnectButton()));
    connect(disconnectButton, SIGNAL(pressed()), this, SLOT(handlePressedDisconnectButton()));
}

void View::updateAfterClientConnected()
{
    connectButton->hide();
    disconnectButton->show();
}

void View::updateAfterClientDisconnected()
{
    disconnectButton->hide();
    connectButton->show();
}

void View::handlePressedConnectButton()
{
    auto host = ui->hostLineEdit->text();
    auto port = ui->portLineEdit->text();
    auto nick = ui->nickLineEdit->text();

    if(not host.isEmpty() and not port.isEmpty() and not nick.isEmpty())
    {
        qDebug() << "Trying to connect client. Host : " << host << ", port : " << port
                 << ", nick : " << nick;
        emit connectClient(ServerSettings {host, port.toUShort()}, nick);
    }
}

void View::handlePressedDisconnectButton()
{
    emit disconnectClient();
}
