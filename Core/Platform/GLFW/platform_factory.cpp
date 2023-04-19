#include "platform_factory.hpp"
#include "window.hpp"

std::unique_ptr<base::Window> glfw::PlatformFactory::create_window()
{
    auto   window = std::make_unique<Window>();
    return window;
}
