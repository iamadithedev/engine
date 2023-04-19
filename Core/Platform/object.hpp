#pragma once

namespace base
{
    template <typename type_t>
    class Object
    {
    public:
        [[nodiscard]] type_t handle() const
        {
            return _handle;
        }

    protected:
        Object() : _handle { }
        {
        }

        type_t _handle;
    };
}