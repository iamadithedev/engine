#include "texture_data.hpp"

TextureData::TextureData(uchar* ptr, int32_t width, int32_t height, int32_t format)
    : _ptr    { ptr }
    , _width  { width  }
    , _height { height }
    , _format { format }
{
}

void TextureData::release()
{
    assert(_ptr != nullptr);
    std::free(_ptr);
}

uchar* TextureData::ptr() const
{
    return _ptr;
}

int32_t TextureData::width() const
{
    return _width;
}

int32_t TextureData::height() const
{
    return _height;
}

int32_t TextureData::format() const
{
    return _format;
}
