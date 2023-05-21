#include "buffer.hpp"

Buffer::Buffer(uint32_t target, uint32_t usage)
    : _target { target }
    , _usage  { usage  }
    #ifndef NDEBUG
    , _initialized { }
    , _binded      { }
    #endif
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
    assert(_binded    == true);
    assert(data.ptr() != nullptr);

    glNamedBufferData(_handle, data.size(), data.ptr(), _usage);

    #ifndef NDEBUG
    _initialized = true;
    #endif
}

void Buffer::sub_data(const BufferData& data, int32_t offset) const
{
    assert(_initialized == true);
    assert(data.ptr()   != nullptr);

    glNamedBufferSubData(_handle, offset, data.size(), data.ptr());
}

void Buffer::bind_at_location(uint32_t index)
{
    assert(_handle != 0);
    assert(_binded == false);
    assert(_target == GL_UNIFORM_BUFFER);

    glBindBufferBase(_target, index, _handle);

    #ifndef NDEBUG
    _binded = true;
    #endif
}

void Buffer::bind()
{
    assert(_handle != 0);
    assert(_binded == false);
    assert(_target != GL_UNIFORM_BUFFER);

    glBindBuffer(_target, _handle);

    #ifndef NDEBUG
    _binded = true;
    #endif
}