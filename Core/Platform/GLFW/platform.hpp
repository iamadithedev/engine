#pragma once

#include "base/platform.hpp"

namespace glfw
{
    class Platform : public base::Platform
    {
    public:
        explicit Platform(int32_t major = 3, int32_t minor = 3, int32_t samples = 4);

        [[nodiscard]] bool init() const;

        void update()  const;
        void release() const;
        void vsync()   const;

    private:
        int32_t _major;
        int32_t _minor;

        int32_t _samples;
    };
}