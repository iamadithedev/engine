#pragma once

#include "object.hpp"
#include "buffer_data.hpp"

class Buffer final : public Object
{
public:
    Buffer(uint32_t target, uint32_t usage);

    void create();
    void destroy();

    void data(const BufferData& data)     const;

    void bind_at_location(uint32_t index) const;
    void bind()                           const;

private:
    uint32_t _target;
    uint32_t _usage;
};