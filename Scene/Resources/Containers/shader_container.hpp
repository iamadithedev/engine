#pragma once

#include "resource_container.hpp"
#include "shader.hpp"

class ShaderContainer final : public ResourceContainer<Shader>
{
public:
    Shader* load(const std::string& filename, const std::string& path) final;
    void  unload() final;
};