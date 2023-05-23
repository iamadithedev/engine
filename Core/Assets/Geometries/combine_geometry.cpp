#include "combine_geometry.hpp"

void CombineGeometry::combine(const std::vector<geometry::triangle>& geometries)
{
    begin();

    _submeshes.reserve(geometries.size());

    for (auto& geometry : geometries)
    {
        const auto& vertices = geometry.vertices();
        const auto& faces    = geometry.faces();

        for (auto& vertex : vertices) {
            add_vertex(vertex);
        }

        for (auto face : faces) {
            face.add_offset(_index);
                 add_face(face);
        }

        const int32_t count = static_cast<int32_t>(faces.size()) * primitive::triangle_count;

        add_submesh({ _offset * static_cast<uint32_t>(sizeof(uint32_t)), count });

        _offset += static_cast<uint32_t>(count);
        _index  += vertices.size();
    }

    end();
}

void CombineGeometry::add_submesh(const mesh_part& submesh)
{
    _submeshes.push_back(submesh);
}

const mesh_part& CombineGeometry::operator[](int32_t index)
{
    return _submeshes[index];
}