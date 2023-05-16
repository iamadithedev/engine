#pragma once

#include "object.hpp"
#include "texture_data.hpp"

class Texture final : public Object
{
public:
    explicit Texture(uint32_t target);

    void create()  final;
    void destroy() final;

    void source(const TextureData& data) const;
    void bind() const;

    void generate_mipmap() const;

private:
    uint32_t _target;
};