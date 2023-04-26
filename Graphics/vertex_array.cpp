#include "vertex_array.hpp"

void VertexArray::create()
{
    glGenVertexArrays(1, &_handle);
}

void VertexArray::destroy()
{
    assert(glIsVertexArray(_handle));

    glDeleteVertexArrays(1, &_handle);
}

void VertexArray::bind() const
{
    glBindVertexArray(_handle);
}
