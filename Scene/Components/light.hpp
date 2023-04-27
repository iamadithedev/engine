#pragma once

#include "vec3.hpp"
#include "rgb.hpp"

class Light
{
public:
    Light(const vec3& position, const rgb& color);

    void color(const rgb& color);

    [[nodiscard]] const rgb& color() const;

private:
    vec3  _position;
    float _temp;
    rgb   _color;
};