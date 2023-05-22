#pragma once

#include "mesh_utils.hpp"

struct aiMesh;
class  MeshImporter
{
public:
    MeshImporter() = delete;

    static std::vector<geometry::triangle> load(const std::string& file);

private:
    static geometry::triangle load(const aiMesh* mesh);
};