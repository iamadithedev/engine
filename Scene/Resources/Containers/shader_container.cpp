#include "shader_container.hpp"

Shader* ShaderContainer::load(const std::string& file)
{
    return new Shader();
}

void ShaderContainer::unload()
{
}