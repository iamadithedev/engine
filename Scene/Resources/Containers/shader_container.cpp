#include "shader_container.hpp"

#include "file.hpp"

void ShaderContainer::init()
{
    _types = { GL_VERTEX_SHADER, GL_FRAGMENT_SHADER };
    _hash  =   typeid(Shader).hash_code();
}

Shader* ShaderContainer::load(const std::string& file, const std::string& path)
{
    const auto& root_node   = YAML::LoadFile(path + file);
    const auto& stages_node = root_node["stages"];

    auto   binary_value = root_node["binary"].as<bool>();
    auto   type_value   = root_node["type"].as<std::size_t>();
    assert(type_value == _hash);

    auto shader = new Shader(); // TODO here from a pool? is container a pool?
         shader->create();

    for (const auto& stage_node : stages_node)
    {
        const auto& file_value = stage_node["file"].as<std::string>();
                    type_value = stage_node["type"].as<int32_t>();

        std::string filepath = path + file_value;

        ShaderStage shader_stage { file_value, _types[type_value] };
        shader_stage.create();

        binary_value ? shader_stage.source(File::read<std::byte>(filepath))
                     : shader_stage.source(File::read<char>(filepath));;

        shader->attach(&shader_stage); // TODO keep a reference somewhere
    }

    shader->link();

    add_resource(shader);
        return   shader;
}

void ShaderContainer::unload()
{
}
