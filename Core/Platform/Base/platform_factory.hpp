#pragma once

#include "input.hpp"
#include "platform.hpp"

namespace base
{
    class PlatformFactory
    {
    public:
        virtual ~PlatformFactory() = default;

        [[nodiscard]] virtual std::unique_ptr<Window>   create_window(const std::string& title, const window_size& size) const = 0;

        [[nodiscard]] virtual std::unique_ptr<Platform> create_platform() const = 0;
        [[nodiscard]] virtual std::unique_ptr<Input>    create_input()    const = 0;
    };
}
