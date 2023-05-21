#pragma once

#include "object.hpp"
#include "buffer_data.hpp"

class Buffer final : public Object
{
public:
    Buffer(uint32_t target, uint32_t usage);

    void create()  final;
    void destroy() final;

    void     data(const BufferData& data);
    void sub_data(const BufferData& data, int32_t offset = 0) const;

    void bind_at_location(uint32_t index);
    void bind();

private:
    uint32_t _target;
    uint32_t _usage;

    #ifndef NDEBUG
    bool _initialized;
    bool _binded;
    #endif
};