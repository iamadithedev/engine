#include "buffer.hpp"

Buffer::Buffer(uint32_t target, uint32_t usage)
    : _target { target }
    , _usage  { usage }
{
}

void Buffer::create()
{
    glGenBuffers(1, &_handle);
}

void Buffer::destroy()
{
    assert(glIsBuffer(_handle));

    glDeleteBuffers(1, &_handle);
}

void Buffer::data(const BufferData& data) const
{
    assert(data.ptr() != nullptr);
    assert(_handle    != 0);

    bind();

    glBufferData(_target, data.size(), data.ptr(), _usage);
}

void Buffer::sub_data(const BufferData& data, int32_t offset) const
{
    assert(data.ptr() != nullptr);
    assert(_handle    != 0);

    bind();

    glBufferSubData(_target, offset, data.size(), data.ptr());
}

void Buffer::bind_at_location(uint32_t index) const
{
    assert(_target == GL_UNIFORM_BUFFER);

    glBindBufferBase(_target, index, _handle);
}

void Buffer::bind() const
{
    glBindBuffer(_target, _handle);
}