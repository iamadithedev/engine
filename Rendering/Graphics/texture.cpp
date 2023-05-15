#include "texture.hpp"

Texture::Texture(uint32_t target)
    : _target { target }
{
}

void Texture::create()
{
    glCreateTextures(_target, 1, &_handle);
}

void Texture::destroy()
{
    assert(glIsTexture(_handle));

    glDeleteTextures(1, &_handle);
}

void Texture::source(const TextureData& data) const
{
    bind();

    glTexImage2D(_target, 0, data.format(), data.width(), data.height(), 0, data.format(), GL_UNSIGNED_BYTE, data.ptr());
}

void Texture::bind() const
{
    glBindTexture(_target, _handle);
}

void Texture::parameter(uint32_t param, int32_t value) const
{
    glTexParameteri(_target, param, value);
}

void Texture::generate_mipmap() const
{
    glGenerateMipmap(_target);
}
