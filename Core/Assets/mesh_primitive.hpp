#pragma once

template<std::size_t _size>
struct   mesh_primitive
{
    void add_offset(uint32_t offset) noexcept
    {
        for (std::size_t i = 0; i < _size; i++) {
            indices[i] += offset;
        }
    }
    [[nodiscard]] std::size_t size() const noexcept
    {
        return _size;
    }

    uint32_t indices[_size];
};