#include "Client.hpp"
#include "ServerSettings.hpp"

Client::Client(const ServerSettings& settings)
    : settings_(settings)
{}

void Client::run()
{
    connectToHost(settings_.host.data(), settings_.port);
}
