#pragma once

#include "vec3.hpp"
#include "vec2.hpp"
#include "rgb.hpp"

namespace vertex
{
    struct debug
    {
        vec3 position;
        rgb  color;
    };

    struct diffuse
    {
        vec3 position;
        vec3 normal;
    };

    struct sprite
    {
        vec2 position;
        vec2 uv;
    };
}