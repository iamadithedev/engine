#include "physics_shapes.hpp"

btCollisionShape* PhysicsShapes::create_box(const vec3& dimension)
{
    return new btBoxShape({ dimension.x, dimension.y, dimension.z });
}
