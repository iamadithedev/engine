#include "combine_geometry.hpp"

void CombineGeometry::combine(const std::vector<triangle_geometry>& geometries)
{
    uint32_t size   = 0;
    uint32_t offset = 0;

    begin();

    for (auto& geometry : geometries)
    {
        const auto& vertices = geometry.vertices();
        const auto& faces    = geometry.faces();

        for (auto& vertex : vertices)
        {
            add_vertex(vertex);
        }

        for (auto face : faces)
        {
            face.add_offset(size);
                 add_face(face);
        }
                        auto count = static_cast<int32_t>(faces.size() * primitive::triangle_count);
        add_submesh({ static_cast<uint32_t>(offset * sizeof(uint32_t)), count });

        size   += vertices.size();
        offset += count;
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