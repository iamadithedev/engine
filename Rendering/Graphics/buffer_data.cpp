#include "buffer_data.hpp"

BufferData::BufferData(const void* ptr, uint32_t size)
    : _ptr  { ptr }
    , _size { size }
{
}

const void* BufferData::ptr() const
{
    return _ptr;
}

uint32_t BufferData::size() const
{
    return _size;
}