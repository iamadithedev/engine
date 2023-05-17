#pragma once

#include "object.hpp"

class Container
{
public:
    virtual Object* load(const std::string& file) = 0;
    virtual void  unload() = 0;
};