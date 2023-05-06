#pragma once

#include "base/platform.hpp"

namespace windows
{
    class Platform final : public base::Platform
    {
    public:
        bool init()    const final;
        void update()  const final;
        void release() const final;

        void vsync()   const final;
    };
}