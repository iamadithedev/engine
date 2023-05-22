#include "physics_world.hpp"
#include "physics_utils.hpp"

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

RayResult PhysicsWorld::cast(const ray& ray, float distance) const
{
    RayResult result;

    btVector3 origin    = PhysicsUtils::get_vector3(ray.origin);
    btVector3 direction = PhysicsUtils::get_vector3(ray.direction);

    btVector3 target = origin + direction * distance;
    btCollisionWorld::ClosestRayResultCallback hit { origin, target };

    _world->rayTest(origin, target, hit);

    if (hit.hasHit())
    {
        result.set_index(hit.m_collisionObject->getUserIndex());
    }

    return result;
}

void PhysicsWorld::add_collision(int32_t index, btCollisionShape* shape, const vec3& position)
{
    auto object = new btCollisionObject(); // TODO use a pool for this?

    object->setCollisionShape(shape);
    object->setWorldTransform(PhysicsUtils::get_transform(position));
    object->setUserIndex(index);

    _world->addCollisionObject(object);
}

void PhysicsWorld::add_debug(btIDebugDraw* debug)
{
    _world->setDebugDrawer(debug);
}

void PhysicsWorld::compute_debug_geometry() const
{
    _world->debugDrawWorld();
    _world->getDebugDrawer()->flushLines(); // TODO just for collision world
}