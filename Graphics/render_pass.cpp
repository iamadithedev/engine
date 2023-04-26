#include "render_pass.hpp"

RenderPass::RenderPass(uint32_t flags)
    : _flags { flags }
{
}

void RenderPass::viewport(int32_t x, int32_t y, int32_t width, int32_t height) const
{
    glViewport(x, y, width, height);
}

void RenderPass::clear_color(float r, float g, float b, float a) const
{
    glClearColor(r, g, b, a);
}

void RenderPass::clear_buffers() const
{
    glClear(_flags);
}

void RenderPass::enable(uint32_t option) const
{
    glEnable(option);
}
