#pragma once

#include "object.hpp"
#include "vertex_attribute.hpp"

class VertexArray final : public Object
{
public:
    void create();
    void destroy();

    void bind() const;

    template<typename type_t>
    void init_attributes_of_type(const std::vector<vertex_attribute>& attributes) const
    {
        for (auto& attribute : attributes)
        {
            glVertexAttribPointer(attribute.index, attribute.size, GL_FLOAT, GL_FALSE, sizeof(type_t), reinterpret_cast<const void*>(attribute.offset));
            glEnableVertexAttribArray(attribute.index);
        }
    }
};