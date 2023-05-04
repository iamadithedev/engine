#pragma once

#include "ray.hpp"
#include "vec2.hpp"

class Camera
{
public:
    explicit Camera(float field_of_view, float z_near = 0.1f, float z_far = 100.0f);

    void resize(float width, float height);

    void field_of_view(float value);
    void z_near(float value);
    void z_far(float value);

    [[nodiscard]] const glm::mat4& projection() const;
    [[nodiscard]] float         field_of_view() const;

    [[nodiscard]] ray screen_to_world(const glm::mat4& view, const vec2& position) const;

private:
    glm::mat4 _projection;
    glm::vec4 _viewport;

    float _field_of_view;
    float _z_near;
    float _z_far;
};