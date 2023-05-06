#pragma once

#include "ray.hpp"

class Physics
{
public:
    Physics();

    void init();
    void release();

    void compute_debug_geometry();

    void add_collision(int32_t index, btCollisionShape* shape, const vec3& position);
    void add_debug(btIDebugDraw* debug);

    [[nodiscard]] btCollisionWorld::ClosestRayResultCallback cast(const ray& ray, float distance) const;

private:
    btCollisionConfiguration* _config;

    btCollisionDispatcher* _dispatcher;
    btBroadphaseInterface* _broadphase;

    btCollisionWorld* _world;
};
