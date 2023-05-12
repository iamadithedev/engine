#include "platform_factory.hpp"
#include "platform.hpp"
#include "window.hpp"

namespace windows
{
    std::unique_ptr<base::Platform> PlatformFactory::create_platform() const
    {
        auto   platform = std::make_unique<Platform>();
        return platform;
    }

    std::unique_ptr<base::Window> PlatformFactory::create_window(const std::string& title, const window_size& size) const
    {
        auto   window = std::make_unique<Window>(title, size);
        return window;
    }
}