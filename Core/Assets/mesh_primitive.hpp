#pragma once

template<std::size_t _size>
struct   mesh_primitive
{
    [[nodiscard]] std::size_t size() const
    {
        return _size;
    }

    uint32_t indices[_size];
};
