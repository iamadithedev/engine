#pragma once

#include "ray.hpp"
#include "physics_debug.hpp"

class Physics
{
public:
    Physics();

    void init();
    void release();
    void debug();

    btCollisionWorld::ClosestRayResultCallback cast(const ray& ray, float distance);

    void add_collision(int32_t index, btCollisionShape* shape, const vec3& position);

    PhysicsDebug* physics_debug() const;

private:
    btCollisionConfiguration* _config;

    btCollisionDispatcher* _dispatcher;
    btBroadphaseInterface* _broadphase;

    btCollisionWorld* _world;

    PhysicsDebug* _debug;
};
