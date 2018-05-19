#include "View.hpp"
#include "Client.hpp"
#include "ServerSettings.hpp"

#include <QApplication>

int main(int argv, char* argc[])
{
    QApplication app {argv, argc};

    ServerSettings settings {"127.0.0.1", 12345};
    View view {};
    Client client {settings};

    view.show();
    client.run();

    return app.exec();
}
