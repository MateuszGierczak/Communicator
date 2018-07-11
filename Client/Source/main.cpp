#include "View.hpp"
#include "Client.hpp"

#include <QApplication>

int main(int argv, char* argc[])
{
    QApplication app {argv, argc};

    View view {};
    Client client {view};

    view.show();

    return app.exec();
}
