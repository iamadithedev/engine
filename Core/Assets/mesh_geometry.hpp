#pragma once

#include "mesh_part.hpp"

template <typename _vertex, typename _primitive>
class MeshGeometry
{
public:
    MeshGeometry() : _ready { }
    {
    }

    void begin()
    {
        assert(!_ready);
    }
    void end()
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

    [[nodiscard]] mesh_part get_mesh_part() const
    {
        assert(_ready);
        return { 0, static_cast<int32_t>(_faces[0].size() * _faces.size()) };
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