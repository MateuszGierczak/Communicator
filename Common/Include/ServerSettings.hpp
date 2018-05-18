#pragma once

#include <string_view>

struct ServerSettings
{
    std::string_view host;
    unsigned short port;
};
