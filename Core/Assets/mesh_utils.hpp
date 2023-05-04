#pragma once

#include "mesh_vertex.hpp"
#include "mesh_primitive.hpp"
#include "mesh_geometry.hpp"

using line     = mesh_primitive<2>;
using triangle = mesh_primitive<3>;

using line_geometry     = MeshGeometry<mesh_vertex::debug,   line>;
using triangle_geometry = MeshGeometry<mesh_vertex::diffuse, triangle>;