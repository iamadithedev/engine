#pragma once

class RenderPass
{
public:
    explicit RenderPass(uint32_t flags);

    void viewport(int32_t x, int32_t y, int32_t width, int32_t height) const;

    void clear_color(float r, float g, float b, float a = 1.0f) const;
    void clear_buffers()                                        const;

    void enable(uint32_t option) const;

private:
    uint32_t _flags;
};