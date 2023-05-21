#pragma once

#include "vec3.hpp"

class PhysicsShapes
{
public:
    PhysicsShapes() = delete;

    static btCollisionShape* create_box(const vec3& dimension);
};