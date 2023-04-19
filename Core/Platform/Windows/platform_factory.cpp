#include "platform_factory.hpp"
#include "platform.hpp"
#include "window.hpp"

namespace windows
{
    std::unique_ptr<base::Platform> PlatformFactory::create_platform()
    {
        auto   platform = std::make_unique<Platform>();
        return platform;
    }

    std::unique_ptr<base::Window> PlatformFactory::create_window(int32_t width, int32_t height)
    {
        auto   window = std::make_unique<Window>(width, height);
        return window;
    }
}