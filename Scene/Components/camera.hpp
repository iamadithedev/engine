#pragma once

class Camera
{
public:
    Camera(float field_of_view, float aspect_ratio, float near_plane = 0.1f, float far_plane = 100.0f);

    void resize(float width, float height);

    void field_of_view(float value);
    void near_plane(float value);
    void far_plane(float value);

    [[nodiscard]] const glm::mat4& projection() const;

    [[nodiscard]] float field_of_view() const;

private:
    glm::mat4 _projection;

    float _field_of_view;
    float _aspect_ratio;
    float _near_plane;
    float _far_plane;
};