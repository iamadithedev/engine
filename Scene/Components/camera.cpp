#include "camera.hpp"

Camera::Camera(float field_of_view, float aspect_ratio, float near_plane, float far_plane)
    : _field_of_view { field_of_view }
    , _aspect_ratio  { aspect_ratio  }
    , _near_plane    { near_plane }
    , _far_plane     { far_plane  }
{
}

const glm::mat4& Camera::projection() const
{
    return _projection;
}

void Camera::resize(float width, float height)
{
           _aspect_ratio = width / height;
    assert(_aspect_ratio > 0.0f);

    _projection = glm::perspective(glm::radians(_field_of_view), _aspect_ratio, _near_plane, _far_plane);
    //_projection = glm::ortho(_data.data[0], _data.data[1], _data.data[2], _data.data[3]);
}

void Camera::field_of_view(float value)
{
    _field_of_view = value;
}

void Camera::near_plane(float value)
{
    _near_plane = value;
}

void Camera::far_plane(float value)
{
    _far_plane = value;
}

float Camera::field_of_view() const
{
    return _field_of_view;
}
