#pragma once

#include "mesh_utils.hpp"

struct aiMesh;
class  MeshImporter
{
public:
    MeshImporter() = delete;

    static std::vector<TriangleGeometry> load(const std::string& file);

private:
    static TriangleGeometry load(const aiMesh* mesh);
};