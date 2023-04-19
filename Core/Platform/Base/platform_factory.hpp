#pragma once

#include "platform.hpp"
#include "window.hpp"

namespace base
{
    class PlatformFactory
    {
    public:
        virtual ~PlatformFactory() = default;

        virtual std::unique_ptr<Window>   create_window(int32_t width, int32_t height) = 0;
        virtual std::unique_ptr<Platform> create_platform()                            = 0;
    };
}
