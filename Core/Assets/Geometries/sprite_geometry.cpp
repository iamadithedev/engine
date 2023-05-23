#include "sprite_geometry.hpp"

SpriteGeometry::SpriteGeometry()
    : _index  { }
    , _offset { }
{
}

void SpriteGeometry::add_sprite(float half_w, float half_h, const vec3& min, const vec3& max)
{
    const uint32_t index_0 = _offset++; const uint32_t index_1 = _offset++;
    const uint32_t index_2 = _offset++; const uint32_t index_3 = _offset++;

    add_vertex({ { half_w,  half_h }, { max.x, max.y } });
    add_vertex({ { half_w, -half_h }, { max.x, min.y } });
    add_vertex({ {-half_w, -half_h }, { min.x, min.y } });
    add_vertex({ {-half_w,  half_h }, { min.x, max.y } });

    add_face({ index_0, index_1, index_3 });
    add_face({ index_1, index_2, index_3 });

    add_submesh({ _index * static_cast<uint32_t>(sizeof(uint32_t)), primitive::sprite_count });

    _index += primitive::sprite_count;
}

void SpriteGeometry::add_submesh(const mesh_part& submesh)
{
    _submeshes.push_back(submesh);
}

const mesh_part& SpriteGeometry::operator[](int32_t index)
{
    return _submeshes[index];
}