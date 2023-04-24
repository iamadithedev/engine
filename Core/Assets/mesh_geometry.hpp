#pragma once

#include "vertex.hpp"

template <typename vertex>
struct mesh_geometry
{
    std::vector<vertex>   vertices;
    std::vector<uint32_t> indices;
};