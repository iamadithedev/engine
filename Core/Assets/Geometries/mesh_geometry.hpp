#pragma once

#include "mesh_part.hpp"

template <typename _vertex, typename _primitive>
class MeshGeometry
{
public:
    MeshGeometry() noexcept : _ready { }
    {
    }

    void begin(uint32_t vertices = 0, uint32_t faces = 0)
    {
        if (vertices > 0 && faces > 0)
        {
            assert(_vertices.capacity() != vertices);
            assert(_faces.capacity()    != faces);

            _vertices.reserve(vertices);
            _faces.reserve(faces);
        }

        assert(!_ready);
    }
    void end() noexcept
    {
        assert(!_vertices.empty());
        assert(!_faces.empty());

        _ready = true;
    }

    void add_vertex(const _vertex&  vertex)
    {
        _vertices.push_back(vertex);
    }
    void add_face(const _primitive& primitive)
    {
        _faces.push_back(primitive);
    }

    [[nodiscard]] const std::vector<_vertex>&    vertices() const
    {
        assert(_ready);
        return _vertices;
    }
    [[nodiscard]] const std::vector<_primitive>& faces()    const
    {
        assert(_ready);
        return _faces;
    }

    [[nodiscard]] mesh_part get_submesh() const
    {
        assert(_ready);
        return { 0, static_cast<int32_t>(_faces.front().size() * _faces.size())};
    }

    void reset()
    {
        _vertices.clear();
        _faces.clear();

        _ready = false;
    }

protected:
    std::vector<_vertex>    _vertices;
    std::vector<_primitive> _faces;

private:
    bool _ready;
};