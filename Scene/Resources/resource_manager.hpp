#pragma once

#include "resource_container.hpp"

class ResourceManager
{
public:
    void init(const std::string& path);
    void release();

    template   <typename Resource>
    Resource* load(const std::string& file)
    {
        auto   container = _containers.at(typeid(Resource).hash_code());
        auto   resource  = (Resource*)container->load(file, _path);
        return resource;
    }

private:
    std::map<std::size_t, Container*> _containers;
    std::string  _path;
};

