#include "View.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

View::View()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *topLayout = new QHBoxLayout();

    topLayout->addWidget(new QLabel("Nick"));
    topLayout->addWidget(nickLineEdit);
    topLayout->addWidget(connectButton);

    connect(connectButton, SIGNAL(pressed()), this, SLOT(handlePressedConnectButton()));

    mainLayout->addLayout(topLayout);
}

void View::handlePressedConnectButton()
{
    auto nick = nickLineEdit->text();

    if(not nick.isEmpty())
    {
        emit connectClient(nick);
    }
}
