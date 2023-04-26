#pragma once

#include "vec3.hpp"
#include "vec2.hpp"

namespace vertex
{
    struct diffuse
    {
        vec3 position;
        vec3 normal;
    };

    struct texture
    {
        vec2 position;
        vec2 uv;
    };
}