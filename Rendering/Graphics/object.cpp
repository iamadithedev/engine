#include "object.hpp"

Object::Object()
    : _handle { }
{
}

uint32_t Object::handle() const
{
    return _handle;
}
