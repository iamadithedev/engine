#pragma once

#include "platform.hpp"
#include "window.hpp"

namespace base
{
    class PlatformFactory
    {
    public:
        virtual ~PlatformFactory() = default;

        virtual std::unique_ptr<Window>   create_window(const std::string& title, const window_size& size) = 0;
        virtual std::unique_ptr<Platform> create_platform()                                                = 0;
    };
}
