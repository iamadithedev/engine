#pragma once

#include "base/platform.hpp"

namespace glfw
{
    class Platform final : public base::Platform
    {
    public:
        explicit Platform(int32_t major = 3, int32_t minor = 3, int32_t samples = 4);

        bool init()    const final;
        void update()  const final;
        void release() const final;

        void vsync()   const final;

    private:
        int32_t _major;
        int32_t _minor;

        int32_t _samples;
    };
}