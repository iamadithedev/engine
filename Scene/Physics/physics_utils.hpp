#pragma once

#include "vec3.hpp"

class PhysicsUtils
{
public:
    PhysicsUtils() = delete;

    static btTransform get_transform(const vec3& position);
    static btVector3     get_vector3(const vec3& vec);
};