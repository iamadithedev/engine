#pragma once

#include "mesh_utils.hpp"

struct aiMesh;
class  MeshImporter
{
public:
    static triangle_geometry load(const std::string& file);

private:
    static triangle_geometry load(const aiMesh* mesh);
};