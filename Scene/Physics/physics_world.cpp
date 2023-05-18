#include "physics_world.hpp"

PhysicsWorld::PhysicsWorld()
    : _config     { }
    , _dispatcher { }
    , _broadphase { }
    , _world { }
{
}

void PhysicsWorld::init()
{
    _config = new btDefaultCollisionConfiguration();

    _dispatcher = new btCollisionDispatcher { _config };
    _broadphase = new btDbvtBroadphase();

    _world = new btCollisionWorld { _dispatcher, _broadphase, _config };
}

void PhysicsWorld::release()
{
    delete _world;
    delete _broadphase;
    delete _dispatcher;
    delete _config;
}

btCollisionWorld::ClosestRayResultCallback PhysicsWorld::cast(const ray& ray, float distance) const
{
    btVector3 origin    { ray.origin.x,    ray.origin.y,    ray.origin.z };
    btVector3 direction { ray.direction.x, ray.direction.y, ray.direction.z };

    btVector3 target = origin + direction * distance;
    btCollisionWorld::ClosestRayResultCallback hit { origin, target };

    _world->rayTest(origin, target, hit);

    return hit;
}

void PhysicsWorld::add_collision(int32_t index, btCollisionShape* shape, const vec3& position)
{
    btTransform transform;
    transform.setIdentity();
    transform.setOrigin({ position.x, position.y, position.z });

    auto object = new btCollisionObject(); // TODO use a pool for this?

    object->setCollisionShape(shape);
    object->setWorldTransform(transform);
    object->setUserIndex(index);

    _world->addCollisionObject(object);
}

void PhysicsWorld::add_debug(btIDebugDraw* debug)
{
    _world->setDebugDrawer(debug);
}

void PhysicsWorld::compute_debug_geometry()
{
    _world->debugDrawWorld();
    _world->getDebugDrawer()->flushLines(); // just for collision world
}