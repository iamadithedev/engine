#pragma once

#include "mesh_geometry.hpp"

struct aiMesh;

class MeshImporter
{
public:
    static MeshGeometry<vertex::diffuse> load(const std::string& file);

private:
    static MeshGeometry<vertex::diffuse> load(const aiMesh* mesh);
};