#pragma once

#include "vertex.hpp"

template <typename vertex>
class MeshGeometry
{
public:
    void add_vertex(const vertex& vert)
    {
        _vertices.push_back(vert);
    }
    void add_face(uint32_t a, uint32_t b, uint32_t c)
    {
        _indices.push_back(a);
        _indices.push_back(b);
        _indices.push_back(c);
    }

    [[nodiscard]] const std::vector<vertex>&   vertices() const
    {
        return _vertices;
    }
    [[nodiscard]] const std::vector<uint32_t>& indices()  const
    {
        return _indices;
    }

private:
    std::vector<vertex>   _vertices;
    std::vector<uint32_t> _indices;
};