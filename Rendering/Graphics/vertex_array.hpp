#pragma once

#include "object.hpp"
#include "vertex_attribute.hpp"

using vertex_attributes = std::vector<vertex_attribute>;

class VertexArray final : public Object
{
public:
    void create()  final;
    void destroy() final;
    
    void bind()    const;

    template<typename type>
    void init_attributes_of_type(const vertex_attributes& attributes) const noexcept
    {
        for (auto& attrib : attributes)
        {
            glVertexAttribPointer(attrib.index, attrib.size, attrib.type, GL_FALSE, sizeof(type), reinterpret_cast<const void*>(attrib.offset));
            glEnableVertexAttribArray(attrib.index);
        }
    }
};