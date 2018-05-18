#include "Server.hpp"

#include <QCoreApplication>

int main(int argc, char* argv[])
{
    QCoreApplication app {argc, argv};
    Server server {};

    server.start();

    return app.exec();
}
