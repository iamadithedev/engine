#pragma once

class Camera
{
public:
    void perspective(float fov, float ratio, float near = 0.1f, float far = 100.0f);
    void ortho(float left, float right, float bottom, float top);

    [[nodiscard]] const glm::mat4& projection() const;

private:
    glm::mat4 _projection;
};