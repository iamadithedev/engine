#include "light.hpp"

Light::Light(const vec3 &position, const rgb& color)
    : _position { position }
    , _temp     { }
    , _color    { color }
{
}

void Light::position(const vec3& position)
{
    _position = position;
}

void Light::color(const rgb& color)
{
    _color = color;
}

const vec3& Light::position() const
{
    return _position;
}

const rgb& Light::color() const
{
    return _color;
}