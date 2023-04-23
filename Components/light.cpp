#include "light.hpp"

Light::Light(const vec3 &position, const rgb& color)
    : _position { position }
    , _color    { color }
{
}

void Light::color(const rgb& color)
{
    _color = color;
}
