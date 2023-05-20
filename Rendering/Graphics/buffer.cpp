#include "buffer.hpp"

Buffer::Buffer(uint32_t target, uint32_t usage)
    : _target { target }
    , _usage  { usage  }
    , _initialized   { }
{
}

void Buffer::create()
{
    glCreateBuffers(1, &_handle);

    #ifndef NDEBUG

    if (_target == GL_UNIFORM_BUFFER)
    {
        assert(_usage == GL_DYNAMIC_DRAW);
    }

    #endif
}

void Buffer::destroy()
{
    assert(glIsBuffer(_handle));

    glDeleteBuffers(1, &_handle);
}

void Buffer::data(const BufferData& data)
{
    assert(data.ptr() != nullptr);

    glNamedBufferData(_handle, data.size(), data.ptr(), _usage);

    _initialized = true;
}

void Buffer::sub_data(const BufferData& data, int32_t offset) const
{
    assert(_initialized == true);
    assert(data.ptr()   != nullptr);

    glNamedBufferSubData(_handle, offset, data.size(), data.ptr());
}

void Buffer::bind_at_location(uint32_t index) const
{
    assert(_target == GL_UNIFORM_BUFFER);

    glBindBufferBase(_target, index, _handle);
}

void Buffer::bind() const
{
    assert(_handle != 0);

    glBindBuffer(_target, _handle);
}