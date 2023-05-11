#pragma once

#include "vec3.hpp"
#include "component.hpp"

class Transform final : public Component
{
public:
    Transform();

    Transform& translate(const vec3& position);
    Transform& rotate(const vec3& axes, float angle);
    Transform& scale(const vec3& axes);

    [[nodiscard]] const glm::mat4& matrix() const;

private:
    glm::mat4 _matrix;
};