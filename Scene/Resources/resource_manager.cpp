#include "resource_manager.hpp"

#include "containers/shader_container.hpp"

void ResourceManager::init(const std::string& path)
{
    _path = path; // TODO in constructor?

    auto shader_container = new ShaderContainer();
         shader_container->init();

    _containers[typeid(Shader).hash_code()] = shader_container;
}

void ResourceManager::release()
{
    // TODO release here the containers?
}
