#pragma once

#include "containers/container.hpp"

template <typename Resource>
class ResourceContainer : public Container
{
public:
    const Resource* get_at_index(uint32_t index)
    {
        return _resources[index];
    }

protected:
    void add_resource(Resource* resource)
    {
         assert(resource != nullptr);
        _resources.push_back(resource);
    }

private:
    std::vector<Resource*> _resources;
};
