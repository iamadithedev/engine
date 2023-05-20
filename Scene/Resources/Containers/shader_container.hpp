#pragma once

#include "resource_container.hpp"
#include "shader.hpp"

class ShaderContainer final : public ResourceContainer<Shader>
{
public:
    void init();

    Shader* load(const std::string& file, const std::string& path) final;
    void  unload() final;

private:
    std::array<uint32_t, 2> _types;
    std::size_t             _hash;
};