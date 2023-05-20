#pragma once

namespace base
{
    template <typename type>
    class Object
    {
    public:
        [[nodiscard]] type handle() const
        {
            return _handle;
        }

    protected:
        Object() noexcept : _handle { }
        {
        }
        type       _handle;
    };
}