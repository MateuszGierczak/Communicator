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
constexpr unsigned ONE_COLUMN_SPAN = 1;
constexpr unsigned TWO_COLUMN_SPAN = 2;

constexpr unsigned MIN_PORT_NUMBER = 0;
constexpr unsigned MAX_PORT_NUMBER = 65535;

View::View()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QGridLayout *connectionLayout = new QGridLayout();

    connectionLayout->addWidget(new QLabel("Host"), FIRST_ROW, FIRST_COLUMN, ONE_ROW_SPAN, ONE_COLUMN_SPAN);
    connectionLayout->addWidget(hostLineEdit, FIRST_ROW, SECOND_COLUMN, ONE_ROW_SPAN, ONE_COLUMN_SPAN);
    QString ipAddressRegExpPattern {"^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$"};
    hostLineEdit->setValidator(new QRegExpValidator(QRegExp{ipAddressRegExpPattern}, this));

    connectionLayout->addWidget(new QLabel("Port"), FIRST_ROW, THIRD_COLUMN, ONE_ROW_SPAN, ONE_COLUMN_SPAN);
    connectionLayout->addWidget(portLineEdit, FIRST_ROW, FOURTH_COLUMN, ONE_ROW_SPAN, ONE_COLUMN_SPAN);
    portLineEdit->setValidator(new QIntValidator(MIN_PORT_NUMBER, MAX_PORT_NUMBER, this));

    connectionLayout->addWidget(new QLabel("Nick"), SECOND_ROW, FIRST_COLUMN, ONE_ROW_SPAN, ONE_COLUMN_SPAN);
    connectionLayout->addWidget(nickLineEdit, SECOND_ROW, SECOND_COLUMN, ONE_ROW_SPAN, TWO_COLUMN_SPAN);
    connectionLayout->addWidget(connectButton, SECOND_ROW, FOURTH_COLUMN, ONE_ROW_SPAN, ONE_COLUMN_SPAN);

    connect(connectButton, SIGNAL(pressed()), this, SLOT(handlePressedConnectButton()));

    mainLayout->addLayout(connectionLayout);
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
