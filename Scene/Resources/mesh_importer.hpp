#pragma once

#include "mesh_geometry.hpp"

struct aiMesh;

using triangle = mesh_primitive<3>;

class MeshImporter
{
public:
    static MeshGeometry<mesh_vertex::diffuse, triangle> load(const std::string& file);

private:
    static MeshGeometry<mesh_vertex::diffuse, triangle> load(const aiMesh* mesh);
};