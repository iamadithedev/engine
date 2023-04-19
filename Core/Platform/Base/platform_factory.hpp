#pragma once

#include "window.hpp"

namespace base
{
    class PlatformFactory
    {
    public:
        virtual ~PlatformFactory() = default;

        virtual std::unique_ptr<Window> create_window() = 0;
    };
}
