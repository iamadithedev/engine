#pragma once

using uchar = unsigned char;

class TextureData
{
public:
    TextureData(uchar* ptr, int32_t width, int32_t height, int32_t format);

    void release();

    [[nodiscard]] uchar*  ptr()    const;
    [[nodiscard]] int32_t width()  const; // TODO make this inline
    [[nodiscard]] int32_t height() const;
    [[nodiscard]] int32_t format() const;

private:
    uchar* _ptr;

    int32_t _width;
    int32_t _height;

    int32_t _format;
};