#include "combine_geometry.hpp"

void CombineGeometry::combine(const std::vector<geometry::triangle>& geometries)
{
    _submeshes.reserve(geometries.size());

    uint32_t index  { };
    uint32_t offset { };

    begin();

    for (auto& geometry : geometries)
    {
        const auto& vertices = geometry.vertices();
        const auto& faces    = geometry.faces();

        for (auto& vertex : vertices) {
            add_vertex(vertex);
        }

        for (auto face : faces) {
            face.add_offset(index);
                 add_face(face);
        }

        const int32_t count = static_cast<int32_t>(faces.size()) * primitive::triangle_count;

        add_submesh({offset * static_cast<uint32_t>(sizeof(uint32_t)), count });

        offset += static_cast<uint32_t>(count);
        index  += vertices.size();
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