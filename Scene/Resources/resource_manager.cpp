#include "resource_manager.hpp"

#include "containers/shader_container.hpp"

void ResourceManager::init(const std::string& path)
{
    _path = path; // TODO in constructor?

    _containers[typeid(Shader).hash_code()] = new ShaderContainer();
}

void ResourceManager::release()
{
    // TODO release here the containers?
}
