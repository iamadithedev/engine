#pragma once

#include "mesh_geometry.hpp"

class Importer
{
public:
    static MeshGeometry<vertex::diffuse> load(const std::string& file);
};