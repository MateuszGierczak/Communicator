#include "Client.hpp"
#include "ServerSettings.hpp"

#include <QCoreApplication>

int main(int argv, char* argc[])
{
    QCoreApplication app {argv, argc};

    ServerSettings settings {"127.0.0.1", 12345};
    Client client {settings};

    return app.exec();
}
