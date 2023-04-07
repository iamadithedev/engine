#include "platform.hpp"

Platform::Platform(int32_t major, int32_t minor, int32_t samples)
    : _major   { major }
    , _minor   { minor }
    , _samples { samples }
{
}

bool Platform::init() const
{
    if (glfwInit() == GLFW_FALSE)
    {
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, _samples);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _minor);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return true;
}

void Platform::update() const
{
    glfwPollEvents();
}

void Platform::release() const
{
    glfwTerminate();
}

void Platform::vsync() const
{
    glfwSwapInterval(1);
}
