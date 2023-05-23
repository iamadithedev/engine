#pragma once

#include "vec3.hpp"

#include "mesh_utils.hpp"

class SpriteGeometry final : public geometry::sprite
{
public:
    SpriteGeometry();

    void  add_sprite(float half_w, float half_h, const vec3& min, const vec3& max);
    const mesh_part& operator[](int32_t index);

private:
    void add_submesh(const mesh_part& submesh);

    std::vector<mesh_part> _submeshes;

    uint32_t _offset;
    uint32_t _index;
};