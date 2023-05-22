#include "physics_utils.hpp"

btTransform PhysicsUtils::get_transform(const vec3& position)
{
    btTransform transform;

    transform.setIdentity();
    transform.setOrigin(get_vector3(position));

    return transform;
}

btVector3 PhysicsUtils::get_vector3(const vec3& vec)
{
    return { vec.x, vec.y, vec.z };
}
