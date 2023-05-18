#pragma once

#include "object.hpp"

class Container
{
public:
    virtual Object* load(const std::string& filename, const std::string& path) = 0;
    virtual void  unload() = 0;
};