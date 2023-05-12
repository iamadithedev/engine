#pragma once

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

    void reset()
    {
         assert(_ready);

        _vertices.clear();
        _faces.clear();

        _ready = false;
    }

private:
    std::vector<_vertex>    _vertices;
    std::vector<_primitive> _faces;

    bool _ready;
};