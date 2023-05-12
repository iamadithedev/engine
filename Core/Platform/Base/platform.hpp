#pragma once

namespace base
{
    class Platform
    {
    public:
        virtual ~Platform() =  default;

        virtual bool init()    const = 0;
        virtual void update()  const = 0;
        virtual void release() const = 0;

        virtual void vsync()   const = 0;
    };
}