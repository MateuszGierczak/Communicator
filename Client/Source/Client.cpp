#include "Client.hpp"
#include "ServerSettings.hpp"

Client::Client(const ServerSettings& settings)
{
    socket_.connectToHost(settings.host.data(), settings.port);
}
