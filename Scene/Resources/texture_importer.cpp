#include "texture_importer.hpp"

TextureData TextureImporter::load(const std::string& file)
{
    int32_t width, height, channels;

    stbi_set_flip_vertically_on_load(true);

    auto   data = stbi_load(file.c_str(), &width, &height, &channels, 0);
    assert(data != nullptr);

    return { data, width, height, channels == 4 ? GL_RGBA : GL_RGB };
}
