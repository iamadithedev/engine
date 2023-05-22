#pragma once

#include "mesh_utils.hpp"

class CombineGeometry final : public geometry::triangle
{
public:
    void  combine(const std::vector<geometry::triangle>& geometries);
    const mesh_part& operator[](int32_t index);

private:
    void add_submesh(const mesh_part& submesh);

    std::vector<mesh_part> _submeshes;
};