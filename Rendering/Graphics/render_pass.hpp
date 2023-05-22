#pragma once

#include "vec2.hpp"
#include "size.hpp"
#include "rgb.hpp"

class RenderPass
{
public:
    explicit RenderPass(uint32_t flags);

    void viewport(const vec2& position, const math::size& size) const;
    void blend()  const;

    void clear_color(const rgb& color) const;
    void clear_buffers()               const;

    void enable(uint32_t option) const;

private:
    uint32_t _flags;
};