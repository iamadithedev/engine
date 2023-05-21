#pragma once

#include "texture_data.hpp"

class TextureImporter
{
public:
    TextureImporter() = delete;

    static TextureData load(const std::string& file);
};