#include "render_pass.hpp"

RenderPass::RenderPass(uint32_t flags)
    : _flags { flags }
{
}

void RenderPass::viewport(const vec2& position, const math::size& size) const
{
    glViewport((int32_t)position.x, (int32_t)position.y, size.width, size.height);
}

void RenderPass::clear_color(const rgb& color) const
{
    glClearColor(color.r, color.g, color.b, 1.0f);
}

void RenderPass::clear_buffers() const
{
    glClear(_flags);
}

void RenderPass::enable(uint32_t option) const
{
    glEnable(option);
}
