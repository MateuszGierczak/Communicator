#include "Client.hpp"
#include "ServerSettings.hpp"

Client::Client(const ServerSettings& settings)
    : settings(settings)
{}

void Client::run()
{
    socket_.connectToHost(settings.host.data(), settings.port);
}
