#include "camera.hpp"

void Camera::perspective(float fov, float ratio, float near, float far)
{
    _projection = glm::perspective(glm::radians(fov), ratio, near, far);
}

const glm::mat4& Camera::projection() const
{
    return _projection;
}
