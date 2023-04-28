#pragma once

#include "vertex.hpp"

template <typename vertex>
class MeshGeometry
{
public:
    MeshGeometry()
        : _ready { }
    {
    }

    void begin()
    {
        _ready = false;
    }
    void end()
    {
        _ready = true;
    }

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
    void add_line(uint32_t a, uint32_t b)
    {
        _indices.push_back(a);
        _indices.push_back(b);
    }

    [[nodiscard]] const std::vector<vertex>&   vertices() const
    {
        assert(_ready);
        return _vertices;
    }
    [[nodiscard]] const std::vector<uint32_t>& indices()  const
    {
        assert(_ready);
        return _indices;
    }

    void reset()
    {
        _vertices.clear();
        _indices.clear();

        _ready = false;
    }

private:
    std::vector<vertex>   _vertices;
    std::vector<uint32_t> _indices;

    bool _ready;
};