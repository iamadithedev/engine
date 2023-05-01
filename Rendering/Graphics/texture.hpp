#pragma once

#include "object.hpp"
#include "texture_data.hpp"

class Texture final : public Object
{
public:
    explicit Texture(uint32_t target);

    void create();
    void destroy();

    void source(const TextureData& data) const;
    void bind() const;

    void parameter(uint32_t param, int32_t value) const;
    void generate_mipmap()                        const;

private:
    uint32_t _target;
};