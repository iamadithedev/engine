#pragma once

#include "base/platform.hpp"

namespace glfw
{
    class Platform final : public base::Platform
    {
    public:
        bool init()    const final;
        void update()  const final;
        void release() const final;

        void vsync()   const final;

        static bool init_context();
    };
}