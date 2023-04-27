#include "physics_debug.hpp"

PhysicsDebug::PhysicsDebug()
    : _index { }
{
}

void PhysicsDebug::drawLine(const btVector3& a, const btVector3& b, const btVector3& color)
{
    rgb rgb { color.x(), color.y(), color.z() };

    _geometry.add_vertex({{ a.x(), a.y(), a.z() }, rgb });
    _geometry.add_vertex({{ b.x(), b.y(), b.z() }, rgb });

    _geometry.add_line(_index++, _index++);
}

int32_t PhysicsDebug::getDebugMode() const
{
    return btIDebugDraw::DBG_DrawWireframe;
}

void PhysicsDebug::flushLines()
{
}

void PhysicsDebug::clearLines()
{
    _geometry.reset();

    _index = 0;
}

const MeshGeometry<vertex::debug>& PhysicsDebug::geometry() const
{
    return _geometry;
}
