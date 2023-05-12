#pragma once

#include "base/platform_factory.hpp"

namespace windows
{
    class PlatformFactory final : public base::PlatformFactory
    {
    public:
        std::unique_ptr<base::Window>   create_window(const std::string& title, const window_size& size) const final;
        std::unique_ptr<base::Platform> create_platform()                                                const final;
    };
}