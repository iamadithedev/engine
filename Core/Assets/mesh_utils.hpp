#pragma once

#include "mesh_vertex.hpp"
#include "mesh_primitive.hpp"
#include "mesh_geometry.hpp"

namespace primitive
{
    constexpr uint32_t line_count     = 2;
    constexpr uint32_t triangle_count = 3;

    using line     = mesh_primitive<primitive::line_count>;
    using triangle = mesh_primitive<primitive::triangle_count>;
}

namespace geometry
{
    using line     = MeshGeometry<mesh_vertex::debug,   primitive::line>;
    using sprite   = MeshGeometry<mesh_vertex::sprite,  primitive::triangle>;
    using triangle = MeshGeometry<mesh_vertex::diffuse, primitive::triangle>;
}