#pragma once

template<int32_t _size>
struct   mesh_primitive
{
    [[nodiscard]] int32_t size() const
    {
        return _size;
    }

    uint32_t indices[_size];
};
