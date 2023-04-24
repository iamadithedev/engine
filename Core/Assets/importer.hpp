#pragma once

#include "mesh_geometry.hpp"

class Importer
{
public:
    static mesh_geometry<vertex::diffuse> load(const std::string& file);
};