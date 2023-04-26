#pragma once

#include "mesh_geometry.hpp"

class PhysicsDebug final : public btIDebugDraw
{
public:
    void flushLines() final;

    [[nodiscard]] const MeshGeometry<vertex::debug>& geometry() const;

private:
    void clearLines() final;

    void drawLine(const btVector3 &a, const btVector3 &b, const btVector3 &color) final;
    void drawContactPoint(const btVector3&, const btVector3&, btScalar, int, const btVector3&) final { }

    void reportErrorWarning(const char*) final { }
    void draw3dText(const btVector3&, const char*) final { }
    void setDebugMode(int) final { }

    int  getDebugMode() const final;

    MeshGeometry<vertex::debug> _geometry;
    int32_t                     _index;
};