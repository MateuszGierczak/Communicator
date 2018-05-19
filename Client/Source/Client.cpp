#include "Client.hpp"
#include "ServerSettings.hpp"

Client::Client(const ServerSettings& settings)
    : settings_(settings)
{}

void Client::run()
{
    socket_.connectToHost(settings_.host.data(), settings_.port);
}
