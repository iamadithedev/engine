#include "shader_container.hpp"

#include "file.hpp"

Shader* ShaderContainer::load(const std::string& filename, const std::string& path)
{
    const auto& root   = YAML::LoadFile(path + filename);
    const auto& stages = root["stages"];

    auto shader = new Shader();
    shader->create();

    for (const auto& stage : stages)
    {
        const auto& file = stage["file"].as<std::string>();
        const auto  type = stage["type"].as<int32_t>();

        auto shader_stage_source = File::read<std::byte>(path + file);

        ShaderStage  shader_stage { file, (uint32_t)(type == 0 ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER) };
        shader_stage.create();
        shader_stage.source(shader_stage_source);

        shader->attach(&shader_stage); // TODO keep a reference somewhere
    }

    shader->link();

    add_resource(shader);
    return       shader;
}

void ShaderContainer::unload()
{
}