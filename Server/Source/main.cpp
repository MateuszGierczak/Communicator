#include "Server.hpp"
#include "ServerSettings.hpp"

#include <QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication app {argc, argv};

    ServerSettings settings {"127.0.0.1", 12345};
    Server server {&app, settings};

    server.run();

    return app.exec();
}
