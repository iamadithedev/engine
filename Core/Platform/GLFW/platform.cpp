#include "platform.hpp"

namespace glfw
{
    bool Platform::init() const
    {
        if (glfwInit() == GLFW_FALSE)
        {
            return false;
        }

        glfwWindowHint(GLFW_SAMPLES, 4);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // TODO remove this, should be enable by default

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

    bool Platform::init_context()
    {
        return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }
}