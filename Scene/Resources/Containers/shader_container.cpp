#include "shader_container.hpp"

#include "file.hpp"

void ShaderContainer::init()
{
    _types = { GL_VERTEX_SHADER, GL_FRAGMENT_SHADER };
}

Shader* ShaderContainer::load(const std::string& file, const std::string& path)
{
    const auto& root_node   = YAML::LoadFile(path + file);
    const auto& stages_node = root_node["stages"];

    auto shader = new Shader();
    shader->create();

    for (const auto& stage_node : stages_node)
    {
        const auto& file_value = stage_node["file"].as<std::string>();
        const auto  type_value = stage_node["type"].as<int32_t>();

        auto shader_stage_source = File::read<std::byte>(path + file_value);

        ShaderStage  shader_stage { file_value, _types[type_value] };
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
