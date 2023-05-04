#include "transform.hpp"

Transform::Transform()
    : _matrix { 1.0f }
{
}

Transform& Transform::translate(const vec3& position)
{
    _matrix = glm::translate(glm::mat4(1.0f), { position.x, position.y, position.z });
     return *this;
}

Transform& Transform::rotate(const vec3& axes, float angle)
{
    _matrix = glm::rotate(_matrix, angle, { axes.x, axes.y, axes.z });
     return *this;
}

Transform& Transform::scale(const vec3& axes)
{
    _matrix = glm::scale(_matrix, { axes.x, axes.y, axes.z });
     return *this;
}

const glm::mat4& Transform::matrix() const
{
    return _matrix;
}
