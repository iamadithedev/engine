#pragma once

#include "vec3.hpp"
#include "rgb.hpp"

class Light
{
public:
    Light(const vec3& position, const rgb& color);

    void color(const rgb& color);

private:
    vec3  _position;
    float _temp;
    rgb   _color;
};