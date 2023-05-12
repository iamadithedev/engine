#pragma once

#include "base/object.hpp"

class Object : public base::Object<uint32_t>
{
public:
    virtual void create()  = 0;
    virtual void destroy() = 0;
};