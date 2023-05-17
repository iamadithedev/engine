#pragma once

#include "texture_data.hpp"

class TextureImporter
{
public:
    static TextureData load(const std::string& file);
};