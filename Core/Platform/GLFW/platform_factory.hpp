#pragma once

#include "base/platform_factory.hpp"

namespace glfw
{
    class PlatformFactory final : public base::PlatformFactory
    {
    public:
        std::unique_ptr<base::Window> create_window() final;
    };
}