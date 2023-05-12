#include "platform_factory.hpp"
#include "platform.hpp"
#include "window.hpp"
#include "input.hpp"

namespace glfw
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

    std::unique_ptr<base::Input> PlatformFactory::create_input() const
    {
        auto   input = std::make_unique<Input>();
        return input;
    }
}