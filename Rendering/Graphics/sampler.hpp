#pragma once

#include "texture.hpp"

class Sampler final : public Object
{
public:
    void create()  final;
    void destroy() final;

    void parameter(uint32_t param, int32_t value) const;

    void bind_at_location(int32_t index)   const;
};