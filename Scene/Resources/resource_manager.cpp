#include "resource_manager.hpp"

#include "containers/shader_container.hpp"

void ResourceManager::init()
{
    _containers[typeid(Shader).hash_code()] = new ShaderContainer();
}

void ResourceManager::release()
{
    // TODO release here the containers?
}
