#include "camera.hpp"

void Camera::perspective(float fov, float ratio, float near, float far)
{
    _projection = glm::perspective(glm::radians(fov), ratio, near, far);
}

void Camera::ortho(float left, float right, float bottom, float top)
{
    _projection = glm::ortho(left, right, bottom, top);
}

const glm::mat4& Camera::projection() const
{
    return _projection;
}
