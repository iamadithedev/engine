#include "physics.hpp"

Physics::Physics()
    : _config     { }
    , _dispatcher { }
    , _broadphase { }
    , _world { }
    , _debug { }
{
}

void Physics::init()
{
    _config = new btDefaultCollisionConfiguration();

    _dispatcher = new btCollisionDispatcher { _config };
    _broadphase = new btDbvtBroadphase();

    _world = new btCollisionWorld { _dispatcher, _broadphase, _config };

    _debug = new PhysicsDebug();
    _world->setDebugDrawer(_debug);
}

void Physics::release()
{
    delete _debug;

    delete _world;
    delete _broadphase;
    delete _dispatcher;
    delete _config;
}

btCollisionWorld::ClosestRayResultCallback Physics::cast(const ray&ray, float distance)
{
    btVector3 origin    { ray.origin.x, ray.origin.y, ray.origin.z };
    btVector3 direction { ray.direction.x, ray.direction.y, ray.direction.z };

    btVector3 target = origin + direction * distance;

    btCollisionWorld::ClosestRayResultCallback hit { origin, target };
    _world->rayTest(origin, target, hit);

    return hit;
}

void Physics::add_collision(int32_t index, btCollisionShape* shape, const vec3& position)
{
    btTransform transform;
    transform.setIdentity();
    transform.setOrigin({ position.x, position.y, position.z });

    auto collision = new btCollisionObject();

    collision->setCollisionShape(shape);
    collision->setWorldTransform(transform);
    collision->setUserIndex(index);

    _world->addCollisionObject(collision);
}

void Physics::debug()
{
    _world->debugDrawWorld();
    _debug->flushLines(); // just for collision world
}

PhysicsDebug* Physics::physics_debug() const
{
    return _debug;
}
