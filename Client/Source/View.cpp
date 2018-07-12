#include "View.hpp"
#include "ServerSettings.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QRegExpValidator>

constexpr unsigned FIRST_ROW = 0;
constexpr unsigned SECOND_ROW = 1;

constexpr unsigned FIRST_COLUMN = 0;
constexpr unsigned SECOND_COLUMN = 1;
constexpr unsigned THIRD_COLUMN = 2;
constexpr unsigned FOURTH_COLUMN = 3;

constexpr unsigned ONE_ROW_SPAN = 1;
constexpr unsigned TWO_COLUMN_SPAN = 2;

constexpr unsigned SEVENTY_PERCENT_STRETCH = 70;
constexpr unsigned THITRY_PERCENT_STRETCH = 30;

constexpr unsigned MIN_PORT_NUMBER = 0;
constexpr unsigned MAX_PORT_NUMBER = 65535;

View::View()
{
    auto mainLayout = new QVBoxLayout(this);

    auto connectionLayout = new QGridLayout();

    connectionLayout->addWidget(new QLabel("Host"), FIRST_ROW, FIRST_COLUMN);
    connectionLayout->addWidget(hostLineEdit, FIRST_ROW, SECOND_COLUMN);
    QString ipAddressRegExpPattern {"^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$"};
    hostLineEdit->setValidator(new QRegExpValidator(QRegExp{ipAddressRegExpPattern}, this));

    connectionLayout->addWidget(new QLabel("Port"), FIRST_ROW, THIRD_COLUMN);
    connectionLayout->addWidget(portLineEdit, FIRST_ROW, FOURTH_COLUMN);
    portLineEdit->setValidator(new QIntValidator(MIN_PORT_NUMBER, MAX_PORT_NUMBER, this));

    connectionLayout->addWidget(new QLabel("Nick"), SECOND_ROW, FIRST_COLUMN);
    connectionLayout->addWidget(nickLineEdit, SECOND_ROW, SECOND_COLUMN, ONE_ROW_SPAN, TWO_COLUMN_SPAN);
    connectionLayout->addWidget(connectButton, SECOND_ROW, FOURTH_COLUMN);

    connect(connectButton, SIGNAL(pressed()), this, SLOT(handlePressedConnectButton()));

    auto centralLayout = new QGridLayout();
    centralLayout->setColumnStretch(FIRST_COLUMN, SEVENTY_PERCENT_STRETCH);
    centralLayout->setColumnStretch(SECOND_COLUMN, THITRY_PERCENT_STRETCH);
    centralLayout->addWidget(messageBox, FIRST_ROW, FIRST_COLUMN);
    centralLayout->addWidget(clientList, FIRST_ROW, SECOND_COLUMN);

    mainLayout->addLayout(connectionLayout);
    mainLayout->addLayout(centralLayout);
}

void View::handlePressedConnectButton()
{
    auto nick = nickLineEdit->text();
    auto host = hostLineEdit->text();
    auto port = portLineEdit->text();

    if(not nick.isEmpty() and
       not host.isEmpty() and
       not port.isEmpty())
    {
        emit connectClient(ServerSettings{host, port.toUShort()}, nick);
    }
}
