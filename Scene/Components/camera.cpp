#include "camera.hpp"

Camera::Camera(float field_of_view, float z_near, float z_far)
    : _viewport      { }
    , _field_of_view { field_of_view }
    , _z_near { z_near }
    , _z_far  { z_far  }
{
}

const glm::mat4& Camera::projection() const
{
    return _projection;
}

void Camera::resize(float width, float height)
{
    float  aspect_ratio = width / height;
    assert(aspect_ratio > 0.0f);

    _projection = glm::perspective(glm::radians(_field_of_view), aspect_ratio, _z_near, _z_far);
    //_projection = glm::ortho(_data.data[0], _data.data[1], _data.data[2], _data.data[3]);

    _viewport.z = width;
    _viewport.w = height;
}

void Camera::field_of_view(float value)
{
    _field_of_view = value;
}

void Camera::z_near(float value)
{
    _z_near = value;
}

void Camera::z_far(float value)
{
    _z_far = value;
}

float Camera::field_of_view() const
{
    return _field_of_view;
}

ray Camera::screen_to_world(const glm::mat4& view, const vec2& position) const
{
    const float y   = _viewport.w - position.y;

    glm::vec3 start = glm::unProject({ position.x, y, 0.0f }, view, _projection, _viewport);
    glm::vec3 end   = glm::unProject({ position.x, y, 1.0f }, view, _projection, _viewport);

    glm::vec3 direction = glm::normalize(end - start);

    return { { start.x, start.y, start.z }, { direction.x, direction.y, direction.z } };
}
